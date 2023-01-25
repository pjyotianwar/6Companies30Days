// Find in Mountain Array

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &a) {
        int res=-1;
        int n=a.length();
        int max_index=0;
        
        // binary search to find index of peak
        int left=0,right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            
            if(mid==0){
                mid=1;
            }
            if(mid==n-1){
                mid=n-2;
            }
            
            int num1=a.get(mid-1),num2=a.get(mid),num3=a.get(mid+1);
            
            if(num2>num1 && num2>num3){
                max_index=mid;
                break;
            }
            
            if(num1<num2 && num2<num3){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        
        if (a.get(max_index)==target){
            return max_index;
        }
        
        
        //binary search on asceding subarray
        left=0;
        right=max_index-1;
        
        while(left<=right){
            int mid=(left+right)/2;
            
            int num=a.get(mid);
            
            if(num==target){
                res=mid;
                break;
            }
            
            if(target>num){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        
        if(res!=-1){
            return res;
        }
        
        
        //binary search on desceding subarray
        left=max_index+1;
        right=n-1;
        
        while(left<=right){
            int mid=(left+right)/2;
            
            int num=a.get(mid);
            
            if(num==target){
                res=mid;
                break;
            }
            
            if(target<num){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
            
        return res;
    }
	
};