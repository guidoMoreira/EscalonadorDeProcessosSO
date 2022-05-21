#include "scheduler.h"
#include "load_jobs.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
extern void iniciarProcesso(int index);

int countConcluido;

void scheduler_init(char* jobs, float quantum){

	pidx = 0;
	alterna = 1;
	receive=0;	

	loadJobs(jobs);

	print_jobsQueue();

	countConcluido = queueSize;
	int i;

	for(i = 0; i < queueSize; i++){
			iniciarProcesso(i);
			kill(spid[i], SIGSTOP);
	}		

/*
  int menor = 0;
		for(int i = 0;i < queueSize;i++){
			if(temp[menor] > temp[i]){
				menor = i; 
			}
		}
		alterna = menor;
	kill(spid[alterna], SIGCONT);
	*/
	while(countConcluido >=0){
		  printf("Menor[>>>>>>>>>>>>>");
		  signal(SIGALRM, alternaTarefa);
		  alarm(quantum);
		  while(!receive)
			pause();
		  receive = 0; 
		sleep(1);
		  
    }


}


void alternaTarefa(int signum){	
	UNUSED(signum);
	//if(TarefaConcluida[alterna]){
		//countConcluido--;
		receive = 1;	
		kill(spid[alterna], SIGSTOP);//Pausa tarefa alternada
		
	
	
		int menor = 0;
		for(int i = 0;i < queueSize;i++){
			if(times[i] == 0){Terminados[i] = 1;}
			if(times[menor] == 0){menor++;}
			if(Terminados[i] == 0 && times[menor] > times[i]){
				menor = i; 
			}
		}
		if(menor < queueSize){
		alterna = menor;
		times[menor]--;

		kill(spid[alterna], SIGCONT);//Continua tarefa alternada
}


}


