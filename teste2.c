#include<stdio.h> 
#include<unistd.h>


int main(int argc, char* argv[])
{

	while(1){	
    	printf("Processo 2\n");	
	usleep(500000);
	}

	return 0;
}
