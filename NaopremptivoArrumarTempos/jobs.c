#include <unistd.h>
#include "jobs.h"
#include <strings.h>


void print_jobsQueue(){
	int ind;	
	
	printf("\n\n PROCESSOS NA FILA! \n\n");
	for(ind = 0; ind < queueSize; ind++)
		printf(" %s ", fila[ind]);

}


void iniciarProcesso(int index){

	pid_t pid;	

	pid = fork();

	if(pid == 0){
		
		char arg[sizeof(filArg[index])];
		strcpy(arg,filArg[index]);
		printf("\n%s, argumentos: %s\n",fila[index],arg);
		execlp(fila[index], arg,(char*)NULL);/*execvp vs execlp*/
		kill(pid, SIGSTOP);

	}else{
		printf("spid [%d] = %d \n",pidx, spid[pidx]);
		spid[pidx] = pid;
		pidx++;	
		/*waitpid(0, NULL, 0);*Esperar Pai*
		Terminados[index] = 1;
		printf("Processo %i Terminado",index+1);*/
	}
	
	
}
