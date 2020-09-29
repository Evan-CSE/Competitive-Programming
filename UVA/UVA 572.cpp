/**Assala mu alaikum....
In this problem we'll have to consider those elements containing '@' and count number of connected component... Connected component is a
sub graph where is vertexes are connected in a such a way that we can traverse from any node to other node,,.... so connected component
will be considered as a single oil containing box (mentioned on problem statement) ..but a single vertex with '@' which is not a connected
component will also be counted...
Md Hasibur Rahman (Evan)
Jatiya Kabi Kazi Nazrul Islam University, Trishal , Mymensingh
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();
ll m,n,c=0,r,cl;
bool visit[100][100];
char a[100][100];
void flood(ll row, ll column) /**AC*/
{
    if(row<0 || column<0 || visit[row][column]==true || row>=m|| column>=n)
        return ;
    else
    {
        if(a[row][column]=='@' && visit[row][column]==false)
        {
            visit[row][column]=true;
            flood(row,column+1);
            flood(row,column-1);
            flood(row+1,column);
            flood(row-1,column);
            flood(row+1,column+1);
            flood(row+1,column-1);
            flood(row-1,column+1);
            flood(row-1,column-1);
        }

    }

}

int main()
{
    fast;
    //freopen("input.txt","r",stdin);
    while(1)
    {
        cin>>m>>n;
        if(m==0)
            break;
        for(ll i=0; i<100; i++)
            for(ll j=0; j<100; j++)
                a[i][j]='0';
        for(ll i=0; i<100; i++)
            for(ll j=0; j<100; j++)
                visit[i][j]=false;
        for(ll i=0; i<m; i++)
        {
            for(ll j=0; j<n; j++)
            {
                char c;
                cin>>c;
                if(c=='@')
                {
                    r=i;
                    cl=j;
                }
                a[i][j]=c;
            }
        }
        c=0;
        for(ll i=0; i<m; i++)
            for(ll j=0; j<n; j++)
            {
                if(a[i][j]=='@' && !visit[i][j])
                {
                    flood(i,j);
                    c++;
                }
            }
        cout<<c<<"\n";
    }

    return 0;
}

