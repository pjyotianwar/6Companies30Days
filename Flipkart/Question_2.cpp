// Shopping Offers

class Solution {
public:
    unordered_map<string,int> dp;
    Solution()
    {
        dp.clear();
    }
    string Key(vector<int>& a)
    {
        string t="";
        for(auto x:a)
        {
            t+=to_string(x);
            t+="#";
        }
        //cout<<t<<endl;
        return t;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
         int c=0;
        for(auto x:needs)
        {
            if(x>0) c++;
        }
        if(c==0) return 0;
        string key=Key(needs);
        if(dp.find(key)!=dp.end()) return dp[key];
        int val=0;
        int n=needs.size();
        for(int i=0;i<n;i++)
        {
            val+=needs[i]*price[i];
        }
        for(auto offer:special)
        {
            vector<int> supply(offer.begin(),offer.end()-1);
            int cost=offer.back();
            int flag=0;
            vector<int> new_need(n);
            for(int i=0;i<n;i++)
            {
                if(needs[i]<offer[i])
                {
                    flag=1;
                    break;
                }
                new_need[i]=needs[i]-supply[i];
            }
            if(flag==1)
                continue;
            val=min(val,cost+shoppingOffers(price,special,new_need));
        }
        return dp[key]=val;
    }
};