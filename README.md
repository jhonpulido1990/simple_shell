![Anurag's GitHub stats](https://github-readme-stats.vercel.app/api?username=easantanders21&theme=dark&show_icons=true)

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
| bg  | The bg command is used to push a suspended process into the background where it can continue to run  |
| fg  | Similar to the bg command, the fg command is used to bring back a suspended process in the background to the foreground  |
| kill  | The kill command in Linux is used to kill or stop a currently running process. The kill command can be used both with the job number and the Process ID (or PID)  |

## _what is the difference between a function and a call

The main difference between system call and function call is that a system call is a request for the kernel to access a resource while a function call is a request made by a program to perform a specific task.

Although the two terms are used interchangeably, there is a difference between system call and function call. System calls are used when a program needs to communicate with the kernel while function calls are used to call a specific function within the program.

## _how to create processes

A new process can be created by the fork() system call. The new process consists of a copy of the address space of the original process. fork() creates new process from existing process. Existing process is called the parent process and the process is created newly is called child process. The function is called from parent process. Both the parent and the child processes continue execution at the instruction after the fork(), the return code for the fork() is zero for the new process, whereas the process identifier of the child is returned to the parent.

```Fork() system call is situated in <sys/types.h> library.```

System call getpid() returns the Process ID of the current process and getppid() returns the process ID of the current process’s parent process.

## _what are the three prototypes of main

main() in a hosted environment is implicitly assumed to have one of the two forms:

```int main(void);``` 
```int main(int argc, char **argv);```

The value of the argc argument is the number of command line arguments. The argv argument is a vector of C strings; its elements are the individual command line argument strings. The file name of the program being run is also included in the vector as the first element; the value of argc counts this element. A null pointer always follows the last element: argv[argc] is this null pointer.

Optionally, some implementations (mostly POSIX systems) also provide a third form:

```int main(int argc, char **argv, char **envp)```

The third argument envp gives the program’s environment; it is the same as the value of environ. See Environment Variables. POSIX.1 does not allow this three-argument form, so to be portable it is best to write main to take two arguments, and use the value of environ.

