class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int start = 0;
        int end = n - 1;
        int maxarea = 0;
        while (start < end) {
            maxarea = max(maxarea, (end - start) * min(height[start], height[end]));
            if (height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return maxarea;
    }
};