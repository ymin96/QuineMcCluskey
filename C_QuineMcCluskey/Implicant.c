#include "Implicant.h"

void initialize(Implicant* ip, int num) {//Implicant변수를 초기화 하는 함수로써 초기화할 Implicant변수의 주소와 10진수 num값을 인자로 받으면 10진수 num을 분석하여 자동으로 Implicant변수값을 채워주는 함수 
	ip->check = 0;
	memcpy(ip->bit, tenCoverTwo(num), sizeof(ip->bit));
	ip->oneBitCount = countOneBit(ip->bit);
	for (int i = 0; i < 100; i++)
		ip->chart[i] = -1;
	ip->chart[0] = num;
	ip->length = get_length(ip->chart);
}
void initializes_all(Implicant*ip, int _oneBitCount, int _check, char _bit[], int _chart[]) {//Implicant변수를 초기화 하는 함수로써 초기화할 Implicant변수의 주소와 Implicant변수의 값을 대부분 받아와 복제해주는 역할의 함수
	ip->check = _check;
	ip->oneBitCount = _oneBitCount;
	memcpy(ip->bit, _bit, sizeof(ip->bit));
	memcpy(ip->chart, _chart, sizeof(ip->chart));
	ip->length = get_length(ip->chart);
}
int compareTo(Implicant ip1, Implicant ip2) {//Implicant변수의 bit값을 비교해주는 함수 만약 비트값이 단 1개만 다를경우 1(true)를 리턴 아닐경우 0(false)를 리턴해주는 함수
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (ip1.bit[i] != ip2.bit[i])
			count++;
	}
	if (count == 1)
		return 1;
	else
		return 0;
}
int countOneBit(char _bit[]) { //char형 배열을 인자로 받아 '1'비트가 몇개 있는 체크하여 그 수만큼 리턴해주는 함수
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (_bit[i] == '1')
			count++;
	}
	return count;
}
char* tenCoverTwo(int _num) {//10진수 값을 입력받아 2진수로 변환해주는 함수 리턴값은 char형 배열을 리턴하기때문에 char*형
	int result = 0;
	char ch[5] = { '0','0','0','0'};
	int check = 3;
	for (int i = 1; _num>0; i *= 10)
	{
		int binary = _num % 2;
		result += binary * i;
		_num /= 2;
		ch[check--] = binary + '0';
	}
	return ch;
}
int get_length(int chart[]) {//chart배열의 실질적 값을 리턴해주는 함수 chart배열을 -1로 초기화 하기 때문에 -1이 나오지 않을때까지 카운팅을 하여 카운팅 한 값을 반환해주는 함수
	int count = 0;
	for (int i = 0; chart[i] != -1; i++)
		count++;
	return count;
}