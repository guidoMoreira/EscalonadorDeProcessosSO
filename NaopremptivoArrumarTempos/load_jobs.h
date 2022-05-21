#ifndef _LOADJOBS
#define _LOADJOBS



extern char **fila;
extern char **filArg;
extern char **argumentos;	
extern int queueSize;
extern float *times;     
extern int *Terminados;

void loadJobs(char* file);
void print_jobsQueue();



#endif
