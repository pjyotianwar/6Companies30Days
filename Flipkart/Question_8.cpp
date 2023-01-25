// Closest Prime Numbers in Range

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> arr;
        for(int i=left;i<=right;i++){
            bool flg = true;
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    flg = false;
                    break;
                }
            }
            if(flg && i!=1) arr.push_back(i);
        }
        int ind=0,mn=INT_MAX;
        if(arr.size()<2) return {-1,-1};
        for(int i=0;i<arr.size()-1;i++){
            if((arr[i+1]-arr[i])<mn){
                mn = (arr[i+1]-arr[i]);
                ind = i;
            }
        }
        return {arr[ind],arr[ind+1]};
    }
};