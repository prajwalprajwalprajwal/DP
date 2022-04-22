//https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
//14th april - ss

//We have different kinds of people in a society. We have to tell is their any particular way, so, that grouping can be done with particular no. only For every kind of people. Such that after grouping, no one can left alone.

//Approach - 1. Make a frequency hashmap. Fill all the frequencies of each kind of elements
//	2. Take the gcd/hcf of all frequencies. So, that we can get to know what will be the maximum size for
//	Grouping.
//If gcd is greater than equal to2, it means their is no number remains. If it is one, it means we can't group the number.


#include<bits/stdc++.h>
using namespace std;

int gcd(int n1,int n2)
{
    while(n1%n2!=0)
    {
        int rem = n1%n2;
        n1=n2;
        n2=rem;
        
    }
    return n2;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v ;
    unordered_map<int,int>map;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
        if(map.count(a)>0)
        {
            map[a]++;
        }
        else
        {
            pair<int,int>p(a,1);
            map.insert(p);
        }
    }
    int counter=0;
    int gcd1=1;
    for(auto m : map)
    {
        if(counter==0)
        {
            gcd1=m.second;
        }
        else
        {
            int gcd2 = m.second;
            gcd1=gcd(gcd1,gcd2);
        }
        counter++;
    }
    
    if(gcd1>=2)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}
