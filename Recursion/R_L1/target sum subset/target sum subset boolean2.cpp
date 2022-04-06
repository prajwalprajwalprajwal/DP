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
        boolean sets = subsets(arr, target,0);
        System.out.println(sets);
    }
                                         
    public static boolean subsets(int[] arr, int target, int idx)
    {
        if(target==0)
        {
            
            return true;
        }
        else if(idx==arr.length)
        {
            
            return false;
        }
        boolean include = subsets(arr, target-arr[idx],idx +1);
        boolean exclude = subsets(arr, target,idx+1);
        
        boolean ans = include || exclude;
        
        return ans;
    }
}
