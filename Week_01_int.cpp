#include<iostream>
#include<vector>
#include<limits>

using namespace std;



int main() {

	/* 
	// ������� �� ���������� ���� size_t
	vector<int>t = { -8,-7,3 };
	int sum = 0;
	for (int x : t) {
		sum += x;
	}
	int avg = sum / t.size();
	cout << avg << endl;*/

	/*
	//����� ������������� � ����������� �������� ���������� ������������� ����
	cout << sizeof(int16_t) << endl;
	cout << numeric_limits<int16_t>::min() << " " << numeric_limits<int16_t>::max();*/

	/*
	// ���������� ������� � ������������� �������� � ��������� ������� �� ������������
	cout << numeric_limits<int>::max() + 1 << " " <<
		numeric_limits<int>::min() - 1 << endl;*/

	/*
	int x = 2'000'000'000;
	int y = 1'000'000'000;
	//��� �������� x � y ���������� 3'000'000'000 ������� �� ���������� � int
	cout << (x + y) / 2 << endl;
	*/

	/*
	int x = -2'000'000'000;
	unsigned int y = x;//���������� ������������ �������� � ����������� ���
	cout << x << " " << y << endl;
	*/

	/*
	vector<int>t = { -8,-7,3 };
	int sum = 0;
	for (auto x : t) {
		sum += x;
	}
	//int avg = (sum / t.size()) + vector<int>();//�������� ������ ��������� ��� �� ������ � ���� ��������� ��������� ���������
	*/

	int x = -1;
	unsigned int y = 1;
	cout << (x < y) << endl;//false �.�. ��������� ���������� � unsign
	cout << (-1 < 1u) << endl;//��� ����������� unsign ������������ ����� u

	getchar();
	return 0;
}