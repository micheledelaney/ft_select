# ft_select
File browser written in C that uses the termcaps library to pick files and returns them to the command line

## Demo
![demo_gif]()

## Installation  
### Requirements  
* A Unix system
* GNU make (v3.81)
* GCC (v4.2.1)

For Linux distros you need to install the termcaps library:  
for Ubuntu and other distros that use apt:  
`sudo apt-get install libncurses5-dev`  

For Arch:  
`pacman -S ncurses`  

### Building  
Clone the repo and run the make command:  
`git clone URL`  
`cd ft_select`  
`make`  

## Run  
`./ft_select ~/*`  
- you can navigate with up/down/right/left the arrow keys
- hit the space key to select a file
- to unselect a file just hit space again
- to return with the selected files hit return
- to dischard and leave hit ESC
- the 'r' key resets all the selected files

## Features

* If you pass a list of arguments to the program it gets displayed in your terminal.
* You can move through the list using arrows.
* One or more choices can be selected or un-selected with the `space` key. With
each selection, the cursor will automatically position itself on the next element.
* You can validate the selection with the `return` key, the list of choices will
be sent back to the shell. This allows other programs to use the output of the program as their input. i.e: rm `./ft_select file1 file2 file3`
* Re-organizes the display on window resize or displays a blank screen if the list cannot fit the in window.
* Exits on `ESC` key
* Pressing the `delete` or `backspace` keys removes an element from the list. In Real mode (Read below), it will automatically delete the active element from the system if it's a valid file/folder. So watch out!
* Press `*` to select all and `-` to unselect all.
* Colored output based on some supported file extensions.
* Pressing the keys `O` and `B` opens a valid folder and goes back to the parent root directory respectively.
* Handles interruption signals gracefully (ctrl + z, ctrl + c, kill, etc...)
* Restores the screen to what it was before clearing it.
* No memory leaks
* Whole codebase is commented for easier browsing.

### Real mode

You can launch the program in real mode. In real mode, when you press `delete`/`backspace` on a valid file or folder, it will be deleted on the system too. So again, watch out! I'm not responsible for any loss of your files.


To run ft_select in real mode, use the flag `-r` or `--real`

	./ft_select -r I love 42



