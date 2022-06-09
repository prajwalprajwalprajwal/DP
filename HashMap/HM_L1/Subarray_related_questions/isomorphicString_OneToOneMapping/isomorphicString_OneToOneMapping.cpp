// https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/isomorphic-strings-official/ojquestion
//22 march 2022

//isomorphic-strings-official

import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        String s1 = scn.next();
        String s2 = scn.next();
        
        boolean ans =  isomerphism(s1,s2);
        System.out.println(ans);
    }
    
    public static boolean isomerphism(String s1, String s2)
    {//hashset is to store the values.. and it helps to find whether that value is already present or not.
        HashSet<Character> set = new HashSet<Character>();
        
        //it stores the Character and its correspondence value.
        HashMap<Character, Character> map = new HashMap<>();
        
        // check for all Characters
        for(int i=0;i<s1.length();i++){
            //first putout the i th character of s1 and s2
            char second = s2.charAt(i);
            char first = s1.charAt(i);
            
            // Check if set is already contain value.If yes, then their will be a key and value must be exists in the map. If not then it means ki already that value is assigned to someone else key. So, it will be false. 
            // if in map the key-value exists, then that particular map key's value will be same as second(i th char. of s2). 
            if(set.contains(second))
            {if(map.containsKey(first))
                {
                if(map.get(first)!=second)
                {
                    
                    return false;
                }
                }
                else
                {
                    return false;
                }
              
            }
            // if value is not present in set. Then add it to set and HashMap.
            else
            {
                
                set.add(second);
                map.put(first, second);
            }
        }
        return true;
    }
}
