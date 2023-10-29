#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	if (argc <= 2){ //명령행 인자 핸들링
        if(argc == 2){
            char buffer[1024]; // 파일기술자에서 읽은 정보를 저장할 버퍼
            char temp[1024]; // row와 불러온 문자열을 합치기 전 잠시 저장할 배열
            char str[9999]; // row와 문자열을 합친 문자열이 들어갈 characthar 배열
            int fd,r,n; //fd = 파일 기술자, r = 읽어온 바이트 수, n = sprintf 된 숫자.
            int row = 0; // 행 번호

            fd = open(argv[1], O_RDONLY); // 파일을 읽어온다.
            if (fd == -1) {
                perror("Open Error"); //perror 호출로 오류시, 오류 출력
                exit(1);
                }
            int counter = 0;
            while ((r = read(fd,buffer,1)) > 0){ //한 바이트씩 읽음
                if(buffer[0] == '\n'){ //읽어온 바이트가 개행문자인지 확인
                    n = sprintf(str,"%d %s\n",row,temp); //행번호와, 문자열들 합치는 과정 n에는 합쳐진 문자열의 길이가 저장
                        if (write(1,str,n) != n) perror("Write"); //write가 오류가 났을때 perror 호출
                    for(int i = 0; i<1024; i++){ // 현재까지 저장되어있던 문자열 배열 초기화
                   	temp[i] = '\0';
                    }
                    for(int t = 0; t<9999; t++){ // 합쳐진 문자열이 있는 배열 초기화
                        str[t] = '\0';
                    }
                    row++; // 행번호 증가
                    counter = 0; // 잠시 저장되는 문자열 배열의 인덱스 번호 초기화

                }else{
                    temp[counter] = buffer[0]; // 읽어온 한 바이트를 잠시 저장되는 문자열 배열에 0부터 저장.
                    counter++; // 인덱스 증가
                    }

                }
	    close(fd); //close filediscripter
	    return 0;
	}else{//명령행 인자로 my cat만 왔을때
        printf("Usage: mycat [YourFile]\n");
        return 0;}
	}else{//명령행 인자로 많은 인자가 주어졌을때
            printf("지원되지 않는 옵션입니다.\n");
            return 0;
        }
}

