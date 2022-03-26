// Coin change permutation with each element can be repeatable upto infinite times.


#include<bits/stdc++.h>
using namespace std;
void coinper(vector<int>coins, int amt, int amtsf, string asf)
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
    for(int i=0;i<coins.size();i++)                 // for each coin, possible permutation
    {
        string a = to_string(coins[i]);
        coinper(coins,amt, amtsf+coins[i], asf+a);    // we add coins[i] to each current answer, to make answer equals to amount.
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
    coinper(coins, amt, 0, asf);
}
