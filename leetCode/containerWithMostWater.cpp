//Given n non-negative integers a1, a2, ..., an , where each represents a point at 
//coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i
//is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container,
//such that the container contains the most water.


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n < 2) return 0;
        
        int first = 0, last = n-1;
        int maxSoFar = 0;
        
        while(first < last){
            int area = min(height[first],height[last]) * (last-first);
            maxSoFar = max(maxSoFar,area);
            if(height[first] <= height[last])
                first++;
            else
                last--;
        }
        
        return maxSoFar;        
    }
};