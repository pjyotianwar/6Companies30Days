// Matrix Block Sum


class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1 ; i <= m ; ++i) {
            for (int j = 1 ; j <= n ; ++j) {
                prefix[i][j] = mat[i - 1][j - 1] + 
                            prefix[i - 1][j] + 
                            prefix[i][j - 1] - 
                            prefix[i - 1][j - 1];
            }
        }
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 1 ; i <= m ; ++i) {
            for (int j = 1 ; j <= n ; ++j) {
                int bgn_r = (i - K - 1) >= 0 ? (i - K - 1) : 0;
                int bgn_c = (j - K - 1) >= 0 ? (j - K - 1) : 0;
                int end_r = (i + K) <= m ? (i + K) : m;
                int end_c = (j + K) <= n ? (j + K) : n;
                
                ans[i - 1][j - 1] = prefix[end_r][end_c] - 
                                    prefix[end_r][bgn_c] - 
                                    prefix[bgn_r][end_c] +
                                    prefix[bgn_r][bgn_c];
            }
        }
        
        return ans;
    }
};