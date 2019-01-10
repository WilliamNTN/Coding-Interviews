//Given two arrays A and B of equal size, the advantage of A with respect to
//B is the number of indices i for which A[i] > B[i].

//Return any permutation of A that maximizes its advantage with respect to B.

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        map<int,int> inA;
        vector<int> ans(A.size());
        for(int i = 0; i < A.size(); i++)
            inA[A[i]]++;
        
        
        for(int i = 0; i < B.size(); i++){
            int key = B[i];
            map<int,int>::iterator it = inA.upper_bound(key);
            if(it != inA.end()){
                ans[i] = it->first;
                if(it->second > 1) it->second--;
                else inA.erase(it);
            }
            else{
                ans[i] = inA.begin()->first;
                if(inA.begin()->second > 1) inA.begin()->second--;
                else inA.erase(inA.begin());
            }
        }
        
        return ans;
    }
};