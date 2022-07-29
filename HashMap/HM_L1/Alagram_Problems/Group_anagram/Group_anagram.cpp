// Group anagram.
//https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/group-anagrams-official/ojquestion#!

//we have different words. we have to grouping these words according to the same anagram

import java.util.*;

public class Main {
    // this function helps to create a hashmap and group the words.
    public static ArrayList<ArrayList<String>> groupanagram(String[] strs)
    {
        HashMap<String, ArrayList<String>> map = new HashMap<>();
         
         //take one by one string from the array.
        for(String str : strs)
        {
            //convert it into code. like abaac = a3b1c1
            String code = getcode(str);
            
            //chekk is it available in the hashmap or not. if yes then add this string to it otherwise create new key and add that string to it.
            
            if(map.containsKey(code))
            {
                ArrayList<String> list = map.get(code);
                list.add(str);
                map.put(code,list);
            }
            else
            {
                ArrayList<String>list = new ArrayList<String>();
                list.add(str);
                map.put(code, list);
            }
        }
        
        //take all the values and add it to single arraylist of strings to an ArrayList.
        ArrayList<ArrayList<String>> res = new ArrayList<>();
        for(String code : map.keySet())
        {
            ArrayList<String> list = map.get(code);
            res.add(list);
        }
        return res;
    }
    
    //create a code for the string.
    public static String getcode(String str)
    {
        HashMap<Character, Integer> fmap = new HashMap<>();
        //add to the hashmap
        for(char ch : str.toCharArray())
        {
            fmap.put(ch, fmap.getOrDefault(ch,0)+1);
        }
        String code = "";
        take all the key and its value aand make a string.
        for(Character key :fmap.keySet())
        {
            code+=key+""+fmap.get(key);
        }
        return code;
    }
    
    
    
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        
        String[] arr = new String[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = scn.next();
        }
        ArrayList<ArrayList<String>> anagramgrouped = groupanagram(arr);
        //sort within arraylist, according to alphabetical order.
        for(ArrayList<String> lst : anagramgrouped)
        {
           Collections.sort(lst);
        }
        // sort according to size of ArrayList
        anagramgrouped.sort(new ListComparator());
        display(anagramgrouped);
    }
    
    static class ListComparator implements Comparator<List<String>> {
        @Override
        
        public int compare(List<String> l1, List<String>l2)
        {
            if(l1.size()!=l2.size())
            {
                return l2.size()-l1.size();
            }
            String l1str = l1.get(0);
            String l2str = l2.get(0);
            return l1str.compareTo(l2str);
        }
        
    }
    public static void display(ArrayList<ArrayList<String>> list)
    {
        for(int i =0;i<list.size();i++)
        {
            ArrayList<String> currlist = list.get(i);
            for(int j=0;j<currlist.size();j++)
            {
                System.out.print(currlist.get(j) + " ");
            }
            System.out.println();
        }
    }
}
