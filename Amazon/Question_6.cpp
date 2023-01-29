// Maximum Subarray Min-Product

class Solution {
public:
    long long M = 1e9 + 7;
    int maxSumMinProduct(vector<int>& nums) {
        map<long long, long long> stick;
        vector<pair<int, int> > sortedArray(nums.size());
        vector<long long> prefix = {nums[0]};
        for(int i = 0; i < nums.size(); i++) {
            sortedArray[i] = {nums[i], i};
        }
        for(int i = 1; i < nums.size(); i++) {
            prefix.push_back(prefix.back() + (long long)nums[i]);
        }
        sort(sortedArray.begin(), sortedArray.end());
        long long ans = 0;
        for(auto [num, i] : sortedArray) {
            auto it = stick.lower_bound(i);
            int r = nums.size(); //right bound
            if(it != stick.end()) r = it->first;
            int l = -1;
            if(it != stick.begin()) {//left bound
                --it;
                l = it->first;
            }
            long long cur = (long long)num * (long long)(prefix[r - 1] - (l >= 0 ? prefix[l] : 0));
            ans = max(ans, cur);
            stick[i] = 1;
        }
        return ans % M;
    }
};