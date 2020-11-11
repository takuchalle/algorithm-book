#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 200000000;

int main() {

	int N, K;
	cin >> N >> K;
	vector<int> a(N), b(N);

	for(int i = 0; i < N; ++i) cin >> a[i];
	for(int i = 0; i < N; ++i) cin >> b[i];

	int min_value = INF;

	sort(b.begin(), b.end());

	for(int i = 0; i < N; ++i) {
		auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

		int val = *iter;

		if(a[i] + val < min_value) {
			min_value = a[i] + val;
		}
	}
	cout << min_value << endl;

	return 0;
}
