/*
 * =====================================================================================
 *       Filename:  read_command.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2013年10月21日 14时12分24秒
 *         Author:  wuyue (wy), vvuyve@gmail.com
 *        Company:  UESTC
 * =====================================================================================
 */
#include "wshell.h"
#ifdef READLINE_ON
#include <readline/readline.h>
#include <readline/history.h>
#endif

//return value: number of parameters
//0 represents only command without any parameters
//-1 represents wrong input
int read_command(char **command,char **parameters,char *prompt)
{
#ifdef READLINE_ON
	buffer  = readline(prompt);
#else
	printf("%s",prompt);
    fgets(buffer,MAXLINE,stdin);
#endif
    if(buffer[0] == '\0')
        return -1;
    char *pStart,*pEnd;
    int count = 0;
    int isFinished = 0;
    pStart = pEnd = buffer;
    while(isFinished == 0)
    {
        while((*pEnd == ' ' && *pStart == ' ') || (*pEnd == '\t' && *pStart == '\t'))
        {
            pStart++;
            pEnd++;
        }

        if(*pEnd == '\0' || *pEnd == '\n')
        {
            if(count == 0)
                return -1;
            break;
        }

        while(*pEnd != ' ' && *pEnd != '\0' && *pEnd != '\n')
            pEnd++;


        if(count == 0)
        {
            char *p = pEnd;
            *command = pStart;
            while(p!=pStart && *p !='/')
                p--;
            if(*p == '/')
                p++;
            //else //p==pStart
            parameters[0] = p;
            count += 2;
            printf("\ncommand:  %s\n",*command);
        }
        else if(count <= MAXARG)
        {
            parameters[count-1] = pStart;
            count++;
        }
        else
        {
            break;
        }

        if(*pEnd == '\0' || *pEnd == '\n')
        {
            *pEnd = '\0';
            isFinished = 1;
        }
        else
        {
            *pEnd = '\0';
            pEnd++;
			pStart = pEnd;
        }
    }

    parameters[count-1] = NULL;

    /*input analysis*/
    printf("input analysis:\n");
    printf("pathname:%s\ncommand:%s\nparameters:\n",*command,parameters[0]);
    int i;
    for(i=1;i<count-1;i++)
        printf("%s\n",parameters[i]);
    return count;
}
