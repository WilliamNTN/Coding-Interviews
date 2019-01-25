
//implement strStr() (indexOF)  
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.size() == 0) return 0;
        if(haystack.size() == 0) return -1;
        if(needle.size() > haystack.size()) return -1;
        //brute-force
        int ptr = 0;
        while(ptr < haystack.size()-needle.size()+1){
            
            bool verify = 1;
            for(int i = 0; i < needle.size(); i++){
                if(haystack[i+ptr] != needle[i]){
                    verify = 0; break;
                }
            }
            if(verify) return ptr;
            ptr++;
        }
        
        return -1;
    }

    //TODO: KMP
};