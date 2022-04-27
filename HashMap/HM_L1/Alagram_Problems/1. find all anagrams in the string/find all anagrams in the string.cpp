// https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/find-all-anagrams-in-a-string-official/ojquestion

//ANAGRAM - Two strings are in anagram, when all characters must be present maybe the order is different.
//EX-   say
//Anagram - ysa,sya etc

//Question is - Let "S1" is string, find all the anagram in the string "S2", and print the starting index of it.
// Ex - 
// cbaebabacd -->S2
// abc  --> S1
// Out put - 
// 2  -- > Total anagram found
// 0 6  --> Their starting indexes

//APPROACH IS   -  1. Create a hashmap for string "s1" .

// 			2. Using #Sliding_window approach or #Acquire_release strategy of same length as string s1. Run it on s2.
// 			3.  As we get same frequencies of each character, that will be one of the result. Then move ahead, till last.


import java.util.*;

public class Main {
	public static void findAnagrams(String s, String p) {
        // write your code here
        
        int[] map2 = new int[26];
        for(int i = 0; i < p.length(); i++){
            char ch = p.charAt(i);
            map2[ch - 'a']++;
        }
        
        int[] map1 = new int[26];
        for(int i = 0; i < p.length(); i++){
            char ch = s.charAt(i);
            map1[ch - 'a']++;
        }
        
        ArrayList<Integer> res = new ArrayList<>();
        if(areAnagram(map1, map2) == true){
            res.add(0);
        }
        
        int i = p.length();
        int j = 0;
        
        while(i < s.length()){
            char chi = s.charAt(i);
            map1[chi - 'a']++;
            
            char chj = s.charAt(j);
            map1[chj - 'a']--;
            
            if(areAnagram(map1, map2) == true){
                res.add(j + 1);
            }
            
            i++;
            j++;
        }
        
        System.out.println(res.size());
        for(int val: res){
            System.out.print(val + " ");
        }
        
	}
	
	
	// constant time complexity
	public static boolean areAnagram(int[] map1, int[] map2){
	    for(int i = 0; i < 26; i++){
	        if(map1[i] != map2[i]){
	            return false;
	        }
	    }
	    
	    return true;
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s = scn.next();
		String p = scn.next();
		findAnagrams(s, p);
	}

}

