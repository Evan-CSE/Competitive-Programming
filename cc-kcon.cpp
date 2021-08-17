#include <bits/stdc++.h>

using namespace std;

int maxSubArraySum(vector<int> v, int l)
{
    int ans = INT_MIN, cur_sum = v[0];
    for (int i = 1; i < l; i++)
    {
        cur_sum = max(cur_sum + v[i], v[i]);
        ans = max(ans, cur_sum);
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int l;
    cin >> l;
    vector<int> v(l);
    for (int i = 0; i < l; i++)
    {
        cin >> v[i];
    }
    cout << maxSubArraySum(v, l) << endl;
    return 0;
}