#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define endl "\n"

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int arr[4], i = 0;
        set<int> st;
        while (i < 4)
        {

            cin >> arr[i];
            st.insert(arr[i]);
            // cout << "ho\n";
            i++;
        }
        // cout << "hmm";
        int sz = st.size();
        sort(arr, arr + 4);
        if (sz == 4 || sz == 3 || (sz == 2 && arr[1] == arr[0] && arr[1] != arr[2]))
        {
            cout << "2\n";
            continue;
        }
        sz == 1 ? cout << "0\n" : cout << 1 << endl;
    }
    return 0;
}