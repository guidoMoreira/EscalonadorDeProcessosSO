#include "scheduler.h"
#include "load_jobs.h"
#include <unistd.h>
#include <signal.h>

extern void iniciarProcesso(int index);

int countConcluido;

void scheduler_init(char* jobs, float quantum){

	pidx = 0;
	alterna = 1;
	receive=0;	

	loadJobs(jobs);

	print_jobsQueue();

	int temp[queueSize];
	countConcluido = queueSize;
	int i;

	for(i = 0; i < queueSize; i++){
			iniciarProcesso(i,argQueues);//Criar variavel para salvar argQueues
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
	
	
	
		//int menor = 0;
/*
		for(int i = 0;i < queueSize;i++){
      
			if(tempo[menor] > tempo[i]){
				menor = i; 
			}
		}*/
		//alterna = menor;

	/*
	if(!alterna)//Se alterna igual a zero
		alterna++;//Alterna = 1
	else// se igual a outro valor que não zero
		alterna = 0;//Alterna = 0
	*/

	//Lembretes remover ultimo menor tempo da lista de possibilidades

  if(alterna == queueSize-1){
        alterna = 0;
    }else{
      alterna++;
    }
kill(spid[alterna], SIGCONT);//Continua tarefa alternada

	//}


}


