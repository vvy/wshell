<p>A simple simulation of shell in Linux.</p>
<p>-wshell.c<br />	　　main program</p>
<p>-type_prompt.c<br />	　　print out the prompt of wshell including path,hostname</p>
<p>-read_command.c<br />	　　read command input, and analyse the command and parameter(s).</p>
<p>-test.c<br />	　　a test program, helloworld, which can be executed in wshell.</p>
<p>update log:<br />2013</p>
<p>10.31<br />	　　-use execvp() instead of execve() to handle with commands like ls.<br />	　　-detect whether the shell is executed as root by geteuid()<br />	　　-bug fix:<br />		　　　　execv()'s arg[0] usually is the name of command without path.<br />		　　　　earlier version is not correct.<br />	　　-plan to do:<br />		　　　　a built-in cd command.</p>
<p>10.16<br />	　　-a shell with basic function: get input and execute the test program(hello world).<br />	</p>
