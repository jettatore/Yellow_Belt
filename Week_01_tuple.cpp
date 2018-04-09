#include<iostream>
#include<vector>
#include<string>
#include<tuple>
#include<map>
#include<set>
#include<utility>

using namespace std;

class Cities {
public:
	tuple<bool, string>FindCountry(const string& city)const {
		if (city_to_country.count(city) == 1) {
			return { true,city_to_country.at(city) };
		}
		else if(ambiguous_cities.count(city)==1){
			return { false,"Ambiguous" };

		}
		else return{ false,"Mot exist" };
	}
private:
	map<string, string>city_to_country;
	set<string>ambiguous_cities;
};

int main() {
	/*
	tuple<int, string, bool>t(7, "C++", true);
	//auto t = make_tuple(7, "C++", true);
	//cout << get<1>(t) << endl;//получить элемент с индексом 1 кортежа t

	pair<int, string>p(7, "C++");//pair имеет поля first & second
	auto p1 = make_pair(7, "C++");//можно создать пару без исп-ия шаблонных параметров
	cout << p.first << " " << p.second << endl;

	map<int, string>m = { {1,"one"},{2,"two"} };
	for (auto & [key,value] : m) {//в стандарте C++17
		cout << key << " " << value << endl;
		value = "eleven";
	}
	*/

	//Cities cities;

	/*
	auto t = cities.FindCountry("Moscow");
	*/

	/*
	bool success;
	string message;
	tie(success, message) = cities.FindCountry("Vogograd");//tie хранит ссылки
	*/

	/*
	auto[success, message] = cities.FindCountry("Ibresy");
	*/

	//cout << success << " " << message << endl;



	system("pause");
	return 0;
}