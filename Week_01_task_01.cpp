#include<iostream>
#include<vector>

using namespace std;

int main() {
	uint32_t n(0), count(0);
	int64_t sum(0), temperature(0);
	cin >> n;
	vector<int64_t>t(n);
	for (int64_t& temperature : t) {
		cin >> temperature;
		sum += temperature;
	}
	int32_t avg = sum / n;
	for (size_t i = 0; i < n; i++) {
		if (t[i] > avg)count++;
	}
	cout << count << endl;
	for (size_t i = 0; i < n; i++) {
		if (t[i] > avg)cout << i << " ";
	}

	return 0;
}