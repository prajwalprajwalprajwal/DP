//https://practice.geeksforgeeks.org/problems/morning-assembly3038/1
//22 march 2022

import java.util.*;

public class Main{
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        
        //create an ArrayList to store numbers and HashMap to store number and how many continious previous elements. 
        ArrayList<Integer> arr = new ArrayList<Integer>(n);
        HashMap<Integer,Integer> map = new HashMap<>();
        
        
        for(int i=0;i<n;i++)
        {
            
            int a =scn.nextInt();
            arr.add(a);
        }
        
        //max stores which is the largest continious sequence available.
        int max = 0 ;
        
        //passing through whole array.
        for(int val : arr)
        {
            //for current element, if its previous element is available in the HashMap, copy their frequecy to it and add one to it.
            if(map.containsKey(val-1))
            {
                map.put(val, map.get(val-1)+1);
            }
            
            //otherwise introduce new element to the hashmap.
            else
            {
                map.put(val,1);
            }
            
            //if the current's element value is greater than the max, then update the max.
            if(map.get(val)>max)
        {
            max = map.get(val);
            
        }
        }
        
        //So, we know their is no need to touch the longest existing sequence. Hence, we have continious elements of array given, with 0(1) operation we can arrange the remaining elements. So, substract n-max.
        System.out.println(n-max);
    }
    
}
