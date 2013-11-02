wshell: wshell.h wshell.c type_prompt.c read_command.c builtin_command.c parsing.c test
	gcc wshell.c type_prompt.c read_command.c builtin_command.c parsing.c -o wshell

wshell_r: wshell.h wshell.c type_prompt.c read_command.c builtin_command.c parsing.c test
	gcc wshell.c type_prompt.c read_command.c builtin_command.c parsing.c -o wshell -D READLINE_ON -I /usr/include -lreadline -ltermcap

test: test.c
	gcc test.c -o test

clean:
	rm -f wshell test
