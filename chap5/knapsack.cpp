#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<class T>
void chmax(T& a, T b) {
    if(a < b) {
        a = b;
    }
}

int main()
{
    int N, W;
    cin >> N >> W;

    vector<int64_t> weight(N), value(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }
    
    vector<vector<int64_t> > dp(N + 1, vector<int64_t>(W + 1, 0));

    for (int64_t i = 0; i < N; i++)
    {
        for (int64_t w = 0; w <= W; w++)
        {
            if(w - weight[i] >= 0) {
                chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
            }

            chmax(dp[i + 1][w], dp[i][w]);
        }
    }
    



    cout << dp[N][W] << endl;

    return 0;
}
