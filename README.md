# Cipher

## Requirements 

- gcc compiler
- C++ 11 and above

To run: 

From Terminal(Unix/Linux):
    
    make

Should produce a main file if not already in folder:

    ./main

## Remove VSCode folders

.vscode folders are used for running and debugging within the VS Code text editor

.vscode folder may be hidden in Unix like systems but visible on Windows OS to find remove from terminal/powershell:

    ls -la //.vscode folder should be visible
   
    rm -rf .vscode

## Known Issues

_issues with using {} initialization on OSX compilers that does not use GDB_

_untested with MSVC compilers_
