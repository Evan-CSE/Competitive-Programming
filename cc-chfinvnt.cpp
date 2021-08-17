#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, p;
        cin >> n >> p >> k;
        if (k >= n)
        {
            cout << (p % k) + 1 << endl;
            continue;
        }
        ll ans = (p % k) * (n / k);
        if (n % k)
        {
            ans += (n / k) + 1;
        }
        ans += p % k ? (p / k) + 1 : p / k;
        cout << ans << endl;
    }
    return 0;
}