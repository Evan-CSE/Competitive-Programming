#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define FI freopen("input.txt","r",stdin)
#define FO freopen("output.txt","w",stdout)
#define fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();
vector<ll>graph[MAX];
bool visit[MAX];

int main()
{
    map<string,int>dic;
    char ch;
    string s;
    int l=0;
    FI;
    //FO;
    while(scanf("%c",&ch)==1)
    {
        if(ch==EOF)
            break;
        if(!isalpha(ch))
        {
            dic[s]=l;
            //cout<<"l er value "<<l<<"\n";
            s.clear();
            l++;
            continue;
        }
        else if(isalpha(ch))
         {
             if(ch>='A' && ch<='Z')
                ch=ch-'A'+'a';
             s+=ch;
         }
    }
    auto it=dic.begin();
    it++;
    for(it;it!=dic.end();it++)
        cout<<it->first<<endl;
    return 0;
}


