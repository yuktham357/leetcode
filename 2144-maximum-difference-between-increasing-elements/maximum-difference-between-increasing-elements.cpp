class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int x=nums[0];
        int mini=-1;
        for(int i=0;i<n;i++){
            int j=nums[i];
            if(j<=x) x=j;
            else mini=max(mini,j-x);
        }
        return mini;
    }
};