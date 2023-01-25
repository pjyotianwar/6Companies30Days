// Number of Ways to Separate Numbers

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    vector<vector<long long>> dp, hash;
    string num;
    int n;
    
    bool f(int left, int mid, int right) {
        if(right > n) return false;
        
        auto check = [&](auto m) {
            return hash[left][left + m] == hash[mid][mid + m];
        };
        
        int l = 0, r = mid - left + 1;
        while(l + 1 < r) {
            auto m = (l + r) / 2;
            if(check(m)) l = m;
            else r = m;
        }
        
        if(l < mid - left && num[left + l] > num[mid + l])
            return false;
        else
            return true;
    }
    
    long long recur(int start, int len) {
        if(start == n) return 1;
        if(start > n) return 0;
        if(start + len > n) return 0;
        if(num[start] == '0') return 0;
        
        auto& ret = dp[start][len];
        if(ret != -1) return ret;
        
        ret = recur(start, len + 1);
        if(f(start, start + len, start + 2 * len))
            ret = (ret + recur(start + len, len)) % MOD;
        else
            ret = (ret + recur(start + len, len + 1)) % MOD;
        
        return ret;
    }
    
    int numberOfCombinations(string num) {
        this->num = num, this->n = num.size();
        this->dp = vector<vector<long long>>(n+1, vector<long long>(n+1, -1));
        this->hash = vector<vector<long long>>(n+1, vector<long long>(n+1));
        
        for(auto i = 0; i < n; ++i) {
            long long h = 0;
            for(auto j = i; j < n; ++j) {
                h = (h * 10 + num[j] - '0') % MOD;
                this->hash[i][j+1] = h;
            }
        }
        
        return recur(0, 1);
    }
};