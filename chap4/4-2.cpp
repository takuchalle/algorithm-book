#include <iostream>
#include <vector>

using namespace std;

int32_t tribonacci(int32_t N, vector<int32_t> &memo)
{
    if (N == 0 || N == 1)
        return 0;
    if (N == 2)
        return 1;

    if (memo[N] != -1)
    {
        return memo[N];
    }

    return memo[N] = tribonacci(N - 1, memo) + tribonacci(N - 2, memo) + tribonacci(N - 3, memo);
}

int main()
{
    int N = 4;
    cin >> N;

    vector<int32_t> memo(N + 1, -1);

    cout << tribonacci(N, memo) << endl;
    return 0;
}
