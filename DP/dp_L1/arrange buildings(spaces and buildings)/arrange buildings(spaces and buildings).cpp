//https://nados.io/question/arrange-buildings
//april 4 by sumit sir


#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int dp[n+1][2];
    
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=1;
    dp[1][1]=1;
    
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
    }
long count=dp[n][0]+dp[n][1];
count*=count;
cout<<count;
}
