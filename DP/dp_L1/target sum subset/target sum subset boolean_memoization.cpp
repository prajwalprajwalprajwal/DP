//little bit error

import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args)throws Exception{
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        
        for(int i=0;i<n;i++)
        {
            arr[i]=scn.nextInt();
        }
        int target;
        target = scn.nextInt();
        boolean[][] strgs = new boolean[arr.length+1][target+1];
        boolean sets = subsets(arr, target,0,strgs);
        System.out.println(sets);
    }
                                         
    public static boolean subsets(int[] arr, int target, int idx, boolean[][] strgs)
    {
        
        if(target==0)
        {
            
            return true;
        }
        else if(idx==arr.length)
        {
            
            return false;
        }
        
        if(target>0 && strgs[idx][target]!=false)
        {
            return strgs[idx][target];
        }
        boolean include = subsets(arr, target-arr[idx],idx +1, strgs);
        boolean exclude = subsets(arr, target,idx+1, strgs);
        
        boolean ans = include || exclude;
        if(target>0)
        strgs[idx][target]=ans;
        return ans;
    }
}
