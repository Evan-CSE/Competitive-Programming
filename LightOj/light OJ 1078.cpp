#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,number,cnt=0,flag=0,i=0,remainder;
    char digit;
    cin>>T;
    while(T--)
    {
        i++;
        cnt=0;
        cin>>number>>digit;
        remainder=0;
        flag=0;
        printf("Case %d: ",i);
        for(int i=0;flag!=1;i++)
        {

            remainder=((remainder*10)+digit-'0')%number;
            cnt++;
            if(remainder==0)
            {
                flag=1;
                cout<<cnt<<endl;
            }
        }
    }
    return 0;
}
/**Implemented by Evan
