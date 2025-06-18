class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i=i+3){
            vector<int>group={nums[i],nums[i+1],nums[i+2]};
            if(group[2]-group[0]>k){
                return {};
            }
            ans.push_back(group);
        }
        return ans;

    }
};