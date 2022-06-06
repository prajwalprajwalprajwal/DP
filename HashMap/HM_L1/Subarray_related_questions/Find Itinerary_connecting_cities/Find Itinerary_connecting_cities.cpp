//https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/find-itinerary-from-tickets-official/ojquestion
//22 march 2022


import java.util.*;

public class Main{
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        int pairs = scn.nextInt();
        
        //create a HashMap to store the tem. starting point and its destination
        HashMap<String, String> map =new HashMap<>();
        
        //create a HashSet to store starting points... So, that jb hmm compare karenge with destinations list, so, that it is easy to find the starting point.
        HashSet<String> set = new HashSet<String>();
        
        //for all pairs
        for(int i=0;i<pairs;i++)
        {
            String s1 = scn.next();
            String s2 = scn.next();
            //insert to HashMap
            map.put(s1, s2);
            //insert starting points to set
            set.add(s1);
        }
        
        //create a ArrayList to store all destination points
        ArrayList<String> al = new ArrayList<String>(map.keySet());
        
        //if destination points matched with starting points..delete them from set. So, at last the city remains in set, that will be a starting point.
        for(String s : al)
        {
            //if set element == ArrayList, then remove it.
            if(set.contains(map.get(S)))
            {
                set.remove(map.get(S));
            }
        }
        
        //In set only one element is remaining... but when we convert set to String.. It also adds [....].
        String start = set.toString();
        
        StringBuilder sb = new StringBuilder(start);
        //So, to remove brackets.
        sb.deleteCharAt(0);
        sb.deleteCharAt(sb.length()-1);
        start = sb.toString();
        
        //while we have atleast one pair in the map.
        while(map.containsKey(start))
        {
            if(map.size()==1)
            {
                System.out.print(start + " -> " + map.get(start) + ".");
                break;
            }
            
            //print the starting point and its destination.
            System.out.print(start + " -> ");
            String nstart = map.get(start);
            
            //then remove it.
            map.remove(start);
            //make the current destination as starting.
            start = nstart;
        }
        
    }
}
