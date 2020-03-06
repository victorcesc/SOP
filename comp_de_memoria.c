#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <conio.h>


#define SHM_SIZE 1024 

struct {
	int matriz[4][10];
	int padrao;
	int contador;
	} *pMatriz;

	//pMatriz->padrao = 5;	

	
int main(int argc, char *argv[])
{
	key_t key;
	int shmid;
	char *segmento;
	int modo,filho;

	
	shmid = shmget(IPC_PRIVATE, SHM_SIZE, S_IRUSR | S_IWUSR);
	if (shmid == -1) {
		perror("shmget");
		exit(1);
	}

	

	
	pMatriz = shmat(shmid, (void *)0, 0);
	if (segmento == (char *)(-1)) {
		perror("shmat");
		exit(1);
	}  
     	
/*	for(){
	   pid = fork();
	   if(pid ==0){
		///
exit(0);
	   }
	}		

	for(){
	wait(NULL)	
	}
*/	

	if((filho = fork()) == -1)
	{
		perror("fork");
		exit(1);
	}

	if(filho == 0)
	{
	        //char *ptr_msg = "alo pai, tudo bem?";   
		//printf("Filho escrevendo no segmento compartilhado\n\n");
		//completar aqui strcpy(segmento, ptr_msg);       //aqui deveria testar a cpacidade da área...
		//strcpy(segmento, ptr_msg);
		exit(0);
	}
	else
	{
	   wait(NULL);	            
	   printf("Mensagem para o pai: %s\n", segmento);
	       
	}
        
	
	if (shmdt(segmento) == -1) {
		perror("shmdt");
		exit(1);
	}

   return 0;
}


void iniciar_matriz(){

	for(int i=0;i<4;i++){
		for(int j=0;j<10;j++){
		//	pMatriz->matriz[i][j] = rand() % 10;
		}
	}




}
