class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int sum = 0;
        for(int num : nums){
            mini = min(mini,num);
            sum+=num;
        }
        return sum - n*mini;
    }
};