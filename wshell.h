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
#include <errno.h>
#include <pwd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_PROMPT 1024
#define MAXLINE 4096 //the length of all args is ARG_MAX
#define MAXARG 10

void type_prompt(char*);
int read_command(char **,char **,char*);
int builtin_command(char *,char **);
void proc(void);

struct passwd *pwd;
char *buffer;
