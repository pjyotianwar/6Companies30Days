// Rotate function

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size(), ans=INT_MIN, curr=0, sum=0;

        for(int i=0; i<n; i++){
            curr += i*nums[i];
            sum += nums[i];
        }

        for(int i=n-1; i>=0; i--){
            curr += sum - n * nums[i];
            ans = max(ans, curr);
        }

        return ans;
    }
};