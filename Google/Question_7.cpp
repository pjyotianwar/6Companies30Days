// K Divisible Elements Subarrays


class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<string> s;

        for(int i=0;i<n;i++)
        {
            int count=0;
            int sum=0;
            string str="";
            for(int j=i;j<n;j++)
            {
                str+=to_string(nums[j]);
                str+='.';
                if(nums[j]%p==0)count++;
                if(count>k) break;
                s.insert(str);
            }
        }
        return s.size();
    }
};