// Coin change permutation with no elemnet can repeat in permutation sequence

#include<bits/stdc++.h>
using namespace std;
void coinper(vector<int>coins, int amt, int amtsf, string asf,vector<bool>t)
{
    if(amtsf==amt)
    
{
    cout<<asf<<endl;
    return;
}
if(amt<amtsf)
{
    return;
}
    for(int i=0;i<coins.size();i++)
    {
        if(t[i]==false)
        {
            t[i]=true;
        string a = to_string(coins[i]);
        coinper(coins, amt, amtsf+coins[i], asf+a,t);
        t[i]=false;
        }
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int>coins;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        coins.push_back(a);
    }
    int amt;
    cin>>amt;
    string asf;
    vector<bool>t(n,false);                // we make a boolean array of size n (size of coins), so, that once the element comes, it will not come again in that sequence. 
    coinper(coins, amt, 0, asf,t);
}
