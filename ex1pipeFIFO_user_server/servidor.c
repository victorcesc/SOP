
// C program to implement one side of FIFO 
// This side reads first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
char users[10][10] = {
		"victor",
		"bruno",
		"jonathan",
		"jose",
		"maria",

};
	



int main() 
{ 
    int fd1; 
  	
    // FIFO file path 
    char * myfifo = "/tmp/myfifo"; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>,<permission>) 
    mkfifo(myfifo, 0666); 
  
    char str1[80], str2[80]; 
    while (1) 
    { 
        // First open in read only and read 
        fd1 = open(myfifo,O_RDONLY); 
        read(fd1, str1, 80); 
  
        // Print the read string and close
		for(int i=0;i<10;i++){
			if(strcmp(str1,&users[i][0])==0){
				printf("Cliente: %s\n", str1);
				str2 = "S";
				close(fd1);
				break; 
			}
							
		}
		str2 = "N"; 
        close(fd1);
         
  
        // Now open in write mode and write 
        // string taken from user. 
        fd1 = open(myfifo,O_WRONLY); 
        //fgets(str2, 80, stdin);		 
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
    } 
    return 0; 
} 
