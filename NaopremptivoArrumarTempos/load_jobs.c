#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load_jobs.h"



void loadJobs(char* file)
{
	


  int count=0,index=0,index2=0,l,c,k,ind;
  
  FILE *arquivo;
  char job[10] = "";
  char ch;	
  int args = 0;              /*contador para os argumentos*/	

  int progXargs[100][100];	


  fila = malloc(100);	
  argumentos = malloc(100);	
 
 
  arquivo = fopen(file, "r");


  for(l=0; l < 100; l++){
	for(c=0; c < 100; c++)
		progXargs[l][c] = 0;
  }

  
  while((ch=fgetc(arquivo)) != EOF){
		if(ch != ' ' && ch != '\n'){
			job[count] = ch;
			count++;		
		}else{
			printf("%s", job);
			if(job[0] == '.'){
				/*  era o original*/
				fila[index] = malloc(((size_t) strlen(job))*sizeof(char));
				strcpy(fila[index],job);
				printf("(%s)\n",fila[index]);	
				memset(job, 0, 10);			
				index++;
			}else if(strcmp(job, "")){
				argumentos[index2] = malloc(((size_t) strlen(job))*sizeof(char));
				strcpy(argumentos[index2],job);
				printf("(%s)",argumentos[index2]);

				memset(job, 0, 10);	
				progXargs[index-1][index2] = 1;
				index2++;
			}
			
			count = 0;	
		}		
  }
  	  
 
  for(k=0; k < index; k++)
		printf("\nProcesso %d: %s", k, fila[k]);

  printf("\n\n\n");	
  
  filArg =(char**)malloc(sizeof(char*) * index);
  times = (float*)malloc(sizeof(float) * index);
  Terminados = (int*)malloc(sizeof(int) * index);  

  for(l=0; l < index; l++){
	filArg[l] = (char*)malloc(sizeof(char)*100);
	filArg[l][0] = ' ';/*'\0'*/
	
	times[l] = (float)1/(l+1)*6;/*Arrumar Tempos corretos Aqui*/	
	printf("<<%f>>",times[l]);
	Terminados[l] = 0;


	args = 0;
	
	for(c=0; c < index2; c++){
		if(progXargs[l][c] && strcmp(argumentos[c],""))
				args++;				
	}
	
	for(ind=0; ind < index2; ind++){
		if(progXargs[l][ind]){
				strcat(argumentos[ind], " ");
				strcat(filArg[l], argumentos[ind]);
		}		
	}


  }	

  queueSize = index;
  fclose(arquivo);
    
}

