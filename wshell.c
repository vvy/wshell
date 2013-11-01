/*
 * =====================================================================================
 *       Filename:  wshell.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2013年10月16日 17时12分19秒
 *         Author:  wuyue (wy), vvuyve@gmail.com
 *        Company:  UESTC
 * =====================================================================================
 */
#include "wshell.h"
#define TRUE 1

void proc(void)
{
    int status,i;
    char *command = NULL;
    char **parameters;
	char prompt[MAX_PROMPT];
    parameters = malloc(sizeof(char *)*(MAXARG+2));
    buffer = malloc(sizeof(char) * MAXLINE);
    if(parameters == NULL || buffer == NULL)
    {
        printf("Wshell error:malloc failed.\n");
        return;
    }
	//arg[0] is command
	//arg[MAXARG+1] is NULL
    while(TRUE)
    {
        type_prompt(prompt);
        if(-1 == read_command(&command,parameters,prompt))
			continue;
		if(builtin_command(command,parameters))
			continue;
        if(fork()!=0)
        {
            waitpid(-1,&status,0);
        }
        else
        {
            execvp(command,parameters);
        }
    }
}

int main() {
    proc();
    return 0;
}
