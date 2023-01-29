// Maximum Sum of an Hourglass

class Solution {
public:
    int maxSum(vector<vector<int>>& Mat) {
        int N = Mat.size(),  M = Mat[0].size();
        
        if(N<3 || M<3) return -1;  // Matrix is not 3x3 then return -1 

        int ans=INT_MIN;

        for(int i=0;i<=N-3;i++){
            for(int j=0;j<=M-3;j++){
                int sum=0;
                // here sum of upper and lower row
                for(int k=j;k<j+3;k++)
                    sum+=Mat[i][k]+Mat[i+2][k];  
                // adding middle el in that sum
                sum+=Mat[i+1][j+1];               
                ans=max(ans,sum); 
            }
        }
        return ans;
    }
};