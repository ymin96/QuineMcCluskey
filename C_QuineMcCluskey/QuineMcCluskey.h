#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Implicant.h"
Implicant implicant[100][5][100],PrimeImplicant[100],Essential_PI[100];
int first_key,input_length,*input_number,**EPItable;
void initialize_QuineMcCluskey(int arr[], int num);
void addSubImplicant();
Implicant combination(Implicant *ip1, Implicant *ip2);
int overlap(Implicant arr[], Implicant ip);
void groupOneBit(Implicant pimplicant[5][100],Implicant ip[]);
void extract(Implicant ip[5][100]);
void printPI();
int size2Dimention(Implicant ip[5][100]);
int size1Dimention(Implicant ip[]);
void extractPI();
void initialize_EPItable();
int searchPos(int num);
void print_EPItable();
void print_Formula();
void searchEPI();
void removeImplicant();
void removeAll(int y);
