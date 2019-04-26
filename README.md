# ft_select
File browser written in C that uses the termcaps library to pick files and returns them to the command line

## Demo
![demo_gif](https://github.com/cmicheledelaney/ft_select/blob/master/demo_ft_select.gif)  

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

## Features    
- you can navigate with up/down/right/left `arrow` keys
- hit the `space` key to select a file
- to unselect a file just hit `space` again
- to return with the selected files hit the `return` key
- to dischard and leave hit `Esc`
- the `r` key resets all the selected files
- the screen doesn't display the files when not all the files can be displayed at once.
- the `delete` or `backspace` keys remove an element from the list
- in real mode with `delete` and `backspace` the files get deleted from disk if they are valid files

### Run
`./ft_select ~/*`  
If you want to return the chosen files to the shell, for example to cat them, run it like this:  
`cat $(./ft_select ~/*)`  

### Real mode
The application can get launched in real mode with the flags `-r` and `--real`. When in real mode files that get deleted from the list get also deleted from the system.
`./ft_select --real ~/*`
