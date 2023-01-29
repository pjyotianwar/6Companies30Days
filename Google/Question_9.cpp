// Maximum Number of Coins You Can Get


class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(p.begin(), p.end(), greater<>());
        int n = p.size(), ans = 0;
        for(int i = 1; i < 2*n/3; i+=2) ans+=p[i];
        return ans; 
    }
};