#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.length();

    uint64_t res = 0;
    for (int bit = 0; bit < (1 << (N - 1)); bit++) 
    {
        uint64_t tmp = 0;
        for (size_t i = 0; i < N - 1; i++)
        {
            tmp *= 10;
            tmp += S[i] - '0';

            if(bit & (1 << i)) {
                res += tmp;
                tmp = 0;
            }
        }
        
        tmp *= 10;
        tmp += S[N - 1] - '0';
        res += tmp;
    }
    
    cout << res << endl;
    return 0;
}
