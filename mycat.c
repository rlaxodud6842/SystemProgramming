#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char buffer[1024];
    char ccc[1024];  // 파일에서 읽은 데이터를 저장할 버퍼
    int fd,r,n;             // 파일 디스크립터
    int row = 0;
    char str[9999];
    char *space;

    fd = open("unix.txt", O_RDONLY);
    if (fd == -1) {
        perror("파일을 열 수 없음");
        exit(1);
        }



    int counter = 0;
    while ((r = read(fd,buffer,1)) > 0){
        if(buffer[0] == '\n'){
            n = sprintf(str,"%d %s\n",row,ccc);
	    write(1,str,n);
            ccc[0] = '\0';
	    str[0] = '\0';
            row++;
	    counter = 0;
        }else{
        ccc[counter] = buffer[0];
        counter++;
	}
    }

    // 파일 닫기
    close(fd);

    return 0;
}

