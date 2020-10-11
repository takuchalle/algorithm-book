#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> K >> N;

    int count = 0;
    for (size_t X = 0; X <= K; X++)
    {
        for (size_t Y = 0; Y <= K; Y++)
        {
            size_t Z = N - X - Y;
            if(0 <= Z && Z <= K) {
                cout << X << "+" << Y << "+" << Z << "=" << N << endl;
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
