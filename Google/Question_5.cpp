// Number of Closed Islands


class Solution {
    int m, n;
    bool dfs(vector<vector<int>>& g, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m)
        return false;
        if(g[i][j])
        return true;
        if(i==0 || j==0 || i==n-1 || j==m-1)
        return false;

        bool a, b, l, r;
        g[i][j]=1;

        a=dfs(g, i-1, j);
        b=dfs(g, i+1, j);
        l=dfs(g, i, j-1);
        r=dfs(g, i, j+1);

        return a && b && l && r;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        n=grid.size();
        if(!n)
        return 0;
        m=grid[0].size();

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j]==0){
                    if(dfs(grid, i, j));
                    ans++;
                }
            }
        }

        return ans;
    }
};