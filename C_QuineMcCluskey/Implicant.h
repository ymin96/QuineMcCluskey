#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Implicant {
	int oneBitCount,check,length;
	char bit[5];
	int chart[100];
}Implicant;

void initialize(Implicant* ip, int num);
void initializes_all(Implicant*ip, int _oneBitCount, int _check, char _bit[], int _chart[]);
int compareTo(Implicant ip1, Implicant ip2);
int countOneBit(char _bit[]);
int get_length(int chart[]);
char* tenCoverTwo(int _num);