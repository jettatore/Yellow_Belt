#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {
	int n(0), r(0), w(0), h(0), d(0);
	uint64_t result(0);
	cin >> n >> r;
	for (size_t i = 0; i < n; ++i) {
		cin >> w >> h >> d;
		result += static_cast<uint64_t>(w)*h*d;
	}
	result *= r;
	cout << result << endl;
	
	return 0;
}
