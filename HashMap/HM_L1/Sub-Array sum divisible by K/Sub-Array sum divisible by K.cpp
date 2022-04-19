//Sub-Array sum divisible by K

//similar to sub array sum equal to k.
The changes are - 
1. When we find the instance sum, divide it by k, if the remainder is availabe in the hashmap, add its value to the answer and increase the value by one.
2. If the remainder is not available, then add that remainder to the hashmap, and set its value as one.
