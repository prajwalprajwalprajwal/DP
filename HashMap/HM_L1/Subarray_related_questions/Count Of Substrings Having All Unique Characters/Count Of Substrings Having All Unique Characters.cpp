//https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/count-of-substrings-having-all-unique-characters-official/ojquestion
//22 march 2022

import java.util.*;

public class Main {
  public static void main(String[] args)
  {
      Scanner scn = new Scanner(System.in);
      String str = scn.next();
      System.out.println(solution(str));
      
  }
  
  public static int solution(String str)
  {
      //create a HashMap of character vs integer.
      HashMap<Character,Integer> map = new HashMap();
      
      //set answer as 0.
      int ans=0;
      
      //set j for release as 0
      int j=0;
      
      //loop for the string.
      for(int i=0;i<str.length();i++)
      {
          //for acquire ith index - ch.
          char ch = str.charAt(i);
          
          // if map containsKey ch, then release the character till we have ch in our HashMap.
          while(map.containsKey(ch))
          {
              char chj = str.charAt(j);
              //release it.
              map.put(chj,map.get(chj)-1);
              
              //if its freq.become 0, then, remove it.
              if(map.get(chj)<=0)
              {
                  map.remove(chj);
              }
              //inc. the j th index.
              j++;
          }
          
          //if the string has length n, then we can create n different subarrays.
          ans+=(i-j+1);
          //otherwise insert the character.
          map.put(ch,map.getOrDefault(ch,0)+1);
      }
      return ans;
  }
}
