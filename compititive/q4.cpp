#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << n - i << n + 1 + 2 * i << n + 1 + 2 * i + 1;
        }
        cout << endl;
    }
    return 0;
}