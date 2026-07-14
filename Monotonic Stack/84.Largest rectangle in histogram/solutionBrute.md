Given an array of integers heights representing the histogram's bar height, where the width of each bar is 1, 
Return the area of the largest rectangle in the histogram.
<img width="522" height="242" alt="image" src="https://github.com/user-attachments/assets/edb93087-39bc-4dd2-a4cb-063c4fc007af" />

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Approach: One way to get the maximum rectangle area possible is by considering all the rectangles and then finding the maximum area out of those. 
To find the area of a rectangle, its height and width must be known. Given the heights in the question, the only task remaining is to find the width of the rectangle.

The width of a rectangle of current height will depend on the number of rectangles on the left and right having a height greater than or equal to the current height.
<img width="949" height="357" alt="image" src="https://github.com/user-attachments/assets/269906ae-b239-4630-b61e-4a8a85030e85" />

Hence, the width of the rectangle can be found using the concept of Previous/Next Smaller Elements. The formula for the same is:
       width = nse[ind] - pse[ind] - 1
where, pse[ind] and nse[ind] represent the indices of the previous and next smaller element for the current index.

Thus, the indices of the previous and next smaller elements can be precomputed. This will help in finding the area of possible individual rectangles, out of which the maximum can be returned as the answer.
