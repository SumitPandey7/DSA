class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());

        for(int i = 1;i < n;i++){
            if(nums[i] == nums[i-1]){
                if(ans.empty() || ans.back()!=nums[i]){
                    ans.push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};