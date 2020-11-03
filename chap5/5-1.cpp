#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    // 0: 泳ぐ, 1: 虫取り, 2: 宿題
    const int A = 3;
    int N;
    cin >> N;

    vector<vector<int> > h(N, vector<int>(A, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < A; j++)
        {
            cin >> h[i][j];
        }
    }

    // i 日目に行動 j を行った時に最大化する DP
    vector<vector<int> > dp(N, vector<int>(A, 0));

    // 初日は前日の影響を受けないので初期化する
    dp[0][0] = h[0][0];
    dp[0][1] = h[0][1];
    dp[0][2] = h[0][2];

    // 連続で同じ行動を行えないので、前日の異なる行動の最大数に当日の行動を足して、大きい方を採用する
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = max(dp[i-1][1] + h[i][0], dp[i-1][2] + h[i][0]);
        dp[i][1] = max(dp[i-1][0] + h[i][1], dp[i-1][2] + h[i][1]);
        dp[i][2] = max(dp[i-1][0] + h[i][2], dp[i-1][1] + h[i][2]);
    }

    // 3つの行動のなかのどの行動でも良いので、この中の最大値を得る
    cout << max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])) << endl;

    return 0;
}
