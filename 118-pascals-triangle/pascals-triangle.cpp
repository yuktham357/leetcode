class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int rows=1;
        for(int i=1;i<=numRows;i++){
            vector<int>row;
            int col=1;
            row.push_back(1);
            for(int j=1;j<i;j++){
                col=col*(i-j);
                col=col/j;
                row.push_back(col);
            }
            ans.push_back(row);
        }
        return ans;
    }
};