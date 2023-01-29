// Last Moment Before All Ants Fall Out of a Plank

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        if(left.size()) {
            int t = *max_element(left.begin(), left.end());
            res = t;
        }
        if(right.size()) {
            int t = *min_element(right.begin(), right.end());
            res = max(res, n-t);
        }
        
        return res;
    }
};