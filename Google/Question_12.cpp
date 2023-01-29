// Restore IP Addresses


class Solution {

    void help(vector<string>& ans, string cur, string s, int count){
        if(count == 4){
            if(s == "") ans.push_back(cur.substr(1));
            return;
        }
        if(s.size() >= 3 && s[0] != '0'){
            if(stoi(s.substr(0, 3)) <= 255)
                help(ans, cur + "." + s.substr(0, 3), s.substr(3), count + 1);
        }
        if(s.size() >= 2 && s[0] != '0') help(ans, cur + "." + s.substr(0, 2), s.substr(2), count + 1);
        if(s.size() >= 1) help(ans, cur + "." + s.substr(0, 1), s.substr(1), count + 1);
    }

public:

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        help(ans, "", s, 0);
        return ans;
    }
};