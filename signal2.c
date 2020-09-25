/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int glob = 0;
int counter = 0;

void handler_alarm(int signum)
{ //signal handler
  glob = 1;
  counter++;
}

void handler_int(int signum)
{ //signal handler
  printf("Total time - %d (s)\n", counter);
  exit(0);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler_alarm); //register handler to handle SIGALRM
  signal(SIGINT,handler_int); //register handler to handle SIGINT
  while(1){
    alarm(1); //Schedule a SIGALRM for 1 second
    while(glob==0); //busy wait for signal to be delivered
    printf("Turing was right!\n");
    glob = 0;
  }
  
  
  return 0; //never reached
}
