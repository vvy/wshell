<p>A simple simulation of shell in Linux for learning.</p>
<p>A blog (in Chinese)&nbsp;of introduction&nbsp;and how to build it :<a href="http://www.cnblogs.com/wuyuegb2312/p/3399566.html">http://www.cnblogs.com/wuyuegb2312/p/3399566.html</a></p>
<p>usage:<br />============<br />type<br />	　　<em>make wshell</em><br />for wshell read input by fgets() or<br />	　　<em>make wshell_r</em><br />for wshell with readline lib.It need to install libreadline5-dev first.</p>
<p>Attention:</p>
<p>　　Because of&nbsp;<span class="label_list">the lack of support for regular expressions , file's names such as *.c are not support.</span></p>
<p><br />consist of:<br />============<br />-wshell.c<br />　　main program</p>
<p>-type_prompt.c<br />　　print out the prompt of wshell including path,hostname</p>
<p>-read_command.c<br />　　read command input, and analyse the command and parameter(s).</p>
<p>-builtin_command.c<br />　　support some built-in command,such as exit,quit,about, and cd.</p>
<p>-test.c<br />　　a test program, helloworld, which can be executed in wshell.</p>
<p>-parsing.c<br />	　　analyses user's input line and tell them to wshell.</p>
<p><br />update log:<br />============</p>
<p>2014</p>
<p>4.14</p>
<p>&nbsp; &nbsp; -Bug fix:</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; Add handler of&nbsp;SIGCHLD. Earlier wshell would ignore the&nbsp;zombie process in background.</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; The handler only process the background process whose pid are saved in a array.</p>
<p>&nbsp; &nbsp; &nbsp;-Adjust some indents, although they are not errors.</p>
<p><span>&nbsp;</span></p>
<p>2013</p>
<p>12.8</p>
<p>&nbsp; &nbsp; -Bug fix:</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; Output redirect function was not completed. '&gt;' still is for make new file,but '&gt;&gt;' append to any file now.</p>
<p>&nbsp;</p>
<p>11.3<br />&nbsp; &nbsp;&nbsp;-Implemented a simple parsing function parse() to analyses the user input.<br />&nbsp; &nbsp;&nbsp;-Support I/O redirect, background running, and pipe. <br />&nbsp; &nbsp;&nbsp;-Bug fix:<br />&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;Typing ctrl+d will normal exit wshell. before, segment fault when using readline lib.</p>
<p>&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;Lack of free() somewhere, which may lead to memory leak.</p>
<p>&nbsp;</p>
<p>11.1<br />&nbsp; &nbsp;&nbsp;-Implemented some builtin command,such as exit/quit, about, and, cd.<br />&nbsp; &nbsp;&nbsp;-Bug fix:<br />&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;Never free the memory of command and parameters before, which may cause memory leak.<br />&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;To solve it, read_command() has been rewrited, and is more like the one in Linux.<br />&nbsp; &nbsp;&nbsp;-Rewrite read_command():<br />&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; There is no need to malloc for command and parameters any more.<br />&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;All these just are pointers now.<br />&nbsp; &nbsp;&nbsp;-Supply two versions:<br />&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;Using readline lib and not.the former need installing readline lib.<br />&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;Type "make wshell_r" to make the former,and "make wshell" for another.</p>
<p><br />10.31<br />&nbsp; &nbsp;&nbsp;-Use execvp() instead of execve() to handle with commands like ls.<br />&nbsp; &nbsp;&nbsp;-Detect whether the shell is executed as root by geteuid()<br />&nbsp; &nbsp;&nbsp;-Bug fix:<br />&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;execv()'s arg[0] usually is the name of command without path.<br />&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;earlier version is not correct.<br />&nbsp; &nbsp;&nbsp;-Plan to do:<br />&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;a built-in cd command.</p>
<p>10.16<br />&nbsp; &nbsp;&nbsp;-A shell with basic function: get input and execute the test program(hello world).</p>
