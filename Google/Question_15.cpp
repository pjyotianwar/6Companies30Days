// Maximum Compatibility Score Sum


class Solution {
public:
   int dp[10];
    int comp(vector<vector<int>>& students, vector<vector<int>>& mentors,int i,int j){
        int k,l,count=0;
        for( k=0;k<students[i].size();k++){
            if(students[i][k]==mentors[j][k])
                count++;
        }
        return count;
    }
    int find(vector<vector<int>>& students, vector<vector<int>>& mentors,int ind){
        if(ind==students.size())
            return 0;
        int ans=-1;
       
         for(int j=0;j<students.size();j++){
         if(dp[j]==0){
             dp[j]=1;
            ans=max(comp(students,mentors,ind,j)+find(students,mentors,ind+1),ans);
             dp[j]=0;
             }
         }
         return ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
         return find(students,mentors,0);
        
    }
};