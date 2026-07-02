class Solution {
    // This solution is based on Greedy Algorithm. Instead of just the cnt variable filling up the asterisk
    // here , a range of value will be maintained .
    // if range contains the desired value, then it's true, otherwise false;
    // Time complexity is big O(N) where  N is the size of string;
public:
    bool checkValidString(string s) {
        int min = 0 , max = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                min +=1;
                max += 1;
            }else if(s[i] == ')'){
                min -= 1;
                max -= 1;
            }
            else if(s[i] == '*'){
                min -= 1;
                max += 1;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
        }
        return (min == 0);
        
    }
};
