#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Implicant {                    //���� ǥ���ϴ� ����ü�� 4��Ʈ ����, '1'��Ʈ�� ����,  �׵��� ������ �˷��� �迭, ���տ� ��� ���θ� �˷��ִ� �������� �ִ�.
	int oneBitCount,check,length;             //oneBitCount�� '1'��Ʈ�� ������ ��Ÿ���� ����, check ������ �� ���� ���տ� ���ƴ��� �˷��ش�, length�� chart�迭�� �������� ���̸� ��Ÿ����
	char bit[5];                              //�Է¹��� 10������ 2������ �ٲٸ� ���ڷ� �ٲپ��� char�迭�� �־��ֱ⶧���� �ʿ��� ����
	int chart[100];                           //�� ���� � �׵��� �������� ����������� �˷��� �迭����
}Implicant;

void initialize(Implicant* ip, int num);      //Implicant������ �ʱ�ȭ �ϴ� �Լ��ν� �ʱ�ȭ�� Implicant������ �ּҿ� 10���� num���� ���ڷ� ������ 10���� num�� �м��Ͽ� �ڵ����� Implicant�������� ä���ִ� �Լ� 
void initializes_all(Implicant*ip, int _oneBitCount, int _check, char _bit[], int _chart[]);     //Implicant������ �ʱ�ȭ �ϴ� �Լ��ν� �ʱ�ȭ�� Implicant������ �ּҿ� Implicant������ ���� ��κ� �޾ƿ� �������ִ� ������ �Լ�
int compareTo(Implicant ip1, Implicant ip2);  //Implicant������ bit���� �����ִ� �Լ� ���� ��Ʈ���� �� 1���� �ٸ���� 1(true)�� ���� �ƴҰ�� 0(false)�� �������ִ� �Լ�
int countOneBit(char _bit[]);                 //char�� �迭�� ���ڷ� �޾� '1'��Ʈ�� � �ִ� üũ�Ͽ� �� ����ŭ �������ִ� �Լ�
int get_length(int chart[]);                  //chart�迭�� ������ ���� �������ִ� �Լ� chart�迭�� -1�� �ʱ�ȭ �ϱ� ������ -1�� ������ ���������� ī������ �Ͽ� ī���� �� ���� ��ȯ���ִ� �Լ�
char* tenCoverTwo(int _num);                  //10���� ���� �Է¹޾� 2������ ��ȯ���ִ� �Լ� ���ϰ��� char�� �迭�� �����ϱ⶧���� char*��