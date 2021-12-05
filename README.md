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

## _how shell uses the path to find the programs

### _Searching for command names in PATH

Any command name that is not built-in (e.g. date) is assumed to be the name of an executable program file, and the shell attempts to find an executable file with that name and run it. (Shells find and run commands.)

If the command name contains no slashes (like most command names, e.g. date), the shell looks for the executable file with that exact name in the list of directories kept in the PATH environment variable. Because PATH is a shell environment variable, you can change the list, and the list is usually exported and inherited by child processes of your shell. Directories in PATH are separated by colons, e.g. the following PATH variable contains three directories separated by two colons:

$ echo "$PATH"
/usr/local/bin:/bin:/usr/bin
When you type the command name date (with no slashes), the shell goes looking for the date executable file in the list of directories kept in the PATH environment variable, looking for an executable file named date to execute. The shell tries each directory in the PATH, left-to-right, and runs the first executable program with the matching command name that it finds.

Using the above PATH list of directories, you can see that when you type date, the first directory tried in the PATH is /usr/local/bin, so the shell looks for an executable file named /usr/local/bin/date. This pathname does not usually exist:

$ ls -l /usr/local/bin/date
ls: cannot access /usr/local/bin/date: No such file or directory
The shell next tries the second directory name in the PATH variable (/bin) and looks for an executable file named /bin/date, and this is the usual location of the date executable file:

$ ls -l /bin/date
-rwxr-xr-x 1 root root 59984 Nov 19 17:25 /bin/date
Since this file exists, the shell runs this executable program and the date appears on your screen:

$ date
Sat Mar 16 20:39:13 EDT 2013
You could get exactly the same results on your screen if you typed the full pathname of the executable date file yourself:

$ /bin/date
Sat Mar 16 20:39:43 EDT 2013
Slashes in the pathname prevent the shell from using PATH to look up the command name, so the shell executes /bin/date directly.

## _how to run another program with the exceve system call

execve() executes the program referred to by pathname.  This causes the program that is currently being run by the calling
       process to be replaced with a new program, with newly initialized stack, heap, and (initialized and uninitialized) data segments. pathname must be either a binary executable, or a script starting
       with a line of the form:

           #!interpreter [optional-arg]

       For details of the latter case, see "Interpreter scripts" below.

       argv is an array of pointers to strings passed to the new program as its command-line arguments.  By convention, the first of these strings (i.e., argv[0]) should contain the filename associated
       with the file being executed.  The argv array must be terminated
       by a NULL pointer.  (Thus, in the new program, argv[argc] will be
       NULL.)

       envp is an array of pointers to strings, conventionally of the
       form key=value, which are passed as the environment of the new
       program.  The envp array must be terminated by a NULL pointer.

       The argument vector and environment can be accessed by the new program's main function, when it is defined as:

           int main(int argc, char *argv[], char *envp[])

       Note, however, that the use of a third argument to the main function is not specified in POSIX.1; according to POSIX.1, the
       environment should be accessed via the external variable environ(7).

