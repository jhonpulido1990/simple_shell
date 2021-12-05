# SIMPLE SHELL

## _What is the Shell?
Whenever you login to a Unix system you are placed in a program called the shell. All of your work is done within the shell.

The shell is your interface to the operating system. It acts as a command interpreter; it takes each command and passes it to the operating system. It then displays the results of this operation on your screen.

There are several shells in widespread use. The most common ones are described below.
Bourne shell (sh)
Original Unix shell written by Steve Bourne of Bell Labs. Available on all UNIX systems. Does not have the interactive facilites provided by modern shells such as the C shell and Korn shell. The Bourne shell does provide an easy to use language with which you can write shell scripts.
C shell (csh)
Written at the University of California, Berkley. As it name indicates, it provides a C like language with which to write shell scripts.

Korn shell (ksh)
Written by David Korn of bell labs. It is now provided as the standard shell on Unix systems. Provides all the features of the C and TC shells together with a shell programming language similar to that of the original Bourne shell.

TC Shell (tcsh)
Available in the public domain. It provides all the features of the C shell together with EMACS style editing of the command line.

Bourne Again Shell (bash)
Public domain shell written by the Free Software Foundation under their GNU initiative. Ultimately it is intended to be a full implementation of the IEEE Posix Shell and Tools specification. Widely used within the academic commnity. Provides all the interactive features of the C shell (csh) and the Korn shell (ksh). Its programming language is compatible with the Bourne shell (sh).

## _what is pid and ppid

```PID: In Linux, an executable stored on disk is called a program, and a program loaded into memory and running is called a process. When a process is started, it is given a unique number called process ID (PID) that identifies that process to the system. If you ever need to kill a process, for example, you can refer to it by its PID.```

```PPID: In addition to a unique process ID, each process is assigned a parent process ID (PPID) that tells which process started it. The PPID is the PID of the process’s parent.```

For example, if process1 with a PID of 101 starts a process named process2, then process2 will be given a unique PID, such as 3240, but it will be given the PPID of 101. It’s a parent-child relationship. A single parent process may spawn several child processes, each with a unique PID but all sharing the same PPID.

## _how to manipulate the current process

| Command  | Function |
| ------------- | ------------- |
| ps  | The ps command is used to list all the currently running processes in the system and information related to them  |
| sleep  | The sleep command is used in Linux to delay a running program by a certain amount of time  |
| jobs  | The jobs command in Linux is used to list the status of all the jobs currently running in the terminal along with their job number  |
