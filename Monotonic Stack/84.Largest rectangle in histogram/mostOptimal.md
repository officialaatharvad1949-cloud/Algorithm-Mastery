Unlike the previous approach, where nse(next smaller element ) and pse(previous smaller element) for each element are calculated and stored in a vector.
And then again, traverse through the element to apply this formula 
          ans[i] = nums[i]*(nse - pse - 1);
Just to calculate the max_area out of it. 
This approach result in time complexity of : O(3N) + O(2N) . First we traversing the 3 visible loops there and second we are poping or pushing elements in 
stack that add up to O(2N). 

In this more optimal approach . Instead of precalculating the pse and nse , Now both of this will be calculated in constant time in one loop, possibly. 
pse is much simpler to calculate while going from i = 0 -> i = n-1. Main bottleneck is to calculate the nse. While we can't calculate the nse for same ith, 
we can very well calculate the nse for a lesser ith value.
For example i = 4. pse for 4th index is know. nse for 4th index can't be calculated . but nse for the 3th index can be calculate here . 
if the value at 4th index is smaller than the value at 3th index then nse for 3th index is 4. and the pse for the 3th index is already stored in the stack. 
 So in this way we know the pse and nse for 3th index , now we can calculate the area and compare it with max_area.

Edge case : Here in this approach , last element will missed to calculate the area. for such element which were not calculated , A simple while loop can 
traverse through this element. 
            Since this element weren't removed in the previous loop , then there nse value mustn't be present in original array . 
            So we will take the nse value as n(size of the array heights);
            and pse value is already stored in the stack data structure as we already know . 
            Now we will find the rem area for such element and compare it with max_area. 

Here this approach will cost O(N) in space complexity and (O(N) + O(N)) in time complexity.
