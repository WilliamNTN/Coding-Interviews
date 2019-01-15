//Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
// All four list have the same length

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.size() == 0) return 0;
        
        map<int,int> AB;
        int n = A.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                AB[A[i] + B[j]]++;
        

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans += AB[-(C[i]+D[j])];
        
        return ans;
    }
};