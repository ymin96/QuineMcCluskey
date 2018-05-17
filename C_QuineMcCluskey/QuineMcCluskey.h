#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Implicant.h"
Implicant implicant[100][5][100],PrimeImplicant[100],Essential_PI[100];//implicant는 모든 implicant의 값을 다뤄줄 3차원 배열 변수, PrimeImplicant배열은 implicant에서 뽑은 주항을 넣어줄 배열변수, Essential_PI배열은 Primeimplicant에서 뽑은 Essential_PI를 넣어줄 배열
int first_key,input_length,*input_number,**EPItable;//first_key변수는 3차원 implicant배열에서 첫번째 인덱스의 길이를 알려주는 변수, input_length는 프로그램 시작시 입력받은 배열의 크기를 저장하는 변수, input_number은 프로그램 시작시 입력받은 배열을 저장하는 변수, EPItable은 PrimeImplicant변수를 기준으로 2차원 table을 만드는 변수
void initialize_QuineMcCluskey(int arr[], int num);//프로그램 시작시 입력한 배열과 배열의 크기를 인자로 받으며 각종 변수들의 초기화와 PI를 추출하기 위해 merge를 해주는 함수와 추출이 다 끝나면 PI를 추출해주는 함수를 호출해준다.
void addSubImplicant();//3차원 배열까지 쓰면서 for문이 너무 복잡해져 한번 간소화 해주기 위해 만들어준 함수로써 더 이상 merge가 안될때까지 merge해주는 함수를 호출해준다.
Implicant combination(Implicant *ip1, Implicant *ip2);//2개의 implicant의 주소를 받아와 결합하여 새로운 Implicant를 리턴해주는 함수
int overlap(Implicant arr[], Implicant ip);//인자로 Implicant배열과 한개의 Implicant구조체를 받아 받아온 배열 안에 중복값이 있나 검사해주는 함수 중복이 없다면 1반환
void groupOneBit(Implicant pimplicant[5][100],Implicant ip[]);//인자로 2차원 Implicant배열과 1차원 Implicant배열을 받아와 1차원 Implicant배열에서 '1'비트의 개수에 따라 분류하여 2차원Implicant배열에 넣어주는 함수.
void extract(Implicant ip[5][100]);//merge해주는 함수로 인접한 그룹을 비교하여 값을 비교해 알맞은 비교값이면 중복을 검사하고 중복이 없으면 임시배열에 추가한다. 최종적으로 나온 임시배열을 다시 '1'의 비트에 따라 그룹화하여 2차원 배열로 만들고 그 값을 implicant에 넣어주는 함수
void printPI();//PItable을 순차적으로 프린트 해주는 함수
int size2Dimention(Implicant ip[5][100]);//2차원 Implicant배열의 실질적인 길이를 반환해주는 함수
int size1Dimention(Implicant ip[]);//1차원 Implicant배열의 실질적인 길이를 반환해주는 함수 
void extractPI();//최종적으로 만들어진 implicant배열에서 결합에 쓰지않은 즉 PrimeImplicant를 찾아주는 함수
void initialize_EPItable();//최종적으로 추출된 PrimeImplicant를 기준으로 EPItable배열을 초기화 해주는 함수
int searchPos(int num);//PrimeImplicant에서 chart에 들어있는 값을 비교하여 EPItable의 적절한 위치의 행값을 반환해주는 함수
void print_EPItable();//EPItable을 프린트 해주는 함수
void print_Formula();//최종적으로 구해진 Essential_PI를 기준으로 공식을 프린트 해주는 함수
void searchEPI();//EPItable에서 단 한개의 값만 가지고 있는 열을 찾아내여 Essential_PI에 추가해주는 함수
void removeImplicant();//찾아낸 필수 주항을 기준으로 table값을 삭제해주고 추가할 수 있는 항이 있다면 Essential_PI에 추가해주는 함수
void removeAll(int y);//행값을 인자로 받아 EPItable에서 인자로 받은 행에 값이 있다면 그 값의 열값을 다 삭제해주는 함수
