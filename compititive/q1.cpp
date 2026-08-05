#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        bool okey = false;
        int tows = 0;
        for (int i = 0; i < k; i++)
        {
            long long x;
            cin >> x;
            if (x >= 3)
                okey = true;
            else if (x == 2)
                tows++;
        }
        if (okey || tows >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}