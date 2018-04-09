#include<iostream>
#include<vector>
#include<limits>

using namespace std;



int main() {

	/* 
	// деление на переменную типа size_t
	vector<int>t = { -8,-7,3 };
	int sum = 0;
	for (int x : t) {
		sum += x;
	}
	int avg = sum / t.size();
	cout << avg << endl;*/

	/*
	//вывод максимального и мнимального значения переменной определенного типа
	cout << sizeof(int16_t) << endl;
	cout << numeric_limits<int16_t>::min() << " " << numeric_limits<int16_t>::max();*/

	/*
	// прибаление единицы к максимальному значению и вычитание единицы из минимального
	cout << numeric_limits<int>::max() + 1 << " " <<
		numeric_limits<int>::min() - 1 << endl;*/

	/*
	int x = 2'000'000'000;
	int y = 1'000'000'000;
	//при сложении x и y получилось 3'000'000'000 которое не уместилось в int
	cout << (x + y) / 2 << endl;
	*/

	/*
	int x = -2'000'000'000;
	unsigned int y = x;//записываем отрицательно значение в беззнаковый тип
	cout << x << " " << y << endl;
	*/

	/*
	vector<int>t = { -8,-7,3 };
	int sum = 0;
	for (auto x : t) {
		sum += x;
	}
	//int avg = (sum / t.size()) + vector<int>();//вызываем ошибку компиляци что бы узанть к чему приводтся результат выражения
	*/

	int x = -1;
	unsigned int y = 1;
	cout << (x < y) << endl;//false т.к. выражение приведется в unsign
	cout << (-1 < 1u) << endl;//для обозначения unsign используется буква u

	getchar();
	return 0;
}