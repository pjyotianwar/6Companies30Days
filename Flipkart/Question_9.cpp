// Top K Frequent Words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<string> ans, v;
        for(auto& w:words){
            if(!mp[w])
            v.push_back(w);
            mp[w]++;
        }

        sort(v.begin(), v.end(), [&](string& a, string& b){
            if(mp[a]==mp[b])
            return a<b;
            else
            return mp[a]>mp[b];
        });

        for(auto& w: v){
            if(k--)
            ans.push_back(w);
            else
            break;
        }

        return ans;
    }
};