#include<bits/stdc++.h>
using namespace std;
int remainder(char a[1000000],int d)
{
int    rem=0;
    for(int i=0;i<strlen(a);i++)
     rem=((rem*10)+a[i]-'0')%d;
    return rem;
}
int main()
{
    int flag=1,leap=0,print=0;
    char s[1000000];
    while(scanf("%s",&s)==1)
    {
        if(print!=0)
       printf("\n");
       print=1;
       flag=1;
        leap=0;
        if(remainder(s,400)==0 || (remainder(s,100)!=0 && remainder(s,4)==0) )
        {
             printf("This is leap year.\n");
             flag=0;
             leap=1;
        }


        if(remainder(s,15)==0)
        {
            printf("This is huluculu festival year.\n");
            flag=0;
        }

        if(remainder(s,55)==0 && leap==1)
        {
             printf("This is bulukulu festival year.\n");
             flag=0;
        }

        if(flag==1)
            printf("This is an ordinary year.\n");

    }
    return 0;
}
