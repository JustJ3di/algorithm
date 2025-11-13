class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> table;
        int n = candyType.size();
        int c = 0;
        for(auto &&e: candyType){
            if(!table.contains(e))c++;
            if(c == n/2)return c;
            table.insert(e);
        }

        return c;
        
    }
};
