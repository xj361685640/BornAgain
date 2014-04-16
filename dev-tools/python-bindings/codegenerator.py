#!/usr/bin/env python

def help_short():
    print('Usage: codegenerator.py make|install|clean|help')

def help_long():
    print('''
C++ wrapper generator for exposing C++ libraries to Python.
''')
    help_short()
    print( '''
Options:
   make:    generate python boost wrapping code in ./output subdirectory
   install: install generated code to BornAgain/PythonAPI
   clean:   clean local directory
   help:    this help

Dependencies:
   - boost-python
   - Python2.7
   - gccxml (deb: libgccxml-dev; rpm: gccxml-devel)
   - pygccxml (https://bitbucket.org/ompl/pygccxml)
   - Py++ (https://bitbucket.org/ompl/pyplusplus)
''')


import sys
import os

import builder_utils
import MakePyCore
import MakePyFit
import InstallPyCore
import InstallPyFit


def main():
    if len(sys.argv)!=2:
        help_short()
        exit()

    if sys.argv[1] == 'make':
        builder_utils.MakePythonAPI(
            MakePyCore, "PythonCoreList.h", "cache_core.xml",
            specialFlags="-DBORNAGAIN_PYTHON" )
        builder_utils.MakePythonAPI(
            MakePyFit, "PythonFitList.h", "cache_fit.xml",
            withPureVirtual=False)
    elif sys.argv[1] == 'install':
        InstallPyCore.InstallCode(MakePyCore)
        InstallPyFit.InstallCode (MakePyFit)
    elif sys.argv[1] == 'clean':
        clean = ["output", "cache_*.xml", "*~", "named_tuple.py", "*.pyc",
                 "exposed_decl.pypp.txt", "tmp.pypp.cpp"]
        for x in clean: os.system("rm -rf "+x)
    elif sys.argv[1] == 'help':
        help_long()
    else:
        help_short()


if __name__ == '__main__':
    main()
