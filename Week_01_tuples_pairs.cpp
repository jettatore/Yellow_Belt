#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<tuple>
#include<map>
#include<set>

using namespace std;

struct  Date {
	int year;
	string month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	tuple<const int&, const string&, const int&>lhs_key =
		tie(lhs.year, lhs.month, lhs.day);//tie создает кортеж который хранит ссылки
	auto rhs_key=tie(rhs.year, rhs.month, rhs.day);
	//lhs_key + rhs_key;
	return lhs_key < rhs_key;
}

class Cities{//Возвращаем из метода (функции) нескоько значений с помощью кортежа
public:
	tuple<bool,string> FindCountry(
		const string& city)const {
		if (city_to_country.count(city) == 1) {
			return{ true,city_to_country.at(city) };
		}
		else if(ambiguous_cities.count(city)==1) {
			return{ false,"Ambiguous" };
		}
		else return{ false,"Not exist" };
};

private:
	map<string, string>city_to_country;
	set<string>ambiguous_cities;
};

int main() {

	
	cout << (Date{ 2017,"June",8 } < Date{ 2017,"January",26 }) << endl;
	

	
	//Кортеж
	auto t = make_tuple(7, "C++", true);//создание кортежа
	tuple<int, string, bool>tt(7, "C++", true);//создание кортежа
	//tuple t(7, "C++", true);// создание кортежа в стандарте C++17, без шаблонных параметров
	cout << get<1>(t);//вывод полей кортежа <0> - нулевое поле кортежа t
	

	/*
	//Пара
	pair<int, string>q(7, "C++");//объявление пары
	cout << q.first << " " << q.second << endl;
	auto p = make_pair(7, "C++");//объявление пары, есть поля first and second
	cout << p.first << " " << p.second << endl;
	map<int, string>digits = { {1,"one"},{2,"two"},{3,"three"},{4,"four"} };
	for (auto item : digits) {
		cout << item.first << " " << item.second << endl;
	}
	for (const pair<int, string>& item : digits) {//map это пара, то есть можно вместо auto писать pair
		cout << item.first << " " << item.second << endl;
	}
	*/
	
	/*
	Cities cities;  //Возвращаем из метода (функции) нескоько значений с помощью кортежа
	bool success;   //объявляем переменные для хранения результата
	string message; //работы метода FindCountry
	tie(success, message) = cities.FindCountry("Volgograd");    //Связываем переменные оператором tie
																//и присваиваем им значения резльтата работа функции FindCountry
																//tie создает кортеж который хранит ссылки, благодаря этому мы
																//можем сохранять в связанные переменные которые вернул метод FindCountry
	//auto[success, message] = cities.FindCountry("Volgograd"); //В новом стандарте можно необъявлять отдельно переменные success and message
	cout << success << " " << message << endl;
	*/

	/* 
	// Кортежы и пары надо использовать аккуратно, они часто мешают читаемости кода
	map<string, pair<double, double>>cities;
	for (const auto& item : cities) {
		cout << item.second.first << endl; //использование пар часто не дает понимание того что, имеллось здесь в виду
	}
	*/

	return 0;
}