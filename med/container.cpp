class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, left = 0, right = height.size()-1;
        
        while (left < right) {
            int area = min(height[left],height[right]) * (right-left);
            maxArea = max(maxArea, area);
            
            // Smaller of the two moves inward
            if (height[left] < height[right])
                left++; // left smaller
            else
                right--; // right smaller or equal
        }
        
        return maxArea;
    }
};