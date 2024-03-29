# T-Write++ Terminal-Based Text Editor

**Version 1.1.0 now out with new cursor system.**

T-Write++ is a terminal-based text editor written in C++. It has many different features, and boasts a very user-friendly intuitive syntax/user interface, very reminiscent of the command-line Python and Lua, as well as the Pico-8 fantasy console. 

It can be used for general-purpose text editing, note-taking, and even basic programming!

<img width="530" alt="image" src="https://github.com/omrawaley/T-Write-Plus-Plus-Terminal-Based-Text-Editor/assets/133281331/4c65b432-6767-4d07-bd54-df042a4e8a71">

(The program shown above—source and executable—is available in the `DemoProgram` folder)


## Features:

T-Write++ includes a few basic features:

- Reading a file
- Editing a file
- Creating a new file
- Deleting a file

There is even a cursor system that allows you to append and remove text from anywhere you want, unlike other terminal-based text editors! The cursor can be moved left with `CTRL + J` and right with `CTRL + L`.

<img width="530" alt="image" src="https://github.com/omrawaley/T-Write-Plus-Plus-Terminal-Based-Text-Editor/assets/133281331/a5bd08c7-36fb-489f-8e49-6314da091954">

Using the command `help` in the T-Write++ menu will display a list of possible actions.

<img width="300" alt="image" src="https://github.com/omrawaley/T-Write-Plus-Plus-Terminal-Based-Text-Editor/assets/133281331/9268b59c-68ca-4d2a-aac9-7ab5d631deb9">

It has a menu system quite reminiscent of the command-line Python (`python` or `python3`) and Lua (`lua`), as well as the PICO-8 and TIC-80 fantasy consoles.

## To Use:

T-Write++ uses Unix-specific system commands which are only available on MacOS and Linux. A Dockerfile is included that can create a Linux virtual machine and enable you to run the application on Windows.

### MacOS/Linux:

Run the Makefile:
`make -B`

Run the program:
`./program`

### Windows:

Build the Docker image: `docker build . -t twrite`

Run the image: `docker run -it twrite`
(Note: the program will immediately quit if you omit the `it` flag)
