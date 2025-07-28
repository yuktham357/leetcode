class Solution {
public:
    int n;
    int helper(vector<int>&nums, int maxi, int curr,int i){
        if(i>=n){
            if(maxi==curr) return 1;
            return 0;
        }
        int t=helper(nums,maxi,nums[i]|curr,i+1);
        int s=helper(nums,maxi,curr,i+1);
        return t+s;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        int  maxi=0;
        for(int i=0;i<n;i++){
            maxi=maxi|nums[i];
        }
        return helper(nums,maxi,0,0);
    }
};