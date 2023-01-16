// Longest Happy Prefix

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> dp(s.size());
        dp[0] = -1;
        for(int i = 1;i<s.size();i++){
            int j = dp[i-1] + 1;
            while(s[i] != s[j]) {
                if(j == 0){
                    break;
                }
                j = dp[j-1] + 1;
            }
            if(s[i] == s[j]){
                dp[i] = j;
            } else {
                dp[i] = -1;
            }
        }
        int l = dp.back();
        return s.substr(0,dp.back()+1);

    }
};