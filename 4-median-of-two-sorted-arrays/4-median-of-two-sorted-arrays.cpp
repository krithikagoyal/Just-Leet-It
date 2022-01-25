class Solution {
public:
    
    pair<bool, int> findPos(vector<int>& nums1, vector<int>& nums2, int pos) {
        int l = 0, r = nums1.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (binary_search(nums2.begin(), nums2.end(), nums1[mid])) {
                int x = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
                int y = upper_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
                if (x + mid < pos && y + mid + 1 >= pos) {
                    return {true, nums1[mid]};
                } else if (x + mid >= pos) {
                    r--;
                } else {
                    l++;
                }
            } else {
                int y = upper_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
                if (y + mid + 1 == pos) {
                    return {true, nums1[mid]};
                } else if (y + mid + 1 > pos) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return {false, -1};
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz = nums1.size() + nums2.size();
        pair<bool, int> ans;
        if (sz % 2) {
            int pos = sz / 2 + 1;
            ans = findPos(nums1, nums2, pos);
            if (ans.first)
                return ans.second;
            ans = findPos(nums2, nums1, pos);
            return (double)ans.second;
        }
        
        int leftpos = sz / 2;
        int rightpos = leftpos + 1;
        pair<bool, int> left;
        pair<bool, int> right;
        
        left = findPos(nums1, nums2, leftpos);
        if (left.first == false) {
            left = findPos(nums2, nums1, leftpos);
            // cout << "yes" << endl;
        }
        
        right = findPos(nums1, nums2, rightpos);
        if (right.first == false) {
            right = findPos(nums2, nums1, rightpos);
        }
        
        // cout << left.second << " " << right.second << endl;
        
        return (double)(left.second + right.second) / 2.0;
    }
};