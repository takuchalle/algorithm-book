#include <iostream>
#include <vector>

using namespace std;

int32_t tribonacci(int32_t N)
{
    if (N == 0 || N == 1)
        return 0;
    if (N == 2)
        return 1;

    return tribonacci(N - 1) + tribonacci(N - 2) + tribonacci(N - 3);
}

int main()
{
    int N;
    cin >> N;

    cout << tribonacci(N) << endl;
    return 0;
}
