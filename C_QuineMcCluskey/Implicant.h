#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Implicant {                    //항을 표시하는 구조체로 4비트 정보, '1'비트의 개수,  항들의 결합을 알려줄 배열, 결합에 사용 여부를 알려주는 변수들이 있다.
	int oneBitCount,check,length;             //oneBitCount는 '1'비트의 개수를 나타내는 변수, check 변수는 이 항이 결합에 사용됐는지 알려준다, length는 chart배열의 실질적인 길이를 나타낸다
	char bit[5];                              //입력받은 10진수를 2진수로 바꾸며 문자로 바꾸어줘 char배열에 넣어주기때문에 필요한 변수
	int chart[100];                           //이 항이 어떤 항들의 결합으로 만들어진건지 알려줄 배열변수
}Implicant;

void initialize(Implicant* ip, int num);      //Implicant변수를 초기화 하는 함수로써 초기화할 Implicant변수의 주소와 10진수 num값을 인자로 받으면 10진수 num을 분석하여 자동으로 Implicant변수값을 채워주는 함수 
void initializes_all(Implicant*ip, int _oneBitCount, int _check, char _bit[], int _chart[]);     //Implicant변수를 초기화 하는 함수로써 초기화할 Implicant변수의 주소와 Implicant변수의 값을 대부분 받아와 복제해주는 역할의 함수
int compareTo(Implicant ip1, Implicant ip2);  //Implicant변수의 bit값을 비교해주는 함수 만약 비트값이 단 1개만 다를경우 1(true)를 리턴 아닐경우 0(false)를 리턴해주는 함수
int countOneBit(char _bit[]);                 //char형 배열을 인자로 받아 '1'비트가 몇개 있는 체크하여 그 수만큼 리턴해주는 함수
int get_length(int chart[]);                  //chart배열의 실질적 값을 리턴해주는 함수 chart배열을 -1로 초기화 하기 때문에 -1이 나오지 않을때까지 카운팅을 하여 카운팅 한 값을 반환해주는 함수
char* tenCoverTwo(int _num);                  //10진수 값을 입력받아 2진수로 변환해주는 함수 리턴값은 char형 배열을 리턴하기때문에 char*형