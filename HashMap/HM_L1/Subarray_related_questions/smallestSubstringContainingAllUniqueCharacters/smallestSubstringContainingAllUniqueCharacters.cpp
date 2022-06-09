// https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/smallest-substring-of-a-string-containing-all-unique-characters-of-itself-official/ojquestion
//22 march



import java.util.*;

public class Main{
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        String s1 = scn.next();
        
        int ans = SmallestSubstring(s1);
        System.out.println(ans);
    }
    public static int SmallestSubstring(String s1){
        HashSet<Character> set = new HashSet<>();
        HashMap<Character,Integer> map = new HashMap<>();
        
        //through hashset find the total no. of unique character available in the string through hashset.
        for(int i=0;i<s1.length();i++)
        {
            char preschar = s1.charAt(i);
            
                set.add(preschar);
            
        }
        
        //#AcquireReleaseStrategy
        int ans = Integer.MAX_VALUE;
        for(int i=0,j=0;i<s1.length();i++)
        {
            //add the char to the map.
            char ch = s1.charAt(i);
            map.put(ch, map.getOrDefault(ch,0)+1);
            //when mapsize and set size will be same, it means at present unique elements are available in the present juridiction(i to j)
            //so, now release the elements till we get the string is valid.
            while(map.size()==set.size() &&  j<s1.length())
            {
                char chj = s1.charAt(j);
                map.put(chj, map.get(chj)-1);
                if(map.get(chj)<=0)
                {
                    map.remove(chj);
                    ans=Math.min(ans, i-j+1);
                }
                j++;
            }
        }
        return ans;
        
        
    }
}
