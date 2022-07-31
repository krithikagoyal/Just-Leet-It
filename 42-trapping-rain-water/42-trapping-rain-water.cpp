class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
                ans += max(leftMax - height[left], 0);
                leftMax = max(leftMax, height[left]);
            } else {
                right--;
                ans += max(rightMax - height[right], 0);
                rightMax = max(rightMax, height[right]);
            }
        }
        return ans;
    }
};