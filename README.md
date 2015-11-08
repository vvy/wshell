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
    -Bug fix1:
        Redirection operator ">>" will append a file, not trunc it to 0-size.
As noted by [caiminfeng](http://www.cnblogs.com/caiminfeng/) .

    -Bug fix2:
        When inputed "cd", it would be core dump before.
As noted by [guokesong](https://github.com/guokesong) in [issues2](https://github.com/vvy/wshell/issues/2).

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


# 简介
为了学习而编写的Linux下shell的简单模拟实现。
介绍如何一步一步编写该程序的博客：http://www.cnblogs.com/wuyuegb2312/p/3399566.html

# 用法
输入

　　make wshell

构建使用fgets()接收命令的wshell

　　make wshell_r
　　

构建使用readline接收命令的wshell。需要安装libreadline5-dev或其他类似的库。


## 注意

　　由于不支持正则表达式，含有通配符如"*.c"这样的文件名是不支持的。
    不存在的命令不会提示。
　　

# 文件列表
### wshell.c
　　主程序

### type_prompt.c
　　拼接当前路径、主机名的提示符。

### read_command.c
　　读取输入的命令，并分离出其中的参数。

### builtin_command.c
　　提供对基本内建命令的支持，含exit、quit、about、cd等。

### test.c
　　用来在wshell中执行的测试程序。

### parsing.c
　　分析用户输入（是否使用了管道、重定向、后台执行等）。
　　
# 更新记录

## 2015
### 11.08
    -让README.md成为了真正的markdown文件
    -调整部分缩进
    -Bug修复1:
        重定向符">>"将正确地在文件存在时做追加，而非把它变成0大小的文件。
感谢[caiminfeng](http://www.cnblogs.com/caiminfeng/) 的指出。

    -Bug修复2:
       当输入不带参数的 `cd`时，会导致崩溃。
感谢 [guokesong](https://github.com/guokesong) 在 [issues2](https://github.com/vvy/wshell/issues/2) 指出。

## 2014
### 05.14

    -Bug修复:

        在readline模式下, readline()申请的内存不会被释放。

感谢[xingfe123](http://home.cnblogs.com/u/614123/) 指出。

 

### 04.14

    -Bug修复:

        增加了SIGCHLD信号的处理器。较早版本的wshell不会处理后台的僵尸进程。

        但是该处理器只会处理事先保存了pid的子进程。

    -调整了不会导致错误的缩进。

 

## 2013

### 12.08

    -Bug修复:

        输出重定向尚未完成。 '>' 仍然会创建新文件，但是'>>'会往文件末尾追加。

 

### 11.03
    -实现了用于分析用户输入的函数parse()。
    -支持输入输出重定向、管道、后台运行。
    -Bug修复:
        输入ctrl+d会正常退出wshell了。此前，在使用readline库时会段错误。

        由于某处缺少free(), 会内存泄漏。

 

### 11.01
    -实现了一些内建命令，包括`exit` 、 `quit` 、 `about` 、 `cd`。
    -Bug修复:
        从未释放命令和参数的空间，导致内存泄漏。
        重写read_command()以解决这个问题，现在的行为更像Linux的了。
    -重写read_command():
        现在没必要为command和parameter释放内存了，它们只是指针。
    -提供了两个版本:
        使用readline库和不使用的。前者需要事先安装这个库。
        输入"make wshell_r"可以生成前者，而"make wshell"会生成后者。


### 10.31
    -用execvp()代替execve()处理 `ls` 这种命令。
    -通过geteuid()判断shell是否执行在root用户下。
    -Bug修复:
        execv()'的arg[0]一般是不含路径的命令，上一个版本处理有误。
    -下一步计划:
        支持内建命令 `cd`。

##10.16
    -一个具有基本功能的shell: 获取输入并执行测试程序(hello world).