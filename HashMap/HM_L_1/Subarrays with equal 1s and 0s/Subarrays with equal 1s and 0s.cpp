//https://practice.geeksforgeeks.org/problems/equal-0-1-and-23208/1/#


	//1. Make variable ans=0.

	//2. Make variable sum =0.

	//3. Create a hashmap, for storing the 
	//Frequency of particular kind of sum at instance

	//4. Initialize that no. To 1.

	//5. For every element of the array, if it is 
	//0, then add -1 to the 'sum', or if it  is 1, then
	//Add 1 to the 'sum'

	//6. If that sum element already found in hashmap,
	//Then increase its frequency by one. And add it 
	//To ans.

	//7. If it is not found, then add it to hashmap,
//Then initialize its frequency to one.

class Solution
{
    //Function to count subarrays with 1s and 0s.
    static int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        int ans = 0;
        
        int sum = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(sum, 1);
        
        for(int val: arr){
            sum += (val == 0? -1: 1);
            
            if(map.containsKey(sum)){
                ans += map.get(sum);
                map.put(sum, map.get(sum) + 1);
            } else {
                map.put(sum, 1);
            }
        }
        
        return ans;
    }
}
