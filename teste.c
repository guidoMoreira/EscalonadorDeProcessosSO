#include<stdio.h> 
#include<unistd.h>


int main(int argc, char* argv[])
{
	
	while(1){
	//printf("((argc %i))",argc);	
    	printf("Processo 1: %s\n", argv[0]);	
	usleep(500000);
	}
	
	return 0;
}
