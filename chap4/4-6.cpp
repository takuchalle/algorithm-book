#include <iostream>
#include <vector>

using namespace std;

int32_t func(int i, int w, const vector<int32_t> &a, vector<vector<int32_t > > &memo)
{
    if(i == 0) {
        if(w==0) return 1;
        else return 0;
    }

    if (memo[i][w] != -1)
        return memo[i][w];

    if (func(i - 1, w - a[i - 1], a, memo))
        return memo[i][w] = 1;

    if (func(i - 1, w, a, memo))
        return memo[i][w] = 1;

    return memo[i][w] = 0;
}

int main()
{
    int N, W;
    cin >> N >> W;

    vector<int> a(N);
    for (size_t i = 0; i < N; i++)
        cin >> a[i];

    vector<vector<int32_t > > memo(N + 1, vector<int32_t>(W + 1, -1));

    cout << func(N, W, a, memo) << endl;

    return 0;
}
