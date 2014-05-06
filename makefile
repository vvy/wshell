all:wshell wshell_r clean

source=type_prompt.c read_command.c builtin_command.c parsing.c 
wshell: wshell.h wshell.c test $(source)
	$(CC) wshell.c $(source) -o wshell 

wshell_r: wshell.h test wshell.c $(source)
	gcc wshell.c $(source) -o wshell -D READLINE_ON -I /usr/include -lreadline -ltermcap 

test: test.c
	$(CC) test.c -o test

clean:
	-rm  -f wshell test
