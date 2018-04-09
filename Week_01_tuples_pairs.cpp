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
		tie(lhs.year, lhs.month, lhs.day);//tie ������� ������ ������� ������ ������
	auto rhs_key=tie(rhs.year, rhs.month, rhs.day);
	//lhs_key + rhs_key;
	return lhs_key < rhs_key;
}

class Cities{//���������� �� ������ (�������) �������� �������� � ������� �������
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
	

	
	//������
	auto t = make_tuple(7, "C++", true);//�������� �������
	tuple<int, string, bool>tt(7, "C++", true);//�������� �������
	//tuple t(7, "C++", true);// �������� ������� � ��������� C++17, ��� ��������� ����������
	cout << get<1>(t);//����� ����� ������� <0> - ������� ���� ������� t
	

	/*
	//����
	pair<int, string>q(7, "C++");//���������� ����
	cout << q.first << " " << q.second << endl;
	auto p = make_pair(7, "C++");//���������� ����, ���� ���� first and second
	cout << p.first << " " << p.second << endl;
	map<int, string>digits = { {1,"one"},{2,"two"},{3,"three"},{4,"four"} };
	for (auto item : digits) {
		cout << item.first << " " << item.second << endl;
	}
	for (const pair<int, string>& item : digits) {//map ��� ����, �� ���� ����� ������ auto ������ pair
		cout << item.first << " " << item.second << endl;
	}
	*/
	
	/*
	Cities cities;  //���������� �� ������ (�������) �������� �������� � ������� �������
	bool success;   //��������� ���������� ��� �������� ����������
	string message; //������ ������ FindCountry
	tie(success, message) = cities.FindCountry("Volgograd");    //��������� ���������� ���������� tie
																//� ����������� �� �������� ��������� ������ ������� FindCountry
																//tie ������� ������ ������� ������ ������, ��������� ����� ��
																//����� ��������� � ��������� ���������� ������� ������ ����� FindCountry
	//auto[success, message] = cities.FindCountry("Volgograd"); //� ����� ��������� ����� ����������� �������� ���������� success and message
	cout << success << " " << message << endl;
	*/

	/* 
	// ������� � ���� ���� ������������ ���������, ��� ����� ������ ���������� ����
	map<string, pair<double, double>>cities;
	for (const auto& item : cities) {
		cout << item.second.first << endl; //������������� ��� ����� �� ���� ��������� ���� ���, �������� ����� � ����
	}
	*/

	return 0;
}