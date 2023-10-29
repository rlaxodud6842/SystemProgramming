#include<stdio.h> //표준 입출력 헤더파일
#include<fcntl.h> //저수준 입출력 헤더파일
#include<stdlib.h> //exit 사용시
#include<unistd.h>

int main(int argc, char* argv[]){
	if (argc <= 4){ //
		if(argc == 4){
        	int fd,n;
	        char buf[1024];
		int index = atoi(argv[2]);
		int offset = atoi(argv[3]);
		
        
        fd = open(argv[1],O_RDONLY);
        if(fd == -1){
            perror("Open");
        }            
        
        lseek(fd,index,SEEK_CUR);
	n=read(fd,buf,offset);
	if(n == -1){
	perror("Read");	
	}
        if(write(1,buf,n) != n) perror("Write");
        printf("\n");    
        close(fd);
        return 0;
                
		}else{
            printf("Usage: myreader index byte\n"); //인자가 한개거나 그 이하면 사용법을 출력.
            return 0;
		}
	}else{
		printf("the other options\n"); //다른 옵션 입력시 처리
	}

}

