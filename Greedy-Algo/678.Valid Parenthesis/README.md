# 678. Valid Parenthesis String

## Problem
Given a string `s` containing `'('`, `')'`, and `'*'`, return true if the string can be valid. 

These are the following rules :
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 
## Bottleneck
Use of a single balance counter doesn't guarantee the validity of 3rd rule.

## Approach
Use a greedy range approach.

Instead of tracking one balance count, maintain:
- `minOpen` = minimum possible open brackets
- `maxOpen` = maximum possible open brackets

For each character:
- `'('` → both increase
- `')'` → both decrease
- `'*'` → it can be `'('`, `')'`, or empty
  - so `minOpen--`
  - `maxOpen++`

### Important checks
- If `maxOpen < 0`, too many closing brackets → invalid immediately
- `minOpen` should never go below `0`, so clamp it:
  ```cpp
  minOpen = max(minOpen, 0);

### Result check 
If min == 0 . That mean the given string is a valid one . else it's invalid;
