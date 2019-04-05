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
- hit the `space` key to select a file
- to unselect a file just hit `space` again
- to return with the selected files hit the `return` key
- to dischard and leave hit `Esc`
- the 'r' key resets all the selected files
- the screen doesn't display the files when not all the files can be displayed at once.
- the `delete` or `backspace` keys remove an element from the list
- in real mode with `delete` and `backspace` the files get deleted from the system it it is a valid file

### Real mode
You can launch the program in real mode. In real mode, when you press `delete`/`backspace` on a valid file or folder, it will be deleted on the system too. So again, watch out! I'm not responsible for any loss of your files.
