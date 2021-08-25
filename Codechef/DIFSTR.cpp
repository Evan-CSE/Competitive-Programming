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
        string tmp, ans = "";
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            ans += to_string(!(tmp[i] - '0'));
        }
        cout << ans << endl;
    }

    return 0;
}