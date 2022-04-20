//https://practice.geeksforgeeks.org/problems/equal-0-1-and-23208/1/
//11th april - ss

//Find subarrays, which have equal no. Of 0,1 and 2s.
//The approach is - Suppose at any point of time, if no. Of 0s,1s and 2s are x,y and z. And after some time
                                //If the no. Of 0s, 1s and 2s all are increased same time, let say 'a'. i.e x+a,y+a,z+a. Then                                                                                                                                                                        that subarray is said to be as equal no. Of 0s,1s and 2s in it.



class Solution 
{ 
    long getSubstringWithEqual012(String str) 
    { 
        long ans = 0;
        
        // code here
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        String key = "0#0";
        HashMap<String, Integer> map = new HashMap<>();
        
        map.put(key, 1);
        
        for(int i = 0; i < str.length(); i++){
            char ch = str.charAt(i);
            
            if(ch == '0'){
                c0++;    
            } else if(ch == '1'){
                c1++;
            } else {
                c2++;
            }
            
            key = (c1 - c0) + "#" + (c2 - c1);
            
            if(map.containsKey(key)){
                int val = map.get(key);
                ans += val;
                
                map.put(key, val + 1);
            } else {
                map.put(key, 1);
            }
        }
        
        return ans;
    }
}
