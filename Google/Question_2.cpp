// Maximum Good People Based on Statements

class Solution {
    bool valid(vector<vector<int>>& S, string& cur) {
        for(int i = 0; i < n; i++) 
            if(cur[i] == '1') 
                for(int j = 0; j < n; j++) 
                    if(S[i][j] != 2 && S[i][j] != cur[j] - '0') return false;
        return true;
    }
public:
    int n, ans = 0;
    int maximumGood(vector<vector<int>>& S) {
        n = size(S);
        string cur = ""; cur.reserve(n);
        dfs(S, cur, 0, 0);
        return ans;
    }
    void dfs(vector<vector<int>>& S, string& cur, int i, int cnt) {
        if(i == n) {
            if(valid(S, cur)) ans = max(ans, cnt);
            return;
        }
        cur.append(1, '0');
        dfs(S, cur, i+1, cnt);
        cur.back() = '1';
        dfs(S, cur, i+1, cnt + 1);
        cur.pop_back();        
    }
};