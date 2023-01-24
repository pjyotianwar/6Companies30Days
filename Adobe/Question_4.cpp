// Magical String

class Solution {
public:
int magicalString(int n) {
    vector<char> s(n, 0);
    int i=0;
    int j=0;
    
    char c = 1;
    char groupCh = 1;
    int numc=0;
    int ans=0;
    while(numc < n) {
        s[i] = c;
        ans = (groupCh == 1) ? ans+c : ans;
        groupCh = 3 - groupCh;
        numc += c;
        ++i;
        if(numc >= n) break;
        if(s[j] == 2)  {
            s[i] = c;
            ans = (groupCh == 1) ? ans+c : ans;
            groupCh = 3 - groupCh;
            numc += c;
            ++i;
        }
        ++j;
        c = 3 - c;
    }
    if(numc > n && groupCh == 2) {
        ans -= (numc - n);
    }
    return ans;
}
};