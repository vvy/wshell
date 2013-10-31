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
            char *j,*k;
            j = pStart,k= pEnd;
            *command = malloc(sizeof(char)*(pEnd - pStart + 1));
            for(i=0;pStart<pEnd;i++,pStart++)
                (*command)[i] = *pStart;
            (*command)[i] = '\0';
            k--;
            while(k!=j && *k !='/')
                k--;
            if(*k == '/')
                k++;
            //else //k==pStart
            parameters[0] = malloc(sizeof(char)*(pEnd - j +1));
            for(i=0;j<pEnd;i++,j++)
                parameters[0][i] = *j;
            parameters[0][i] = '\0';
            count += 2;
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
    printf("pathname:%s\ncommand:%s\nparameters:\n",*command,parameters[0]);
    for(i=1;i<count-1;i++)
        printf("%s\n",parameters[i]);
    return count;
}
