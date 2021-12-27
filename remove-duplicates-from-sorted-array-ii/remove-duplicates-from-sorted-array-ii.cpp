class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int shifts = 0, cnt = 0, num = 100000;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num) {
                cnt++;
            } else {
                cnt = 1;
                num = nums[i];
            }
            
            if (cnt <= 2) {
                int tmp = nums[i];
                nums[i] = nums[i - shifts];
                nums[i - shifts] = tmp;
            } else {
                shifts++;
            }
        }
        return nums.size() - shifts;
    }
};