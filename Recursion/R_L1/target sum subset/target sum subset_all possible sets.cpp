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
        ArrayList<String> sets = subsets(arr, target,0);
        for(String s:sets)
        {
            System.out.println(s);
        }
    }
                                         
    public static ArrayList<String> subsets(int[] arr, int target, int idx)
    {
        if(target==0)
        {
            ArrayList<String> ans = new ArrayList<String>();
            ans.add("");
            return ans;
        }
        else if(idx==arr.length)
        {
            ArrayList<String> ans = new ArrayList<String>();
            return ans;
        }
        ArrayList<String> include = subsets(arr, target-arr[idx],idx +1);
        ArrayList<String> exclude = subsets(arr, target,idx+1);
        
        ArrayList<String> res = new ArrayList<String>();
                                                                                                                                                                                   
        for(String i:include)
        {
            res.add(i+arr[idx]);
        }
        for(String i:exclude)
        {
            res.add(i);
        }
        
        return res;
    }
}
