Given string num representing a non-negative integer num, and an integer k,
return the smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1, and the number is 200. Note that the output must not contain leading zeroes.

Main Intuition: Keep the smaller digit at the start.
To get the smallest possible integer, the smaller digits must be kept at the beginning. This can be achieved by getting rid of K larger digits using a simple greedy approach that works by processing each digit and keeping the smallest possible digit, aiming for the smallest resulting number. Prioritizing smaller digits for the leftmost positions ensures the resulting number is minimized.
