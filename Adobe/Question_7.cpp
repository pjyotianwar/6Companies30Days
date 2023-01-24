// Number of Matching Subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=s.length(), ans=0;
        map<string, int> mp;
        string w;
        for(auto& w: words){
            mp[w]++;
        }
        for(auto& m: mp){
            w = m.first;
            int i=0, j=0, wl=w.length();
            while(i<n && j<wl){
                if(s[i]==w[j]){
                    j++;
                }
                i++;
            }
            if(j==wl)
            ans+=m.second;
        }
        return ans;
    }
};