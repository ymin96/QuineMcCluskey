#include "Implicant.h"

void initialize(Implicant* ip, int num) {
	ip->check = 0;
	memcpy(ip->bit, tenCoverTwo(num), sizeof(ip->bit));
	ip->oneBitCount = countOneBit(ip->bit);
	for (int i = 0; i < 100; i++)
		ip->chart[i] = -1;
	ip->chart[0] = num;
	ip->length = get_length(ip->chart);
}
void initializes_all(Implicant*ip, int _oneBitCount, int _check, char _bit[], int _chart[]) {
	ip->check = _check;
	ip->oneBitCount = _oneBitCount;
	memcpy(ip->bit, _bit, sizeof(ip->bit));
	memcpy(ip->chart, _chart, sizeof(ip->chart));
	ip->length = get_length(ip->chart);
}
int compareTo(Implicant ip1, Implicant ip2) {
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
int countOneBit(char _bit[]) {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (_bit[i] == '1')
			count++;
	}
	return count;
}
char* tenCoverTwo(int _num) {
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
int get_length(int chart[]) {
	int count = 0;
	for (int i = 0; chart[i] != -1; i++)
		count++;
	return count;
}