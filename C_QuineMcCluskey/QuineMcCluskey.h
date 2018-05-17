#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Implicant.h"
Implicant implicant[100][5][100],PrimeImplicant[100],Essential_PI[100];//implicant�� ��� implicant�� ���� �ٷ��� 3���� �迭 ����, PrimeImplicant�迭�� implicant���� ���� ������ �־��� �迭����, Essential_PI�迭�� Primeimplicant���� ���� Essential_PI�� �־��� �迭
int first_key,input_length,*input_number,**EPItable;//first_key������ 3���� implicant�迭���� ù��° �ε����� ���̸� �˷��ִ� ����, input_length�� ���α׷� ���۽� �Է¹��� �迭�� ũ�⸦ �����ϴ� ����, input_number�� ���α׷� ���۽� �Է¹��� �迭�� �����ϴ� ����, EPItable�� PrimeImplicant������ �������� 2���� table�� ����� ����
void initialize_QuineMcCluskey(int arr[], int num);//���α׷� ���۽� �Է��� �迭�� �迭�� ũ�⸦ ���ڷ� ������ ���� �������� �ʱ�ȭ�� PI�� �����ϱ� ���� merge�� ���ִ� �Լ��� ������ �� ������ PI�� �������ִ� �Լ��� ȣ�����ش�.
void addSubImplicant();//3���� �迭���� ���鼭 for���� �ʹ� �������� �ѹ� ����ȭ ���ֱ� ���� ������� �Լ��ν� �� �̻� merge�� �ȵɶ����� merge���ִ� �Լ��� ȣ�����ش�.
Implicant combination(Implicant *ip1, Implicant *ip2);//2���� implicant�� �ּҸ� �޾ƿ� �����Ͽ� ���ο� Implicant�� �������ִ� �Լ�
int overlap(Implicant arr[], Implicant ip);//���ڷ� Implicant�迭�� �Ѱ��� Implicant����ü�� �޾� �޾ƿ� �迭 �ȿ� �ߺ����� �ֳ� �˻����ִ� �Լ� �ߺ��� ���ٸ� 1��ȯ
void groupOneBit(Implicant pimplicant[5][100],Implicant ip[]);//���ڷ� 2���� Implicant�迭�� 1���� Implicant�迭�� �޾ƿ� 1���� Implicant�迭���� '1'��Ʈ�� ������ ���� �з��Ͽ� 2����Implicant�迭�� �־��ִ� �Լ�.
void extract(Implicant ip[5][100]);//merge���ִ� �Լ��� ������ �׷��� ���Ͽ� ���� ���� �˸��� �񱳰��̸� �ߺ��� �˻��ϰ� �ߺ��� ������ �ӽù迭�� �߰��Ѵ�. ���������� ���� �ӽù迭�� �ٽ� '1'�� ��Ʈ�� ���� �׷�ȭ�Ͽ� 2���� �迭�� ����� �� ���� implicant�� �־��ִ� �Լ�
void printPI();//PItable�� ���������� ����Ʈ ���ִ� �Լ�
int size2Dimention(Implicant ip[5][100]);//2���� Implicant�迭�� �������� ���̸� ��ȯ���ִ� �Լ�
int size1Dimention(Implicant ip[]);//1���� Implicant�迭�� �������� ���̸� ��ȯ���ִ� �Լ� 
void extractPI();//���������� ������� implicant�迭���� ���տ� �������� �� PrimeImplicant�� ã���ִ� �Լ�
void initialize_EPItable();//���������� ����� PrimeImplicant�� �������� EPItable�迭�� �ʱ�ȭ ���ִ� �Լ�
int searchPos(int num);//PrimeImplicant���� chart�� ����ִ� ���� ���Ͽ� EPItable�� ������ ��ġ�� �ప�� ��ȯ���ִ� �Լ�
void print_EPItable();//EPItable�� ����Ʈ ���ִ� �Լ�
void print_Formula();//���������� ������ Essential_PI�� �������� ������ ����Ʈ ���ִ� �Լ�
void searchEPI();//EPItable���� �� �Ѱ��� ���� ������ �ִ� ���� ã�Ƴ��� Essential_PI�� �߰����ִ� �Լ�
void removeImplicant();//ã�Ƴ� �ʼ� ������ �������� table���� �������ְ� �߰��� �� �ִ� ���� �ִٸ� Essential_PI�� �߰����ִ� �Լ�
void removeAll(int y);//�ప�� ���ڷ� �޾� EPItable���� ���ڷ� ���� �࿡ ���� �ִٸ� �� ���� ������ �� �������ִ� �Լ�
