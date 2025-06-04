class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int n=nums.size();
        int ans;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(diff>abs(target-sum)){
                    diff=abs(target-sum);
                    ans=sum;
                }
                if(sum==target) return sum;
                else if(sum<target) j++;
                else k--;
            }
        }
        return ans;
    }
};