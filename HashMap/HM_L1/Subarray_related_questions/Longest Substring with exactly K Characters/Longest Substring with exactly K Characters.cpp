//https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/longest-substring-with-exactly-k-unique-characters-official/ojquestion
//22 march

import java.util.*;
public class Main {
  public static void main(String[] args)
  {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        int k = scn.nextInt();
        
        System.out.println(solution(str,k));
  }
  
  public static int solution(String str, int k)
  {
      int maxLen = -1;
      HashMap<Character,Integer> map = new HashMap<Character, Integer>();
      
      //use aquire release strategy to get max. length unique characters
      for(int i=0,j=0;i<str.length();i++)
      {
          // get the character and add it to the map.
          char ch = str.charAt(i);
          map.put(ch,map.getOrDefault(ch,0)+1);
          //if map size is equal to k, then find the max of maxlen and i-j+1.
          if(map.size()==k)
          {
              maxLen = Math.max(maxLen,i-j+1);
          }
          //if size is bigger, then, release approach is used.
          else{
              while(map.size()>k){
                  char l = str.charAt(j);
                  int count = map.get(l);
                  if(count==1)
                  {
                      map.remove(l);
                  }
                  else
                  {
                      map.put(l, map.get(l)-1);
                  }
                  j++;
              }
          }
      }
      return maxLen;
  }
}
