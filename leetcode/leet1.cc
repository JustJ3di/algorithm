class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>tab;
        for(auto i = 0;i < nums.size(); ++i){
            auto find = target-nums[i];
            if(tab.contains(find))
                return {i,tab[find]};
            tab[nums[i]] =i;
        }
        return {};
    }
};
