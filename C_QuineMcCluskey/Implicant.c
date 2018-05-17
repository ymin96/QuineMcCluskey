#include "Implicant.h"

void initialize(Implicant* ip, int num) {//Implicant������ �ʱ�ȭ �ϴ� �Լ��ν� �ʱ�ȭ�� Implicant������ �ּҿ� 10���� num���� ���ڷ� ������ 10���� num�� �м��Ͽ� �ڵ����� Implicant�������� ä���ִ� �Լ� 
	ip->check = 0;
	memcpy(ip->bit, tenCoverTwo(num), sizeof(ip->bit));
	ip->oneBitCount = countOneBit(ip->bit);
	for (int i = 0; i < 100; i++)
		ip->chart[i] = -1;
	ip->chart[0] = num;
	ip->length = get_length(ip->chart);
}
void initializes_all(Implicant*ip, int _oneBitCount, int _check, char _bit[], int _chart[]) {//Implicant������ �ʱ�ȭ �ϴ� �Լ��ν� �ʱ�ȭ�� Implicant������ �ּҿ� Implicant������ ���� ��κ� �޾ƿ� �������ִ� ������ �Լ�
	ip->check = _check;
	ip->oneBitCount = _oneBitCount;
	memcpy(ip->bit, _bit, sizeof(ip->bit));
	memcpy(ip->chart, _chart, sizeof(ip->chart));
	ip->length = get_length(ip->chart);
}
int compareTo(Implicant ip1, Implicant ip2) {//Implicant������ bit���� �����ִ� �Լ� ���� ��Ʈ���� �� 1���� �ٸ���� 1(true)�� ���� �ƴҰ�� 0(false)�� �������ִ� �Լ�
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
int countOneBit(char _bit[]) { //char�� �迭�� ���ڷ� �޾� '1'��Ʈ�� � �ִ� üũ�Ͽ� �� ����ŭ �������ִ� �Լ�
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (_bit[i] == '1')
			count++;
	}
	return count;
}
char* tenCoverTwo(int _num) {//10���� ���� �Է¹޾� 2������ ��ȯ���ִ� �Լ� ���ϰ��� char�� �迭�� �����ϱ⶧���� char*��
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
int get_length(int chart[]) {//chart�迭�� ������ ���� �������ִ� �Լ� chart�迭�� -1�� �ʱ�ȭ �ϱ� ������ -1�� ������ ���������� ī������ �Ͽ� ī���� �� ���� ��ȯ���ִ� �Լ�
	int count = 0;
	for (int i = 0; chart[i] != -1; i++)
		count++;
	return count;
}