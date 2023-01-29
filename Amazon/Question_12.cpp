// Maximum Length of Repeated Subarray

class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int answer = 0, n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> table(n1 + 1, vector<int>(n2+1, 0));
                              
    for(int i = n1 - 1; n1 ; i--, n1--) 
      for(int j = n2 - 1, jj = n2; jj ; j--, jj--)
        if (nums1[i] == nums2[j]){
          table[i][j] = table[n1][jj] + 1;
          answer = max( answer, table[i][j]);
        }
            
    return answer;
  }
};