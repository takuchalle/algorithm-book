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

    int m = 10000;
    for (int i = 0; i < N; i++)
    {
        int c = 0;
        int n = a[i];
        while(n%2 == 0) {
            n /= 2;
            c++;
        }
        m = std::min(m, c);
    }

    cout << m << endl;
    return 0;
}
