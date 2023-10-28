#include<stdio.h> //printf, perror
#include<stdlib.h> //malloc, free
#include<string.h> //strlen

int main(int argc, char* argv[]){
	char* cptr; //사용자의 문자열을 담을 포인터 변수 cptr 선언
	int i; //반복문에 사용될 변수 i선언
	
	if (argc < 2){ //인자의 갯수 비교. -h만 줘도 0번째 인덱스에는 프로그램이, 1번째에는 인자가 와서 2개가 넘게된다.
		printf("Usage: str -h\n"); //인자가 한개거나 그 이하면 사용법을 출력.
		printf("You can learn how to use it by typing str -h.\n");
		return 0;
	}

	if (argv[1][1] == 'h'){ // argv 배열에 1번째에 1번재 index에 h가 있다면. 하이푼 -은 argv[1][0]에 들어가 있기때문에 이렇게 해줘야함.
		printf("This is the program that print the reverse sentece user input\n"); // 사용법 출력
		printf("You can use this program just like\n"); 
		printf("str -r  arbitratystring\n");
		return 0;
	}
//	
	else if (argv[1][1] == 'r'){ // argv 배열에 1번째에 1번재 index에 r가 있다면. 역순으로 출력해주는 로직 작동
		if (argc != 3){ // 3개 이상인 경우, str -r sentence ???? 와 같은 경우 사용법을 참고하라고 출력,
			printf("not enough arguments, please refer to the help\n");
			return 0;
		}
		int n =strlen(argv[2]); //argv[2]에는 사용자가 입력한 문자열이 있을것, 그 문자열의 길이를 n에 담는다.
		cptr = (char*)malloc(sizeof(char)*n); // char의 바이트 와 사용자가 입력한 문장에 필요한 만큼 곱해, ctpr포인터에 저장메모리 공간을 할당함.
		printf("after malloc\n"); //할당 되고있다고 출력

		if(cptr == NULL){ // 만약 할당 되지 않았다면,perror 라이브러리 함수로 오류 출력
			perror("malloc");
			exit(1);
		}else{
			printf("Assinging\n");
			char *userStirng; //유저가 입력한 문자열 변수 선언
			
			userStirng = argv[2]; //변수 안에 문자열 삽입
			
			for (i=0; i<n; i++){
				cptr[i] = userStirng[n-1-i];
			}
			printf("%s\n",cptr);
			//caution: don't miss the following line.	
			free(cptr);
		}
	}
	else{
		printf("the other options\n");
	}

}
