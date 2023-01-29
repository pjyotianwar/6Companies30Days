// Shuffle an Array

class Solution {
    vector<int>nums;
public:
    Solution(vector<int> nums) {
        this->nums=nums;
        srand((unsigned)time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int>res(nums.begin(),nums.end());
        for(int i=0;i<res.size();i++)
            swap(res[i],res[rand()%res.size()]);
        return res;
    }
};