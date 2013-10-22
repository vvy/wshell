wshell: wshell.h wshell.c type_prompt.c read_command.c test
	gcc wshell.c type_prompt.c read_command.c -o wshell

test: test.c
	gcc test.c -o test

clean:
	rm -f wshell test
