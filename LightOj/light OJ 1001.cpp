#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        scanf("%d",&n);
        printf("%d %d\n",n/2,n-(n/2));
    }
    return 0;
}
