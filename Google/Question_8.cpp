// Random Pick with Weight


class Solution {
    vector<int> m;
    random_device rd;
public:
    Solution(vector<int> w) {
        m = move(w);
        for (int i = 1; i < m.size(); ++i)
            m[i] += m[i-1];
    }
    int pickIndex() {
        return lower_bound(m.begin(), m.end(), rd() % m.back() + 1) - m.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */