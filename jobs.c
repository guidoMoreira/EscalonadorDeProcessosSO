#include <unistd.h>
#include "jobs.h"



void print_jobsQueue(){
	int ind;	
	
	printf("\n\n PROCESSOS NA FILA! \n\n");
	for(ind = 0; ind < queueSize; ind++)
		printf(" %s ", fila[ind]);

}


void iniciarProcesso(int index, int index2){

	pid_t pid;	

	pid = fork();

	if(pid == 0){
		printf("\n%s, argumentos: %s\n",fila[index],argumentos[index]);
		char *fakearg = NULL;
		execlp(fila[index], argumentos[index2],(char *)NULL);
		kill(pid, SIGSTOP); 

	}else{
		printf("spid [%d] = %d \n",pidx, spid[pidx]);
		spid[pidx] = pid;
		pidx++;	

	}
	
	
}
