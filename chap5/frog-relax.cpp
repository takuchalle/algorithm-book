#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const uint64_t INF = 1LL << 60;

template<class T>
void chmin(T& a, T b) {
    if(a > b) {
        a = b;
    }
}

int main()
{
    int N;
    cin >> N;

    vector<int64_t> h(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> h[i];
    }
    
    vector<int64_t> dp(N, INF);

    dp[0] = 0;

    for (size_t i = 1; i < N; i++)
    {
        chmin(dp[i], dp[i - 1] + abs(h[i - 1] - h[i]));

        if(i > 1) {        
            chmin(dp[i], dp[i - 2] + abs(h[i - 2] - h[i]));
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}
