#ifndef _JOBS
#define _JOBS



#include <stdio.h>     
#include <stdlib.h>    
#include <unistd.h>   
#include <signal.h>    
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



char **fila;
char **filArg;
char **argumentos;	
int queueSize;      /*Tamanho da Fila de tarefas*/
int spid[100];
int pidx;
float *times;
int *Terminados;

void print_jobsQueue();
void iniciarProcesso(int index);


#endif
