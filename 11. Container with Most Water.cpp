class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, start = 0, end = height.size()-1;
        while(start<end){
            int area = min(height[start], height[end])*(end-start);
            max_area = max(max_area, area);
            if(height[start]<height[end])
                start++;
            else
                end--;
        }
        return max_area;
    }
};
