# Introduction
A simple simulation of shell in Linux for learning.
A blog (in Chinese) of introduction and how to build it :http://www.cnblogs.com/wuyuegb2312/p/3399566.html

# Usage
type

　　make wshell

for wshell read input by fgets() or

　　make wshell_r
　　

for wshell with readline lib.It need to install libreadline5-dev first.


## Attention

　　Because of the lack of support for regular expressions , typing file's names such as "*.c" are not support.
　　

# File List
### wshell.c
　　main program

### type_prompt.c
　　print out the prompt of wshell including path,hostname

### read_command.c
　　read command input, and analyse the command and parameter(s).

### builtin_command.c
　　support some built-in command,such as exit,quit,about, and cd.

### test.c
　　a test program, helloworld, which can be executed in wshell.

### parsing.c
　　analyses user's input line and tell them to wshell.
　　
# Update log

## 2015
### 11.08
    -Make the README.md be a real markdown file.
    -Bug fix:
        Redirection operator ">>" will append a file, not trunc it to 0-size.
        As noted by [caiminfeng](http://www.cnblogs.com/caiminfeng/).

## 2014
### 05.14

    -Bug fix:

        In readline mode, the spaces alloced by readline() was freed only once.Now they are all freed in the end of read_command().

        As noted by [xingfe123](http://home.cnblogs.com/u/614123/)

 

### 04.14

    -Bug fix:

        Add handler of SIGCHLD. Earlier wshell would ignore the zombie process in background.

        The handler only process the background process whose pid are saved in a array.

     -Adjust some indents, although they are not errors.

 

## 2013

### 12.8

    -Bug fix:

        Output redirect function was not completed. '>' still is for make new file,but '>>' append to any file now.

 

### 11.3
    -Implemented a simple parsing function parse() to analyses the user input.
    -Support I/O redirect, background running, and pipe. 
    -Bug fix:
        Typing ctrl+d will normal exit wshell. before, segment fault when using readline lib.

        Lack of free() somewhere, which may lead to memory leak.

 

### 11.1
    -Implemented some builtin command,such as exit/quit, about, and, cd.
    -Bug fix:
        Never free the memory of command and parameters before, which may cause memory leak.
        To solve it, read_command() has been rewrited, and is more like the one in Linux.
    -Rewrite read_command():
        There is no need to malloc for command and parameters any more.
        All these just are pointers now.
    -Supply two versions:
        Using readline lib and not.the former need installing readline lib.
        Type "make wshell_r" to make the former,and "make wshell" for another.


### 10.31
    -Use execvp() instead of execve() to handle with commands like ls.
    -Detect whether the shell is executed as root by geteuid()
    -Bug fix:
        execv()'s arg[0] usually is the name of command without path.
        earlier version is not correct.
    -Plan to do:
        a built-in cd command.

##10.16
    -A shell with basic function: get input and execute the test program(hello world).