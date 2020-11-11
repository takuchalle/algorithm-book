#include <iostream>

using namespace std;

int main() {
	cout << "Start Game" << endl;
	
	int left = 20, right = 36;

	while(right - left > 1) {
		int mid = left + (right	- left) / 2;
		
		cout << "Is the age less than " << mid << " ? (Yes/No)" << endl;
		string ans;
		cin >> ans;

		if(ans == "yes") right = mid;
		else left = mid;
	}

	cout << "The age is " << left << "!" << endl;

	return 0;
}

