class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int val = 1;
        int ans = 0;
        while (val < buckets) {
            val *= (minutesToTest / minutesToDie) + 1;
            ans++;
        }
        return ans;
    }
};