//https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/longest-substring-with-unique-characters-official/ojquestion
//22 march 2022

//use acquire and release strategy.

import java.util.*;

public class Main{
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        System.out.println(solution(str));
    }
    
    
    public static int solution(String str)
    {// if string length is zero, then return with zero.
        if(str.length()==0)
        {
            return 0;
        }
        
        //create a hashmap - which stores characters with its frequency.
        HashMap<Character,Integer> map = new HashMap<>();
        
        // Minimum ans will be 1
        int ans =1;
        
        //run a loop from starting of string to end.
        for(int i=0,j=0;i<str.length();i++)
        {
            //use i to acquire and j to release
            char ch = str.charAt(i);
            
            // if char i is already present, then use release strategy to release elements from j, till all elements will be unique
            while(map.containsKey(ch))
            {
                //get the jth index element
                char chj = str.charAt(j);
                
                //reduce its frequency
                map.put(chj, map.get(chj)-1);
                
                //when when jth character's frequency is zero, tb tb temporary answer store kr lo. so, that at the time,as we encounter the chi th element, we must have its answer.
                if(map.get(chj)<=0)
                {
                    map.remove(chj);
                    ans=Math.max(ans,i-j);
                }
                j++;
            }
            
            //otherwise add element to the hashmap.
            map.put(ch,map.getOrDefault(ch,0)+1);
            
        }
        
        //print max of answer or map.size.
        return Math.max(ans,map.size());
    }
}
