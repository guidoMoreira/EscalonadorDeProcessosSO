#include<stdio.h> 
#include<unistd.h>


int main(int argc, char* argv[])
{
	int i = 0;
	while(i < 15){
		//printf("((argc %i))",argc);	
    		printf("Processo 1: %s\n", argv[0]);	
		usleep(1000000);
		i++;
	}
	
	return 0;
}
