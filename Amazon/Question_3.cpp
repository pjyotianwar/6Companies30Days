// Split a String Into the Max Number of Unique Substrings

class Solution {
public:
    unordered_set<string> umap;
    int dfs(string &s, int pos){
        if(pos==s.length())
            return 0;
        string tmp = "";
        int ans = 0;
        for(int i=pos;i<s.length();i++){
            tmp+=s[i];
            if(umap.find(tmp)==umap.end()){
                umap.insert(tmp);
                ans=max(ans,1+dfs(s,i+1));
                umap.erase(tmp);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        return dfs(s,0);
    }
};