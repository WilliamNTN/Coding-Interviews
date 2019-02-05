/*
 Given n pairs of parentheses, write a function to generate all
 combinations of well-formed parentheses.
 For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    
    void solve(int nOpen, int nClose, string soFar, vector<string>& vec){
        if(nOpen == 0 && nClose == 0){
            vec.push_back(soFar);
            return;
        }
        
        if(nOpen == nClose){
            return solve(nOpen-1,nClose,soFar + '(', vec);
        }
        else{
            if(nOpen){
                solve(nOpen-1,nClose,soFar+'(',vec);
            }
            solve(nOpen,nClose-1,soFar+')',vec);
        }
        return;
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,n,"",ans);
        return ans;
    }
};