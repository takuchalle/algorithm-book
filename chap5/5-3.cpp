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

    for (int i = 0; i < N; i++)
    {
        if(a[i] <= N) {
            dp[i + 1][a[i]] = true;
        }

        for (int j = 0; j <= W; j++)
        {
            if(dp[i][j]) {
                dp[i + 1][j] = true;
                if(j + a[i] <= W) {
                    dp[i + 1][j + a[i]] = true;
                }
            }
        }
    }

    int count = 0;
    for (size_t i = 0; i <= W; i++)
    {
        if(dp[N][i]) {
            count++;
        }
    }

    cout << count << endl;    

    return 0;
}
