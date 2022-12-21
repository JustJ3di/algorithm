int dp(vector <int> &nums, int jumps_index,vector <int> &memo)
    {
        if(jumps_index>=nums.size()-1)return 0;
        if(memo[jumps_index])return memo[jumps_index];
        
        int min_jump=10000;
        for(int i = nums[jumps_index]; i>=1; i--)
            {
                min_jump = min(min_jump,1+dp(nums,i+jumps_index,memo));
            }
        memo[jumps_index] = min_jump;
        return memo[jumps_index];
    }

int jump(vector<int>& nums) {

    vector <int> memo(nums.size());
    return dp(nums,0,memo);
}