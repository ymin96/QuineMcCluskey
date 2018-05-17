#include "QuineMcCluskey.h"

void initialize_QuineMcCluskey(int arr[], int num) {
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
}
void addSubImplicant() {
	for (int i = 0; i < first_key; i++) {
		extract(implicant[i]);
	}
}
void extract(Implicant ip[5][100]) {
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
Implicant combination(Implicant *ip1, Implicant *ip2) {
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
int overlap(Implicant arr[], Implicant ip) {
	for (int i = 0; i < size1Dimention(arr); i++) {
		if (strcmp(arr[i].bit, ip.bit) == 0)
			return 0;
	}
	return 1;
}
void groupOneBit(Implicant pImplicant[5][100], Implicant ip[]) {
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
void printPI() {
	addSubImplicant();
	extractPI();
	for (int k = 0; k < first_key; k++) {
		for (int i = 0; i < size2Dimention(implicant[k]); i++) {
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
int size2Dimention(Implicant ip[5][100]) {
	int  count = 0;
	for (int i = 0; ip[i][0].oneBitCount != -1; i++)
		count++;
	return count;
}
int size1Dimention(Implicant ip[]) {
	int count = 0;
	for (int i = 0; ip[i].oneBitCount != -1; i++)
		count++;
	return count;
}
void extractPI() {
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
void initialize_EPItable() {
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
int searchPos(int num) {
	for (int i = 0; i < input_length; i++) {
		if (num == input_number[i])
			return i;
	}
}
void print_EPItable() {
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
void searchEPI() {
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
void removeImplicant() {
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
void removeAll(int y) {
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
void print_Formula() {
	printf("최종 Essential_PI\n");
	for (int i = 0; i < size1Dimention(Essential_PI); i++) {
		for (int j = 0; j < Essential_PI[0].length - Essential_PI[i].length; j++)
			printf("   ");
		for (int j = 0; Essential_PI[i].chart[j] != -1; j++)
			printf("%2d ", Essential_PI[i].chart[j]);
		printf(" | %s |\n", Essential_PI[i].bit);
	}
	printf("\n\n최종 공식: ");
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