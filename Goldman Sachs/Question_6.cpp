// Minimum Consecutive Cards to Pick Up

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int ans=INT_MAX, i=1;
        for(auto& card: cards){
            if(mp[card]){
                ans = min(ans, i-mp[card]+1);
            }
            mp[card]=i;
            i++;
        }

        if(ans!=INT_MAX)
        return ans;
        return -1;
    }
};