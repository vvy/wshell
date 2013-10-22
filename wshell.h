/*
 * =====================================================================================
 *       Filename:  wshell.h
 *    Description:  
 *        Version:  1.0
 *        Created:  2013年10月16日 20时15分26秒
 *         Author:  wuyue (wy), vvuyve@gmail.com
 *        Company:  UESTC
 * =====================================================================================
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXLINE 1024
#define MAXARG 10

void type_prompt();
int read_command(char **command,char **parameters);
void proc(void);

