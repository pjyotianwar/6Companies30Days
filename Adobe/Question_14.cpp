// Number of People Aware of a Secret

class Solution {
public:
    long dp[1001];
    long m=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        return helper(1,n,delay,forget);
    }
    long helper(int day,int &n,int &delay,int &forget){
        if(dp[day]!=-1)
            return dp[day];
        long ans=0;
        ans++;
        if(day+forget<=n)
            ans--;
        for(int start=day+delay;start<(min(day+forget,n+1));start++){
            ans+=helper(start,n,delay,forget);
            ans%=m;
        }
        dp[day]=ans;
        return ans;
        
    }
};