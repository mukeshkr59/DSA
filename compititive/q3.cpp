#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int maxi = -67;
        vector<int> arr(7);
        for (int i = 0; i < 7; i++)
        {
            int a;
            cin >> a;
            maxi = max(maxi, a);
            arr[i] = a;
        }
        int sum = 0;
        int cnt = 1;
        for (int i = 0; i < 7; i++)
        {
            if (arr[i] == maxi && cnt > 0)
            {
                sum += arr[i];
                cnt--;
            }
            else
            {
                sum -= arr[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}