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
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                len++;
            }
        }
        if (len)
        {
            int time = len / 2;
            cout << time << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}