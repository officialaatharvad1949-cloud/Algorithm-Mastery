class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> hash(26 , 0);
        vector<bool> visited(26 ,false);
        for(auto it: s){
            hash[it-'a'] += 1;
        }
        string ans = "";
        for(char ch : s){
            if(!visited[ch-'a']){
                while(!ans.empty() && ans.back() > ch && hash[ans.back() - 'a'] > 0){
                   visited[ans.back()-'a'] = false;
                   ans.pop_back();
                }
                visited[ch-'a'] = true;
                ans.push_back(ch);
            }
            hash[ch-'a'] -= 1;
        }
        return ans;
        
        
    }
};
