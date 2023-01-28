// Sort an Array

class Solution {
    void quickSort(vector<int>& nums, int s, int e) {
        if(s>=e) return;
        int l=s+1, r=e;
        while(l<r)
        {
            if(nums[l]<=nums[s]) l++;
            else if(nums[r]>nums[s]) r--;
            else swap(nums[l], nums[r--]);       
        } 
        if(nums[l]>nums[s]) l--;
        swap(nums[s], nums[l]);
        quickSort(nums, s, l-1);
        quickSort(nums, l+1, e);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};