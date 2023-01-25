// Distant Barcodes

class Solution {
    typedef pair<int, int> pii;
    
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> count(10001, 0);
        for (int n : barcodes) count[n]++;
        priority_queue<pii, vector<pii>> maxQ;
        for (int n : barcodes) {
            if (count[n]) {
                maxQ.push({count[n], n});
                count[n] = 0;
            }
        }
        pii prev = {-1, 0};
        int i = 0;
        while (!maxQ.empty()) {
            auto t = maxQ.top();
            maxQ.pop();
            barcodes[i++] = t.second;
            if (prev.first > 0)
                maxQ.push(prev);
            (t.first)--;
            prev = t;
        }
        return barcodes;
    }
};