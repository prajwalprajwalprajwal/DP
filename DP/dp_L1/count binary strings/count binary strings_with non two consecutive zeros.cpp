//count binary strings
// https://nados.io/question/count-binary-strings
// 4th april - sumit sir

import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args)throws Exception{
       Scanner scn = new Scanner(System.in);
       int n = scn.nextInt();
        
        int count=0;
        int[][] arr = new int[2][n+1];
        arr[0][0]=0;
        arr[1][0]=0;
        arr[0][1]=1;
        arr[1][1]=1;
        for(int i=2;i<=n;i++)
        {
            arr[0][i]=arr[1][i-1];
            arr[1][i]=arr[0][i-1]+arr[1][i-1];
        }
        count=arr[0][n]+arr[1][n];
        System.out.println(count);
       
    }
                                         
    
}
