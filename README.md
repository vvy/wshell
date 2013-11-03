<p>A simple simulation of shell in Linux.</p>
<p>A blog (in Chinese)&nbsp;of introduction&nbsp;and how to build it :<a href="http://www.cnblogs.com/wuyuegb2312/p/3399566.html">http://www.cnblogs.com/wuyuegb2312/p/3399566.html</a></p>
<p>usage:<br />============<br />type<br />	　　make wshell<br />for wshell read input by fgets() or<br />	　　make wshell_r<br />for wshell with readline lib.It need to install libreadline5-dev first.</p>
<p><br />consist of:<br />============<br />-wshell.c<br />　　main program</p>
<p>-type_prompt.c<br />　　print out the prompt of wshell including path,hostname</p>
<p>-read_command.c<br />　　read command input, and analyse the command and parameter(s).</p>
<p>-builtin_command.c<br />　　support some built-in command,such as exit,quit,about, and cd.</p>
<p>-test.c<br />　　a test program, helloworld, which can be executed in wshell.</p>
<p>-parsing.c<br />	　　analyses user's input line and tell them to wshell.</p>
<p><br />update log:<br />============<br />2013</p>
<p>11.3<br />　　-implemented a simple parsing function parse() to analyses the user input.<br />　　-support I/O redirect, background running, and pipe. <br />　　-bug fix:<br />		　　　　typing ctrl+d will normal exit wshell.before, segment fault when using readline lib.</p>
<p>&nbsp;</p>
<p>　　　　lack of free() somewhere ,which may lead to memory leak.</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>11.1<br />　　-implemented some builtin command,such as exit/quit, about, and, cd.<br />　　-bug fix:<br />　　　　never free the memory of command and parameters before, which may cause memory leak.<br />　　　　To solve it, read_command() has been rewrited, and is more like the one in Linux.<br />　　-rewrite read_command():<br />　　　　there is no need to malloc for command and parameters any more.<br />　　　　all these just are pointers now.<br />　　-supply two versions:<br />　　　　using readline lib and not.the former need installing readline lib.<br />　　　　type "make wshell_r" to make the former,and "make wshell" for another.</p>
<p><br />10.31<br />　　-use execvp() instead of execve() to handle with commands like ls.<br />　　-detect whether the shell is executed as root by geteuid()<br />　　-bug fix:<br />　　　　execv()'s arg[0] usually is the name of command without path.<br />　　　　earlier version is not correct.<br />　　-plan to do:<br />　　　　a built-in cd command.</p>
<p>10.16<br />　　-a shell with basic function: get input and execute the test program(hello world).</p>
