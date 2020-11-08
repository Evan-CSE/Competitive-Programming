#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


/*WA*/

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,nws;
		int a,b;
		cin>>a>>b;
		cin>>s;
		nws = s;
		int l = s.size(),onlyA = 0;
		for(int i=0;i<l;i++)
		{
			if(s[i]=='1')
			{
				onlyA+=a;
				while(s[i]=='1' && i<l)
				{
					i++;
				}
				i--;
			}
		}
		int AB = 0;
		for(int i=0;i<l;i++)
		{
			if(s[i]=='1')
			{
				while(s[i]=='1' && i<l)
					i++;
			
				AB+=a;
				//cout<<AB<<" .....\n";
			}
			if(i>0 && i<l-1 && s[i]=='0' & s[i+1]=='1')
			{
				AB = min(AB+b,AB+a);
				i++;
				while(i<l && s[i]=='1')
				{
					i++;
				}
				i--;
			}
		}
		cout<<min(AB,onlyA)<<endl;
	}
	return 0;
}