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
    int best = -50000;
    for (int i = 0; i < N; i++)
    {
        if(a[i] < worst) {
            worst = a[i];
        }

        if(best < a[i]) {
            best = a[i];
        }
    }

    cout << best - worst << endl;
    return 0;
}
