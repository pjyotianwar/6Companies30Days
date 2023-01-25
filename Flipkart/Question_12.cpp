// Check If a String Contains All Binary Codes of Size K

class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        if(k > s.length())
        return false;
    
        unordered_map<string,int>mp;
    
        int start = 0, end = 0;
    
        string ans ="";
    
        while((end-start+1)<=k)
        {
            ans.push_back(s[end]);	   
            if((end-start+1)==k)
            break;
            end++;	
        }
        mp[ans]++;
        while(end<s.length())
        {
            end++;
            if(end >= s.length())
            break;
            
            ans.push_back(s[end]);
            string temp = ans.substr(1,ans.length());
            ans = temp;
            start++;
            mp[ans]++;
        }
        return mp.size() >= pow(2,k);
    }
};