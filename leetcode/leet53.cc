class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = INT_MIN;
        int tmp = 0;
        int s = 0;
        int t = nums[0];
        for(auto &&e:nums){
            if(e>t)t = e;
            if(e<0)s++;
            tmp += e;
            if(tmp<0)
                tmp = 0;
            m = max(tmp,m);
        }
        //MAGIC
        return [=](){
            if(s==nums.size())
                return t;
            return m;
        }();
            
    }  
};
