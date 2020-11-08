#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
	int n,sum=0,x;
	cin>>n;
	for(int i=0;i<n;i++)cin>>x,sum+=x;
	sum%n?cout<<"NO\n":cout<<"YES\n";
	return 0;
}