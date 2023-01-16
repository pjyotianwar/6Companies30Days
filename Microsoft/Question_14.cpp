// Minimum Deletions to Make Array Divisible

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int, int> mp;
        set<int> s;
        for(auto& n: nums){
            mp[n]++;
        }
        for(auto& n: numsDivide){
            s.insert(n);
        }

        int ans = 0;

        for(auto& m: mp){
            bool p = true;
            for(auto& it: s){
                if(it<m.first)
                    return -1;
                else if(it%m.first!=0){
                    p = false;
                    break;
                }
            }
            if(p)
                return ans;
            ans+=m.second;
        }

        return -1;
    }
};