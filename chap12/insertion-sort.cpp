#include <iostream>
#include <string>
#include <vector>

using namespace std;

// O(N^2)
// in-place 
// stable sort
void InsertionSort(vector<int> &a) {
	int N = (int)a.size();
	for(int i = 0; i < N; i++) {
		int v = a[i];

		int j = i;
		for(; j > 0; --j) {
			if(a[j - 1] > v) {
				a[j] = a[j - 1];
			}
			else break;
		}
		a[j] = v;
	}
}

void printArray(vector<int> &a) {
	for(auto& _a : a) {
		cout << _a << " ";
	}
	cout << endl;
}

int
main(int argc, char* argv[]) {
	int N;
	cin >> N;

	vector<int> a(N);
	for(int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	InsertionSort(a);

	printArray(a);

	return 0;
}
