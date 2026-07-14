class Solution
{
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        int max_area = 0;
        for(int i = 0 ; i < n ; ++i){
            int min_height = heights[i] ; 
            for(int j = i ; j < n ; ++j){
                
                int width = j - i + 1;
                min_height = min(min_height , heights[j]);
                max_area = max(max_area , width*min_height);
            }
        }
        return max_area;
     
    }
};
