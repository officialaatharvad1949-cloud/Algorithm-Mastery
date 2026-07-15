class Solution
{
public:
    int largestRectangleArea(vector<int> &heights) {
        int max_area = 0;
        int n = heights.size();
        stack<int> small;
        for(int i = 0 ; i < n ; ++i){
            while(small.size() && heights[small.top()] > heights[i]){
                int ele = heights[small.top()];
                int nse = i;
                small.pop();
                int pse = small.empty()? -1 : small.top();
                max_area = max(max_area , ele*(nse - pse - 1));
            }
            small.push(i);
        }
        while(small.size()){
            int nse = n;
            int ele = heights[small.top()];
            small.pop();
            int pse = small.empty()? -1 : small.top();
            max_area = max(max_area , ele*(nse - pse - 1));

        }
        return max_area;
     
    }
};
