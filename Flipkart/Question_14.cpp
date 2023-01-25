// Custom Sort String

class Solution {
public:
    string customSortString(string S, string T) {
        
        unordered_set<int> s(S.begin(), S.end());
        unordered_map<char, int> m;
        
        for(auto& each: T)
            if(s.count(each))
                m[each]++;
                
        string str;
        for(auto& c: S) {
            int val=m[c];
            while(val--)
                str+=c;
        }
        
        for(auto& each: T)
            if(!s.count(each))
                str+=each;
            
        return str;
    }
};