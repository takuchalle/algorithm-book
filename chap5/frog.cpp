#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const uint64_t INF = 1LL << 60;

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
        if(i == 1) dp[i] = abs(h[0] - h[1]);
        dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]), dp[i - 2] + abs(h[i - 2] - h[i]));
    }

    cout << dp[N - 1] << endl;

    return 0;
}
