//Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0) return ans;
        
        vector<int> first(1,1);
        ans.push_back(first);
        int lastInserted = 0;
        for(int i = 1; i<numRows; i++){
            vector<int> vec;
            vec.push_back(1);
            for(int j = 1; j<i; j++)
                vec.push_back(ans[lastInserted][j-1] + ans[lastInserted][j]);
            vec.push_back(1);
            ans.push_back(vec);
            lastInserted++;
        }
        return ans;
    }
};