//codigo referente a criacao de processo A->B--C
//                                          |
//                                          D  
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid, status;
    pid = fork();

    if(pid == -1) // fork falhou
    {
        perror("fork falhou!");
        exit(-1);
    }

    else if(pid == 0) // Este é o processo B(filho de A)
    {	
	int pid,status;	
	pid = fork();
	
	
	if(pid == -1) // fork falhou
    	{
        	perror("fork falhou!");
        	exit(-1);
    	}
	
	else if(pid == 0)// Este é o processo C(filho de B)
	{
	  printf("processo C\t pid: %d\t pid pai: %d\n", getpid(), getppid());
          exit(0);
	}
	else
	{
	  pid = fork();
	  if(pid == 0)
	  {
	   printf("processo D\t pid: %d\t pid pai: %d\n", getpid(),getppid());
	   exit(0); 
	  }		  
	  wait(&status);
	  wait(&status);
	  printf("processo B\t pid: %d\t pid pai: %d\n", getpid(), getppid());
          exit(0);	
	}

	
	
    }
    else // Este é o processo A(pai)
    {
        wait(&status);
        printf("processo A\t pid: %d\t pid pai: %d\n", getpid(), getppid());
        exit(0);
    }
}
