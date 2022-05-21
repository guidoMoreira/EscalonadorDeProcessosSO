#include<stdio.h> 
#include<unistd.h>


int main(int argc, char* argv[])
{

	while(1){	
    	printf("Processo 2: %s\n", argv[0]);
	usleep(1000000);
	}

	return 0;
}
