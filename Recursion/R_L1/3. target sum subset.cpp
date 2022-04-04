//https://nados.io/question/target-sum-subsets-dp



import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception
    {
        Scanner scn= new Scanner(System.in);
        int n;
        n=scn.nextInt();
        
        int[] arr = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=scn.nextInt();
        }
        int target;
        target = scn.nextInt();
        
        boolean ans = subset(arr, target,0,n,0);
        System.out.println(ans);
    }
    public static boolean subset(int[] arr, int target, int ans,int n,int i)
    {
        if(i==n)
        {
            if(target==ans)
            {
                return true;
            }
            else
            return false;
        }
        
        boolean ans1=subset(arr, target,ans+arr[i], n, i+1);
        boolean ans2 =subset(arr,target,ans,n,i+1);
        if(ans1 || ans2)
        return true;
        else
        return false;
        
    }
}
