A simple simulation of shell in Linux.

-wshell.c
	main program

-type_prompt.c
	print out the prompt of wshell including path,hostname

-read_command.c
	read command input, and analyse the command and parameter(s).

-test.c
	a test program, helloworld, which can be executed in wshell.

update log:
2013

10.31
	-use execvp() instead of execve() to handle with commands like ls.
	-detect whether the shell is executed as root by geteuid()
	-bug fix:
		execv()'s arg[0] usually is the name of command without path.
		earlier version is not correct.
	-plan to do:
		a built-in cd command.

10.16
	-a shell with basic function: get input and execute the test program(hello world).
	
