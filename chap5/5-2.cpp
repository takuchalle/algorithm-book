#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    // 
    vector<vector<bool> > dp(N + 1, vector<bool>(W + 1, false));

    dp[0][0] = true;

    for (int i = 0; i < N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // i を選ばない場合
            dp[i + 1][w] = dp[i + 1][w] | dp[i][w];

            // i を選ぶ場合
            if(w - a[i] >= 0) 
                dp[i + 1][w] = dp[i + 1][w] | dp[i][w - a[i]];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    cout << dp[N - 1][W - 1] << endl;

    return 0;
}
