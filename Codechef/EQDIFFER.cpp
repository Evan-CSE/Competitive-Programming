#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, mx = INT_MIN;
        map<int, int> mp;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
            mx = max(mx, mp[v[i]]);
        }
        if (n <= 2)
        {
            cout << "0\n";
            continue;
        }
        mx == 1 ? cout << n - 2 << endl : cout << n - mx << endl;
    }
    return 0;
}