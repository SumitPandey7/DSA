class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = 1LL * nums[i] * nums[i];
        }
        sort(nums.rbegin(), nums.rend());
        long long ans = 0;
        int pos = (n+1)/2;
        for (int i = 0; i < n; i++) {
            if (i < pos)
                ans += nums[i];
            else
                ans -= nums[i];
        }
        return ans;
    }
};