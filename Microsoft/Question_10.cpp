// Shortest Unsorted Continuous Subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int res = 0,start= 0,end = 0;
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(nums[i] != temp[i])
            {
                start = i;
                break;
            }
        }
        for(int i = nums.size()-1 ; i >= 0 ; i--)
        {
        
            if(nums[i] != temp[i])
            {
                end = i;
                break;
            }
        }
        if(end < start || end  == start || start < 0) 
            return 0;
        res = end -start + 1;
        return res;
    }
};