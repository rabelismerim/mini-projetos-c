"""Build all standalone programs with GCC/Clang or MSVC (Developer Prompt)."""
import argparse
import os
from pathlib import Path
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[1]

def build(compiler=None):
    compiler = compiler or os.environ.get('CC') or next(
        (name for name in ('gcc', 'clang', 'cl') if shutil.which(name)), None)
    if not compiler:
        raise SystemExit('Instale GCC/Clang ou abra o Developer Command Prompt do Visual Studio.')
    output = ROOT / 'build' / 'bin'
    output.mkdir(parents=True, exist_ok=True)
    msvc = Path(compiler).stem.lower() == 'cl'
    for source in sorted((ROOT / 'projetos').rglob('main.c')):
        name = source.parent.name
        binary = output / (name + ('.exe' if os.name == 'nt' else ''))
        if msvc:
            command = [compiler, '/nologo', '/std:c17', '/W4', '/WX', '/utf-8',
                       '/D_CRT_SECURE_NO_WARNINGS', '/I' + str(ROOT / 'include'),
                       str(source), '/Fe:' + str(binary), '/Fo:' + str(output / (name + '.obj'))]
        else:
            command = [compiler, '-std=c17', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                       '-I', str(ROOT / 'include'), str(source), '-o', str(binary)]
        subprocess.run(command, cwd=output, check=True)
        print('OK:', name, flush=True)
    return output

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--cc', help='Compilador ou caminho do executavel')
    build(parser.parse_args().cc)
