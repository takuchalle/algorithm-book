#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MergeSort(vector<int> &a, int left, int right) {
	if(right - left == 1) return;

	// int mid = (right + left) / 2;
	int mid = left + (right - left) / 2;

	MergeSort(a, left, mid);

	MergeSort(a, mid, right);

	vector<int> buf;
	for(int i = left; i < mid; ++i) buf.push_back(a[i]);
	for(int i = right - 1; i >= mid; --i) buf.push_back(a[i]);

	int index_left = 0;
	int index_right = (int)buf.size() - 1;

	for(int i = left; i < right; ++i) {
		if(buf[index_left] < buf[index_right]) {
			a[i] = buf[index_left++];
		} else {
			a[i] = buf[index_right--];
		}
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

	MergeSort(a, 0, N);

	printArray(a);

	return 0;
}
