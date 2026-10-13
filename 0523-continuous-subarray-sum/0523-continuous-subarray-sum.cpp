class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum+=nums[i];
            int r = sum%k;
            if(mp.find(r)==mp.end()){
                mp[r] = i;
            }
            else if(i-mp[r]>1){
                return true;
            }
        }
        return false;
    }
};