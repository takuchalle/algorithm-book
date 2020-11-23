#include <iostream>
#include <string>
#include <vector>

using namespace std;

void QuickSort(vector<int> &a, int left, int right) {
	if(right - left <= 1) return;

	int pivot_index = left + (right - left) / 2;
	int pivot = a[pivot_index];
	swap(a[pivot_index], a[right - 1]);

	int i = left;
	for(int j = left; j < right - 1; ++j) {
		if(a[j] < pivot) {
			swap(a[i++], a[j]);
		}
	}
	swap(a[i], a[right - 1]);

	QuickSort(a, left, i);
	QuickSort(a, i + 1, right);
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

	QuickSort(a, 0, N);

	printArray(a);

	return 0;
}
