#include <iostream>
#include <vector>

using namespace std;

void func(int N, uint64_t cur, int use, int &counter)
{
    if (cur > N)
        return;
    if (use == 0b111)
        counter++;

    func(N, cur * 10 + 7, use | 0b100, counter);

    func(N, cur * 10 + 5, use | 0b010, counter);

    func(N, cur * 10 + 3, use | 0b001, counter);
}

int main()
{
    int N;
    cin >> N;
    int counter = 0;
    func(N, 0, 0, counter);
    cout << counter << endl;
    return 0;
}
