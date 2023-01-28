// Maximum Consecutive Floors Without Special Floors

class Solution {
public:
    int maxConsecutive(int b, int t, vector<int>& special) {
        sort(special.begin(), special.end());
        int ans=0;
        for(auto& s:special){
            ans=max(ans, s-b);
            b = s+1;
        }
        ans = max(t-special.back(), ans);
        return ans;
    }
};