#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    
    int worst = 50000;
    int second = 50000;
    for (int i = 0; i < N; i++)
    {
        if(a[i] < second) {
            second = a[i];
        }

        if(a[i] < worst) {
            second = worst;
            worst = a[i];
        }
    }

    cout << second << endl;
    return 0;
}
