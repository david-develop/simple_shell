# Readme simple_shell 📚

------------

Custom implementation of the application `shell` as a project for Holberton School. In this project we apply the knowledge that we have gotten  in C programming language.

------------

### Description  📚
**simple_shell** is the customized version of the command interpreter for linux systems. Being a basic version of sh, we can perfom some specific functions to work on terminal.

The simple_shell reads lines from terminal, interprets them, and generally executes other commands. In case of a missing information or a mistake, the program will show to the user the kind of error.

------------
### Installation ⚙
To compile the program is necessary to add all the `*.c` involved in the program (functions, main files, etc). For that reason to compile type:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

To execute the program in interactive mode type:

`./hsh`

### How it works

In interactive mode type the command and then press enter ↵

	mini-shell--$ ls
	Programacion  boot   dev  home	      initrd.img.old  lib32  libx32	 media	opt   root  sbin  srv  tmp  var      vmlinuz.old
	bin	      cdrom  etc  initrd.img  lib	      lib64  lost+found  mnt	proc  run   snap  sys  usr  vmlinuz

Or type for non-interactive mode:

	echo "ls" | ./hsh

------------

### Builtins functions:
#### Exit:
Cause normal process termination, the status must be transmitted to the parent process. If the status is not defined by user its value is 0.
##### Example of use:
Regular case:

	mini-shell--$ exit
	/simple_shell$ echo $?
	0

Using status:

	mini-shell--$ exit 48
	/simple_shell$ echo $?
	48

#### env:
Prints enviromental variables.
##### Example of use:

	mini-shell--$ env
	CLUTTER_IM_MODULE=xim
	LESSCLOSE=/usr/bin/lesspipe %s %s
	XDG_MENU_PREFIX=gnome-
	LANG=es_CO.UTF-8
	DISPLAY=:0
	GNOME_SHELL_SESSION_MODE=ubuntu-communitheme
	COLORTERM=truecolor
	DESKTOP_AUTOSTART_ID=109860eec2b0d5f55e15668754515697900000017440007
	USERNAME=carl
	XDG_VTNR=2
	SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
	XDG_SESSION_ID=2
	USER=carl
	DESKTOP_SESSION=ubuntu-communitheme
	...
#### setenv:
Creates or modifies environmental variables.
##### Example of use:
	mini-shell--$ setenv VARIABLE 1000
	mini-shell--$ env
	OLDPWD=/home
	_=./ssshell
	VARIABLE=1000

#### unsetenv:
Deletes environmental variables.
##### Example of use:
	mini-shell--$ unsetenv VARIABLE
	mini-shell--$ env
	OLDPWD=/home
	_=./ssshell

#### cd:
Changes the current directory of the process.
##### Example of use:
	mini-shell--$ cd /usr
	mini-shell--$ ls
	bin  games  include  lib  lib32  libexec  libx32  local  sbin  share  src
	mini-shell--$ cd /
	mini-shell--$ ls
	Programacion  boot   dev  home	      initrd.img.old  lib32  libx32	 media	opt   	root  sbin  srv  tmp  var      vmlinuz.old
	bin	      cdrom  etc  initrd.img  lib	      lib64  lost+found  mnt	proc  run   snap  sys  usr  vmlinuz
	mini-shell--$ cd boot
	mini-shell--$ ls
	System.map-4.15.0-55-generic  config-4.15.0-58-generic	initrd.img-4.15.0-55-generic  memtest86+.elf		 vmlinuz-4.15.0-58-generic
	System.map-4.15.0-58-generic  efi			initrd.img-4.15.0-58-generic  memtest86+_multiboot.bin
	config-4.15.0-55-generic      grub			memtest86+.bin		      vmlinuz-4.15.0-55-generic




------------
### Files Description
| File  |Description   |
| ------------ | ------------ |
|**header.h**   | Contains all libraries and function prototypes  |
| **_path.c** |Handle all path browsing to execute commands.|
|**builtins.c**|Structures with all builtins commands. |
|**execute.c**|Forks and executes the processes in the program.|
|**readline.c**|Read the information typed by the user and export a string|
|**split_line.c**|Tonkenize in separated words all the information typed by the user.|
|**Builtins:** <br> <ul> <li>b-cd.c</li> <li>b-env.c</li><li>b-exit.c</li><li>b-setenv.c</li><li>b-unsetenv.c</li></ul> | Implementation of builtins commands|
|**General functions:** <br> <ul> <li>g-calloc.c</li> <li>g-cpy_arrp.c</li><li>g-findenv.c</li><li>g-freearrp.c</li><li>g-freearrp.c</li><li>g-freearrp.c</li><li>g-freearrp.c</li><li>g-str_concat.c</li><li>g-strchr.c</li><li>g-strcmp.c</li><li>g-strdup.c</li><li>g-strlen.c</li><li>g-strtok.c</li></ul> | Implementation of standard C libraries

------------
### More Info
[sh(1)](https://linux.die.net/man/1/sh "sh(1)")

### Authors

* [David Peralta](https://github.com/david-develop/)
* [Carlos Molano.](https://github.com/cmmolanos1/)
