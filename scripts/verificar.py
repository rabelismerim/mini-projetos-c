"""Check real program results; optionally render terminal transcripts as PNG."""
import argparse
import os
from pathlib import Path
import subprocess
import tempfile
import textwrap

ROOT = Path(__file__).resolve().parents[1]
BIN = ROOT / 'build' / 'bin'

def run(name, data='', cwd=None, code=0):
    binary = BIN / (name + ('.exe' if os.name == 'nt' else ''))
    result = subprocess.run([str(binary)], input=data, text=True,
                            capture_output=True, cwd=cwd, timeout=5)
    assert result.returncode == code, (name, result.stdout, result.stderr)
    return result.stdout + result.stderr

def capture(name, data, output):
    from PIL import Image, ImageDraw, ImageFont
    fonts = [Path('C:/Windows/Fonts/consola.ttf'),
             Path('/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf')]
    font_path = next((path for path in fonts if path.exists()), None)
    font = ImageFont.truetype(str(font_path), 19) if font_path else ImageFont.load_default(size=19)
    # Exact stdout; wrap long lines without changing their contents.
    lines = ['ENTRADAS (uma por linha):', data.strip().replace('\n', ' | ') or '(sem entrada)', '', 'SAIDA REAL:']
    lines.extend(output.splitlines())
    wrapped = [part for line in lines for part in (textwrap.wrap(line, width=88, replace_whitespace=False) or [''])]
    if len(wrapped) > 40:
        wrapped = wrapped[:18] + ['[...] trecho intermediario omitido na captura [...]'] + wrapped[-18:]
    width, height = 1120, 112 + 27 * len(wrapped)
    image = Image.new('RGB', (width, height), '#0c1220')
    draw = ImageDraw.Draw(image)
    draw.rounded_rectangle((16, 16, width - 16, height - 16), radius=14, fill='#141e30')
    for index, color in enumerate(['#ff6370', '#f6c85f', '#52d6a0']):
        draw.ellipse((36 + index * 25, 34, 49 + index * 25, 47), fill=color)
    draw.text((135, 28), 'MINI PROJETOS EM C / ' + name, font=font, fill='#8ed8ff')
    for index, line in enumerate(wrapped):
        draw.text((36, 80 + 27 * index), line, font=font,
                  fill='#52d6a0' if line.endswith(':') else '#e2e8f0')
    target = ROOT / 'docs' / 'capturas' / (name + '.png')
    target.parent.mkdir(parents=True, exist_ok=True)
    image.save(target)
    target.with_suffix('.txt').write_text('ENTRADAS:\n' + data + '\nSAIDA:\n' + output, encoding='utf-8')

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--capturas', action='store_true')
    args = parser.parse_args()
    prices = '\n'.join(['Loja ' + str(i) for i in range(1, 9)] +
                       ['Teclado', 'Mouse', 'Monitor', 'Headset'] + ['99', '110'] + ['150'] * 30) + '\n'
    cases = {
        'idade': ('2000\n', 'anos.'),
        'media_aluno': ('8\n7\n9\n', 'Media: 8.00\nSituacao: Aprovado'),
        'porcentagem_turma': ('12\n18\n', 'Mulheres: 60.00%'),
        'media_numeros': ('10\n20\n30\n9999\n', 'Media: 20.00'),
        'contagem_crescente': ('', '491 492 493 494 495 496 497 498 499 500'),
        'contagem_decrescente': ('', '10 9 8 7 6 5 4 3 2 1'),
        'audiencia_tv': ('4\n10\n5\n20\n7\n5\n12\n5\n0\n', '50.00% (20 pessoas)'),
        'busca_binaria': ('5\n2\n4\n6\n8\n10\n8\n', 'posicao 4 (indice 3)'),
        'comparador_precos': (prices, 'R$ 99.00'),
        'pilha': ('1\n10\n1\n20\n3\n2\n4\n5\n3\n6\n', 'Topo: 20'),
        'fila_circular': ('1\n10\n1\n20\n2\n1\n30\n3\n4\n6\n', 'Elementos (2/10): 20 30'),
        'segmento_binario': ('', '10 11 12 13 14 15 16 17 18 19'),
        'cadastro_vendas': ('1\n2\nMouse\n10\n1\n1\nTeclado\n5\n3\n2\n5\n', 'Produtos: 2 | Unidades: 15'),
    }
    with tempfile.TemporaryDirectory() as directory:
        for name, (data, expected) in cases.items():
            output = run(name, data, directory)
            assert expected in output, (name, output)
            if args.capturas:
                capture(name, data, output)
            print('OK:', name)
        assert 'Mouse | 10' in run('cadastro_vendas', '2\n5\n', directory)
        assert 'Codigo ja cadastrado' in run('cadastro_vendas', '1\n2\n5\n', directory)
        file = Path(directory) / 'vendas.csv'
        file.write_text('arquivo corrompido\n', encoding='utf-8')
        assert 'invalido' in run('cadastro_vendas', cwd=directory, code=1)
        assert file.read_text() == 'arquivo corrompido\n'
        assert 'vazia' in run('porcentagem_turma', '0\n0\n', directory)
        assert 'Nenhum numero' in run('media_numeros', '9999\n', directory)
        assert 'Nenhum espectador' in run('audiencia_tv', '0\n', directory)
        assert 'nao pesquisado' in run('audiencia_tv', '3\n0\n', directory)
        assert 'nao encontrado' in run('busca_binaria', '2\n1\n3\n2\n', directory)
        for notes, status in [('7\n7\n7\n', 'Aprovado'), ('5\n5\n5\n', 'Recuperacao'), ('4\n4\n4\n', 'Reprovado')]:
            assert status in run('media_aluno', notes, directory)
        assert 'Entrada invalida' in run('media_aluno', 'abc\nnan\n11\n8\n7\n9\n', directory)
        for name in ['pilha', 'fila_circular']:
            data = ''.join('1\n' + str(i) + '\n' for i in range(10))
            output = run(name, data + '1\n2\n1\n99\n4\n5\n2\n6\n', directory)
            assert 'Estrutura cheia' in output and 'Estrutura vazia' in output
            expected = '1 2 3 4 5 6 7 8 9 99' if name == 'fila_circular' else '99 8 7 6 5 4 3 2 1 0'
            assert expected in output
        for name in cases:
            run(name, '', directory, code=1 if name == 'cadastro_vendas' else 0)
        asc = run('contagem_crescente').split('\n', 1)[1].split()
        desc = run('contagem_decrescente').split('\n', 1)[1].split()
        assert list(map(int, asc)) == list(range(1, 501))
        assert list(map(int, desc)) == list(range(1500, 0, -1))
    print('OK: limites, entradas invalidas, FIFO/LIFO, persistencia e EOF')

if __name__ == '__main__':
    main()
