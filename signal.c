#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
//This program for sending the signal to process using keyboard
int main()
{
 void sigint_handler(int sig);
 char s[200];

 if( signal(SIGINT,sigint_handler) == SIG_ERR )
 {
  perror("signal");
  exit(1);
 }

 printf("Enter a string: ");

 if( fgets(s,200,stdin) == NULL )
  perror("Gets");
 else
  printf("You entered: %s\n",s);

 return 0;
}

void sigint_handler(int sig)
{
 printf(" Please don't disturb me!\n");
}
