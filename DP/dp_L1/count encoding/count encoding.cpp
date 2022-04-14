//https://nados.io/question/count-encodings
//4th march by ss.


#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    
    int dp[str.size()+1];
    
    dp[0]=1;
    
    dp[1]=1;
    for(int i=2;i<=str.size();i++)
    {
        string s1;
        s1=str[i-1];
        
        int n1=stoi(s1);
       
        if(n1!=0)
        {
            dp[i]=dp[i-1];
        }
        string s2;
        s2=str[i-2];
        s2.append(s1);
        
        int n2 = stoi(s2);
        if(n2!=0 && n2<=26)
        {
            dp[i]+=dp[i-2];
        }
    }
    cout<<dp[str.size()];
}
