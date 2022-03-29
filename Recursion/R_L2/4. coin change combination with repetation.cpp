#include<iostream>
#include<vector>
#include<string>
using namespace std;

int coinc(int i, int amt, vector<int>coins, int amtsf)
{
    if(i==coins.size())
    {
        if(amt==amtsf)
        {
            
            return 1;
        }
        else
        {
            
            return 0;
        }
    }
    int ans=0;
    for(int j=amt/coins[i];j>=1;j--)
    {
        
        ans+=coinc(i+1,amt,coins,amtsf+coins[i]*j);
    }
    
   ans+=coinc(i+1,amt,coins,amtsf);
   return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int amt;
    cin>>amt;
    
    
    cout<<coinc(0,amt,v,0);
}
