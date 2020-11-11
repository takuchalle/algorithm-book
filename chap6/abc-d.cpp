#include <algorithm>
#include <iostream>
#include <vector>

using namespace	std;
const long long INF = 1LL << 60;

// x 以内に風船を割ることができるか？という問題に帰着することができる
// 二分探索法で最小の x を求めるようにしている

int main() {
	int N;
	cin >> N;
	vector<long long> h(N), s(N);
	for(int i = 0; i < N; i++) cin >> h[i] >> s[i];

	long long left = 0, right = INF;

	while(right - left > 1) {
		long long mid = (left + right)/2;

		bool ok = true;
		vector<long long> t(N, 0);
		for(int i = 0; i < N; i++) {
			if(mid < h[i]) ok = false;
			else t[i] = (mid - h[i]) / s[i];
		}

		sort(t.begin(), t.end());
		for(int i = 0; i < N; i++) {
			if(t[i] < i) ok = false;
		}

		if(ok) right = mid;
		else left = mid;

		cout << mid << endl;
	}
	cout << right << endl;
}

