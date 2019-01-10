//Count the number of segments in a string, where a segment is defined
//to be a contiguous sequence of non-space characters.

class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0) return 0;
        
        int ans = 0;
        int ptr = 0;
        while(s[ptr] == ' ') ptr++;
        cout<<"Start at" << ptr<<endl;
        
        for(ptr; ptr < s.size(); ptr++){
            if(s[ptr] == ' ' && s[ptr-1] != ' '){
                ans++;
            }
        }
        if(s[s.size()-1] != ' ') ans++;
        return ans;
    }
};