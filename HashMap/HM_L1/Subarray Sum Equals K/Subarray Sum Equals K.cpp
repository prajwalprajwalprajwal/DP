//https://leetcode.com/problems/subarray-sum-equals-k/
//11th april - ss

//Find subarrays which sum is equals to k.

//The approach is - 
//	1. Take a variable called sum, which will do the operation of adding elements to it, at every instance. 
//	2. Then we subtract that instance sum with k, let we get the value 'a'. If we found the value 'a' in our hashmap, then add that value to ans and increase its value by one, otherwise insert a new key as 'a' with value one in it.


class Solution {
    public int subarraySum(int[] nums, int k) {
        int ans = 0;
        
        int sum = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(sum, 1);
        for(int val: nums){
            sum += val;
            
            if(map.containsKey(sum - k)){
                ans += map.get(sum - k);
            }
            
            if(map.containsKey(sum)){
                map.put(sum, map.get(sum) + 1);
            } else {
                map.put(sum, 1);
            }
        }
        
        
        return ans;
    }
}
