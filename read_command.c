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

//return value: number of parameters
//0 represents only command without any parameters
//-1 represents wrong input
int read_command(char **command,char **parameters)
{
    char buffer[MAXLINE];
    fgets(buffer,MAXLINE,stdin);
    if(buffer[0] == '\0')
        return -1;
    char *pStart,*pEnd;
    int length = 0, count = 0,i;
    pStart = pEnd = buffer;
    while(*pEnd !='\0' && *pEnd != '\n')
    {
        while(*pEnd == ' ' && *pStart == ' ')
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
            *command = malloc(sizeof(char)*(pEnd - pStart + 1));
            for(i=0;pStart<pEnd;i++,pStart++)
                (*command)[i] = *pStart;
            (*command)[i] = '\0';
            count++;
            //printf("\ni:%d,command:  %s\n",i,*command);
        }
        else if(count <= MAXARG)
        {
            parameters[count-1] = malloc(sizeof(char)*(pEnd - pStart + 1));
            for(i=0;pStart<pEnd;i++,pStart++)
                parameters[count-1][i] = *pStart;
            parameters[count-1][i] = '\0';
            count++;
        }
        else
        {
            break;
        }
    }

    parameters[count-1] = NULL;

    /*input analysis*/
    printf("input analysis:\n");
    printf("command:%s\nparameters:\n",*command);
    for(i=0;i<count-1;i++)
        printf("%s\n",parameters[i]);
    return count;
}
