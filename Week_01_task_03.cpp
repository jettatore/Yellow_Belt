#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

/*
enum class Lang {
	DE,FR,IT
};

struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

bool operator<(const Region& lhs, const Region& rhs) {
	return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
		tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	int count(0);
	map<Region, int>counted;
	for (auto region : regions) {
		count = max(count, ++counted[region]);
	}
	return count;
};
*/

enum class Lang {
	DE, FR, IT
};

struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

bool operator<(Region const & lhs, Region const & rhs) {
	auto lhs_key = tie(lhs.std_name,lhs.parent_std_name,lhs.names,lhs.population);
	auto rhs_key = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
	return lhs_key < rhs_key;
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	int count(0);
	map<Region, int>counted;
	for (auto region : regions) {
		count = max(count, ++counted[region]);
	}
	return count;
};

int main() {
	
	cout << FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Russia",
			"Eurasia",
		{ { Lang::DE, "Russland" },{ Lang::FR, "Russie" },{ Lang::IT, "Russia" } },
		89
		},{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Russia",
			"Eurasia",
		{ { Lang::DE, "Russland" },{ Lang::FR, "Russie" },{ Lang::IT, "Russia" } },
		89
		},
		}) << endl;

	cout << FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Russia",
			"Eurasia",
		{ { Lang::DE, "Russland" },{ Lang::FR, "Russie" },{ Lang::IT, "Russia" } },
		89
		},{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou deux" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Moscow",
			"Toulouse",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		31
		},
		}) << endl;
	
	return 0;
}
