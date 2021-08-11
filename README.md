# Cipher

- A program that let user to encode or decode their messages,
- User can choose between 3 different ciphers such as caesar, vigenere, and substitution.
- User can also choose either append ther messages to the file or just print out in their terminal.

## About clonning

- You can clone a repository from GitHub to your local computer to make it easier to fix merge conflicts, add or remove files, and push larger commits. 
- When you clone a repository, you copy the repository from GitHub to your local machine.
- Cloning a repository pulls down a full copy of all the repository data that GitHub has at that point in time, including all versions of every file and folder for the project. 
- You can push your changes to the remote repository on GitHub, or pull other people's changes from GitHub. For more information, see "Using Git".
- You can clone your existing repository or clone another person's existing repository to contribute to a project.

## To clone 

- Open Terminal.
- Change the current working directory to the location where you want the cloned directory.

```
$ git clone https://github.com/jenlcmc/cipher.git
```

- Press Enter to create your local clone.
- It shoud kind of look like under example except the https is different

```
$ git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY
> Cloning into `Spoon-Knife`...
> remote: Counting objects: 10, done.
> remote: Compressing objects: 100% (8/8), done.
> remove: Total 10 (delta 1), reused 10 (delta 1)
> Unpacking objects: 100% (10/10), done.
```

## Requirements 

- gcc compiler
- C++ 11 and above

To run: 

From Terminal(Unix/Linux):
    
    make

Should produce a main file if not already in folder:

    ./main

**To remove .o and main file after use:**
```
    make clean
```
## Remove VSCode folders

.vscode folders are used for running and debugging within the VS Code text editor

.vscode folder may be hidden in Unix like systems but visible on Windows OS to find remove from terminal/powershell:

    ls -la //.vscode folder should be visible
   
    rm -rf .vscode

## Known Issues

_issues with using {} initialization on OSX compilers that does not use GDB_

_untested with MSVC compilers_

## Upcoming Features
- Read file and decode or encode
- Add XOR cipher 
