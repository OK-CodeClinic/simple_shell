# C - Simple Shell   --- (Team Project)

This project gives a basic general knowledge of; 
1. How does a shell work
2. What is a pid and a ppid
3. How to manipulate the environment of the current process
4. What is the difference between a function and a system call
5. How to create processes
6. What are the three prototypes of main
7. How does the shell use the PATH to find the programs
8. How to execute another program with the execve system call
9. How to suspend the execution of a process until one of its children terminates
10. What is EOF / “end-of-file”?

## Author

- [Kehinde Omokungbe](https://www.github.com/OK-CodeClinic)
- [Joy Kuapa](https://www.github.com/starkjoy)

## Documentation
All projects must obey the;

[ALX Betty Documentation](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
and 
[ALX Betty Style](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl)

## Requirements

### General Requirements;
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)
- Write a README with the description of your project
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker.

### Github Requirements;
There should be one project repository per group. If you and your partner have a repository with the same name in both your accounts, you risk a 0% score. Add your partner as a collaborator.

### List of allowed functions and system calls
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- -stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

### Compilation
Your shell will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### Output
- Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

Example of error with sh:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

Same error with your program hsh:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

### Testing
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### Checks
The Checker will be released at the end of the project (1-2 days before the deadline). We strongly encourage the entire class to work together to create a suite of checks covering both regular tests and edge cases for each task. See task 8. Test suite.
![Logo](data:image/png;base64,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)


