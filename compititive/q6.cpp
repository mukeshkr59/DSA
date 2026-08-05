#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int m;
        cin >> n >> m;
        int sum = 0;
        vector<int> A(n);
        vector<int> B(m);
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            A[i] = a;
            sum += a;
        }
        // sum = abs(sum);
        for (int i = 0; i < m; i++)
        {
            int b;
            cin >> b;
            B[i] = b;
        }
        int j = 0;
        while (j < m)
        {
            int sum1 = 0;
            int x = B[j];

            for (int i = 0; i < n; i++)
            {
                if (x--)
                {
                    sum1 += (-A[i]);
                }
                else
                {
                    sum1 += A[i];
                }
            }
            sum = max(sum, abs(sum1));
            j++;
        }
        cout << sum << endl;
    }
    return 0;
}