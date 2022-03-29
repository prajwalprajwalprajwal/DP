#include<bits/stdc++.h>
using namespace std;
void coincom(int i, vector<int>coins, int amt, int amtsf, string asf)
{
  if(i==coins.size())
  {
    if(amt==amtsf)
    {
    cout<<asf<<endl;
    return;
    }
    else
    {return;}
  }
  
  coincom(i+1, coins, amt, amtsf+coins[i], asf+to_string(coins[i]));          // we should include 
  coincom(i+1, coins, amt, amtsf, asf);                                 // not include
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
  coincom(0,coins,amt,0,asf);
}
