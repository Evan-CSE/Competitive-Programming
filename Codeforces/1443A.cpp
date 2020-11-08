#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,cur;
		cin>>n;
		cur = 4*n;
		for(int i=0;i<n;i++)cout<<cur<<" ",cur-=2;
			cout<<endl;
	}
	return 0;
}