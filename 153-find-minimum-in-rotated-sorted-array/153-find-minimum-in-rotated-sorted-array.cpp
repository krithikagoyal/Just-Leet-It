class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] <= nums[nums.size() - 1])
            return nums[0];
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[0]) {
                l++;
            } else {
                r--;
            }
        }
        if (nums[mid] >= nums[0])
            return nums[mid + 1];
        return nums[mid];
    }
};