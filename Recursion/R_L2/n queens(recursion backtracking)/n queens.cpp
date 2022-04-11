#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool ispossible(vector<vector<int>> v, int row, int col)
{
    for(int i=row-1,j=col;i>=0;i--)
    {
        if(v[i][j]>0)
        {
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
    {
        if(v[i][j]>0)
        {
            return false;
        }
    }
    
    for(int i=row-1,j=col+1;i>=0&&j<v[i].size();i--,j++)
    {
        if(v[i][j]>0)
        {
            return false;
        }
    }
    return true;
    
}

void queens(vector<vector<int>> v,int n,int row,string asf)
{
    if(row==v.size())
    {
        cout<<asf<<endl;
        return;
    }
    
   for(int col=0;col<v.size();col++)
   {
       if(ispossible(v,row,col)==true)
       {
           v[row][col]=1;
           //cout<<"d"<<endl;
           queens(v,n,row+1, asf+to_string(row)+" "+to_string(col)+", ");
           v[row][col]=0;
       }
   }
}
int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> v(n , vector<int> (n, 0));
    
    queens(v,n,0,"");
}
