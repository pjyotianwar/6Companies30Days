// Maximum Points in an Archery Competition

class Solution {
public:
    int check(vector<int>&aliceArrows, int mask, int numArrows){
        int requiredArrows=0;
        int numberWon=0;
        for(int i=0;i<12;i++){
            if(mask&(1<<i)){
                numberWon+=i;
                requiredArrows+=aliceArrows[i]+1;
            }
        }
        if(requiredArrows<=numArrows)return numberWon;
        return 0;
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int maxBitmask=pow(2,12)-1;
        int relevantBitmask=-1;
        int maximumPoints=0;
        for(int i=1;i<=maxBitmask;i++){
            int currPoints=check(aliceArrows,i,numArrows);
            if(currPoints>maximumPoints){
                relevantBitmask=i;
                maximumPoints=currPoints;
            }
        }
        vector<int>ans(12,0);
        int totalSum=0;
        for(int i=0;i<12;i++){
            if(relevantBitmask & (1<<i)){
                ans[i]=aliceArrows[i]+1;
                totalSum+=ans[i];
            }
        }
        int remain=numArrows-totalSum;
        for(int i=0;i<12;i++){
            if(ans[i]==0){
                ans[i]=remain;
                break;
            }
        }
        return ans;
    }
};