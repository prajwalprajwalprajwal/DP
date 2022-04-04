// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
// 4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from 
//      any row in the left wall.
// 5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
// 6. Each cell has a value that is the amount of gold available in the cell.
// 7. You are required to identify the maximum amount of gold that can be dug out from the mine.


import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        
        int[][] costs = new int[n][m];
        for(int i=0;i<costs.length;i++)
        {
            for(int j=0;j<costs[0].length;j++)
            {
                costs[i][j] = scn.nextInt();
            }
        }
        
        int[][] dp=new int[costs.length][costs[0].length];
        for(int j=dp[0].length-1;j>=0;j--)
        {
            for(int i=0;i<dp.length;i++)
            {
                if(j==dp[0].length-1)
                {
                    dp[i][j]=costs[i][j];
                }
                else if(i==0)
                {
                  
                        dp[i][j]=costs[i][j]+Math.max(dp[i][j+1],dp[i+1][j+1]);
                    
                   
                }
                else if(i==dp.length-1)
                {
                    
                        dp[i][j]=costs[i][j]+Math.max(dp[i][j+1],dp[i-1][j+1]);
                    
                    
                }
                else
                {
                    dp[i][j] = costs[i][j]+ Math.max(dp[i-1][j+1],Math.max(dp[i][j+1],dp[i+1][j+1]));
                }
            }
        }
        int max=-1;
        
        for(int i=0;i<dp.length;i++)
        {
            if(max<dp[i][0])
            {
                max=dp[i][0];
            }
            
        }
        System.out.println(max);
    }
}
