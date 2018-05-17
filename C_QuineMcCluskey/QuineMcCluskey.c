#include "QuineMcCluskey.h"

void initialize_QuineMcCluskey(int arr[], int num) {   //프로그램 시작시 입력한 배열과 배열의 크기를 인자로 받으며 각종 변수들의 초기화와 PI를 추출하기 위해 merge를 해주는 함수와 추출이 다 끝나면 PI를 추출해주는 함수를 호출해준다.
	first_key = 0;
	memset(implicant, -1, sizeof(implicant));
	Implicant tmp[100];
	memset(tmp, -1, sizeof(tmp));
	for (int i = 0; i < num; i++) {
		initialize(&tmp[i], arr[i]);
	}
	groupOneBit(implicant[first_key++], tmp);
	input_length = num;
	input_number = arr;
	addSubImplicant();
	extractPI();
}
void addSubImplicant() {     //3차원 배열까지 쓰면서 for문이 너무 복잡해져 한번 간소화 해주기 위해 만들어준 함수로써 더 이상 merge가 안될때까지 merge해주는 함수를 호출해준다.
	for (int i = 0; i < first_key; i++) {
		extract(implicant[i]);
	}
}
void extract(Implicant ip[5][100]) {   //merge해주는 함수로 인접한 그룹을 비교하여 값을 비교해 알맞은 비교값이면 중복을 검사하고 중복이 없으면 임시배열에 추가한다. 최종적으로 나온 임시배열을 다시 '1'의 비트에 따라 그룹화하여 2차원 배열로 만들고 그 값을 implicant에 넣어주는 함수
	Implicant temp[100];
	memset(temp, -1, sizeof(temp));
	for (int k = 0; k < size2Dimention(ip) - 1; k++) {
		for (int i = 0; i < size1Dimention(ip[k]); i++) {
			for (int j = 0; j < size1Dimention(ip[k + 1]); j++) {
				if (compareTo(ip[k][i], ip[k + 1][j])) {
					Implicant tempip = combination(&ip[k][i], &ip[k + 1][j]);
					if (overlap(temp, tempip))
						temp[size1Dimention(temp)] = tempip;
				}
			}
		}
	}
	if (size1Dimention(temp) != 0)
		groupOneBit(implicant[first_key++], temp);
}
Implicant combination(Implicant *ip1, Implicant *ip2) {//2개의 implicant의 주소를 받아와 결합하여 새로운 Implicant를 리턴해주는 함수
	int count = 0, tcount = 0, arr[100];
	memset(arr, -1, sizeof(arr));
	char ch[5] = { '0','0','0','0' };
	for (int i = 0; ip1->chart[i] != -1; i++) {
		arr[tcount++] = ip1->chart[i];
	}
	for (int i = 0; ip2->chart[i] != -1; i++) {
		arr[tcount++] = ip2->chart[i];
	}
	for (int i = 0; i < 4; i++) {
		if (ip1->bit[i] != ip2->bit[i])
			ch[i] = '-';
		else
			ch[i] = ip1->bit[i];
		if (ch[i] == '1')
			count++;
	}
	ip1->check = 1;
	ip2->check = 1;
	Implicant ip;
	initializes_all(&ip, count, 0, ch, arr);
	return ip;
}
int overlap(Implicant arr[], Implicant ip) {//인자로 Implicant배열과 한개의 Implicant구조체를 받아 받아온 배열 안에 중복값이 있나 검사해주는 함수 중복이 없다면 1반환
	for (int i = 0; i < size1Dimention(arr); i++) {
		if (strcmp(arr[i].bit, ip.bit) == 0)
			return 0;
	}
	return 1;
}
void groupOneBit(Implicant pImplicant[5][100], Implicant ip[]) {//인자로 2차원 Implicant배열과 1차원 Implicant배열을 받아와 1차원 Implicant배열에서 '1'비트의 개수에 따라 분류하여 2차원Implicant배열에 넣어주는 함수.
	int check = 0;
	for (int i = 0; ip[i].oneBitCount != -1; i++) {
		check = 0;
		for (int j = 0; j < size2Dimention(pImplicant); j++) {
			if (ip[i].oneBitCount == pImplicant[j][0].oneBitCount) {
				pImplicant[j][size1Dimention(pImplicant[j])] = ip[i];
				check = 1;
			}
		}
		if (check == 0) {
			pImplicant[size2Dimention(pImplicant)][0] = ip[i];
		}
	}
}
void printPI() {//PItable을 순차적으로 프린트 해주는 함수
	for (int k = 0; k < first_key; k++) {
		printf("<%d번째 테이블>\n", k + 1);
		for (int i = 0; i < size2Dimention(implicant[k]); i++) {
			printf("1의 개수: %d\n", implicant[k][i][0].oneBitCount);
			for (int j = 0; j < size1Dimention(implicant[k][i]); j++) {
				for (int l = 0; implicant[k][i][j].chart[l] != -1; l++)
					printf("%2d ", implicant[k][i][j].chart[l]);
				printf(" | %s | %d\n", implicant[k][i][j].bit, implicant[k][i][j].check);
			}
			printf("------------------------\n");
		}
		printf("===========================\n");
	}
	printf("Prime Implicant 값\n");
	for (int i = 0; i < size1Dimention(PrimeImplicant); i++) {
		for (int j = 0; j < PrimeImplicant[0].length - PrimeImplicant[i].length; j++)
			printf("   ");
		for (int j = 0; PrimeImplicant[i].chart[j] != -1; j++)
			printf("%2d ", PrimeImplicant[i].chart[j]);
		printf(" | %s | %d\n", PrimeImplicant[i].bit, PrimeImplicant[i].check);
	}
	printf("\n\n");
}
int size2Dimention(Implicant ip[5][100]) {//2차원 Implicant배열의 실질적인 길이를 반환해주는 함수
	int  count = 0;
	for (int i = 0; i < 5; i++) {
		if (ip[i][0].oneBitCount != -1)
			count++;
	}
	return count;
}
int size1Dimention(Implicant ip[]) {//1차원 Implicant배열의 실질적인 길이를 반환해주는 함수 
	int count = 0;
	for (int i = 0; ip[i].oneBitCount != -1; i++)
		count++;
	return count;
}
void extractPI() {//최종적으로 만들어진 implicant배열에서 결합에 쓰지않은 즉 PrimeImplicant를 찾아주는 함수
	memset(PrimeImplicant, -1, sizeof(PrimeImplicant));
	for (int k = first_key - 1; k >= 0; k--) {
		for (int i = size2Dimention(implicant[k]) - 1; i >= 0; i--) {
			for (int j = size1Dimention(implicant[k][i]) - 1; j >= 0; j--) {
				if (implicant[k][i][j].check == 0)
					PrimeImplicant[size1Dimention(PrimeImplicant)] = implicant[k][i][j];
			}
		}
	}
}
void initialize_EPItable() {//최종적으로 추출된 PrimeImplicant를 기준으로 EPItable배열을 초기화 해주는 함수
	EPItable = (int**)malloc(sizeof(int)*size1Dimention(PrimeImplicant));
	for (int i = 0; i < size1Dimention(PrimeImplicant); i++) {
		EPItable[i] = (int*)malloc(sizeof(int)*input_length);
		memset(EPItable[i], 0, sizeof(int)*input_length);
	}
	for (int i = 0; i < input_length; i++) {
		for (int j = 0; j < PrimeImplicant[i].length; j++) {
			EPItable[i][searchPos(PrimeImplicant[i].chart[j])] = 1;
		}
	}
}
int searchPos(int num) {//PrimeImplicant에서 chart에 들어있는 값을 비교하여 EPItable의 적절한 위치의 행값을 반환해주는 함수
	for (int i = 0; i < input_length; i++) {
		if (num == input_number[i])
			return i;
	}
}
void print_EPItable() {//EPItable을 프린트 해주는 함수
	int height = size1Dimention(PrimeImplicant), width = input_length;
	for (int i = 0; i < PrimeImplicant[0].length; i++)
		printf("   ");
	printf("        ");
	for (int i = 0; i < width; i++)
		printf(" %2d", input_number[i]);
	printf("\n");
	for (int i = 0; i < PrimeImplicant[0].length + width; i++)
		printf("---");
	printf("--------\n");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < PrimeImplicant[0].length - PrimeImplicant[i].length; j++)
			printf("   ");
		for (int j = 0; PrimeImplicant[i].chart[j] != -1; j++)
			printf("%2d ", PrimeImplicant[i].chart[j]);
		printf(" | %s |", PrimeImplicant[i].bit);
		for (int j = 0; j < width; j++) {
			if (EPItable[i][j] == 0)
				printf("   ");
			else if (EPItable[i][j] == 1)
				printf(" * ");
			else if (EPItable[i][j] == 2)
				printf(" - ");
		}
		printf("\n");
	}
	printf("\n\n\n");
}
void searchEPI() {//EPItable에서 단 한개의 값만 가지고 있는 열을 찾아내여 Essential_PI에 추가해주는 함수
	memset(Essential_PI, -1, sizeof(Essential_PI));
	int height = size1Dimention(PrimeImplicant), width = input_length, count = 0, y;
	printf("필수 주항\n");
	for (int i = 0; i < width; i++) {
		count = 0;
		for (int j = 0; j < height; j++) {
			if (EPItable[j][i] == 1) {
				count++;
				y = j;
			}
		}
		if (count == 1) {
			EPItable[y][i] = 2;
			PrimeImplicant[y].check = 1;
			if (overlap(Essential_PI, PrimeImplicant[y])) {
				Essential_PI[size1Dimention(Essential_PI)] = PrimeImplicant[y];
				for (int j = 0; j < Essential_PI[0].length - Essential_PI[size1Dimention(Essential_PI) - 1].length; j++)
					printf("   ");
				for (int j = 0; Essential_PI[size1Dimention(Essential_PI) - 1].chart[j] != -1; j++)
					printf("%2d ", Essential_PI[size1Dimention(Essential_PI) - 1].chart[j]);
				printf(" | %s |\n", Essential_PI[size1Dimention(Essential_PI) - 1].bit);
			}
		}
	}
	printf("\n");
}
void removeImplicant() {//찾아낸 필수 주항을 기준으로 table값을 삭제해주고 추가할 수 있는 항이 있다면 Essential_PI에 추가해주는 함수
	int height = size1Dimention(PrimeImplicant), width = input_length;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (EPItable[i][j] == 2)
				removeAll(i);
		}
	}
	printf("추가된 주항\n");
	for (int i = 0; i < height; i++) {
		if (PrimeImplicant[i].check == 0) {
			Essential_PI[size1Dimention(Essential_PI)] = PrimeImplicant[i];
			for (int j = 0; j < Essential_PI[0].length - Essential_PI[size1Dimention(Essential_PI) - 1].length; j++)
				printf("   ");
			for (int j = 0; Essential_PI[size1Dimention(Essential_PI) - 1].chart[j] != -1; j++)
				printf("%2d ", Essential_PI[size1Dimention(Essential_PI) - 1].chart[j]);
			printf(" | %s |\n", Essential_PI[size1Dimention(Essential_PI) - 1].bit);
		}
	}
}
void removeAll(int y) {//행값을 인자로 받아 EPItable에서 인자로 받은 행에 값이 있다면 그 값의 열값을 다 삭제해주는 함수
	int height = size1Dimention(PrimeImplicant), width = input_length;
	for (int i = 0; i < width; i++) {
		if (EPItable[y][i] == 1 || EPItable[y][i] == 2) {
			for (int j = 0; j < height; j++) {
				if (EPItable[j][i] == 1 || EPItable[j][i] == 2)
					PrimeImplicant[j].check = 1;
				EPItable[j][i] = 0;
			}
		}
	}
}
void print_Formula() {//최종적으로 구해진 Essential_PI를 기준으로 공식을 프린트 해주는 함수
	printf("최종 Essential_PI\n");
	for (int i = 0; i < size1Dimention(Essential_PI); i++) {
		for (int j = 0; j < Essential_PI[0].length - Essential_PI[i].length; j++)
			printf("   ");
		for (int j = 0; Essential_PI[i].chart[j] != -1; j++)
			printf("%2d ", Essential_PI[i].chart[j]);
		printf(" | %s |\n", Essential_PI[i].bit);
	}
	printf("\n\nF = ");
	char ch[5] = { 'A','B','C','D' };
	for (int i = 0; i < size1Dimention(Essential_PI); i++) {
		for (int j = 0; j < 4; j++) {
			if (Essential_PI[i].bit[j] == '1')
				printf("%c", ch[j]);
			else if (Essential_PI[i].bit[j] == '0')
				printf("%c'", ch[j]);
		}
		if (i < size1Dimention(Essential_PI) - 1)
			printf(" + ");
	}
	printf("\n");
}