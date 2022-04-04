//  https://nados.io/question/goldmine


import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int[][] costs = new int[n][m];
        
        for(int i=0;i<costs.length;i++)
        {
            for(int j=0;j<costs[0].length;j++)
            {
                costs[i][j]=scn.nextInt();
            }
        }
        
        int[][] strgs= new int[costs.length][costs[0].length];
        int max=0;
        for(int i=0;i<costs.length;i++){
        int v=goldMine(costs, i, 0,strgs);
        if(max<v)
        {
            max=v;
        }
        
        }
        System.out.println(max);
        
        
        
    }
    
    public static int goldMine(int[][] costs, int i, int j,int[][] strgs )
    {
        if(j==costs[0].length-1)
        {
            if(strgs[i][j]!=0)
            {
                return strgs[i][j];
            }
            
                int val = costs[i][j];
                int ans = val;
                strgs[i][j]=ans;
                return ans;
            
        }
        
        else if(i==0)
        {
            if(strgs[i][j]!=0)
            {
                return strgs[i][j];
            }
            
                int val = costs[i][j];
                int v1 = goldMine(costs,i,j+1,strgs);
                int v2 = goldMine(costs,i+1,j+1,strgs);
                
                int ans = val + Math.max(v1,v2);
                strgs[i][j]=ans;
                return ans;
            
        }
        
        else if(i==costs.length-1)
        {
            if(strgs[i][j]!=0)
            {
                return strgs[i][j];
            }
            
                int val = costs[i][j];
                int v1 = goldMine(costs,i,j+1,strgs);
                int v2 = goldMine(costs,i-1,j+1,strgs);
                int ans = val +Math.max(v1,v2);
                strgs[i][j]=ans;
                return ans;
            
        }
        else
        {
            if(strgs[i][j]!=0)
            {
                return strgs[i][j];
            }
            
                int val = costs[i][j];
                int v1 = goldMine(costs,i,j+1,strgs);
                int v2 = goldMine(costs,i+1,j+1,strgs);
                int v3  = goldMine(costs,i-1,j+1,strgs);
                
                int ans = val + Math.max(v1, Math.max(v2,v3));
                strgs[i][j]=ans;
                return ans;
            
        }
        
        
        
        // goldMine(costs,i,j+1,strgs);
        // goldMine(costs,i+1,j+1,strgs);
        // goldMine(costs,i-1,j+1,strgs);
    }
}
