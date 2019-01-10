//Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process:
// Starting with any positive integer, replace the number by the sum
// of the squares of its digits, and repeat the process until the number
// equals 1 (where it will stay), or it loops endlessly in a cycle which does
// not include 1. Those numbers for which this process ends in 1 are happy numbers.

class Solution {
public:
    
    int generate(int n){
        int result = 0;
        
        while(n != 0){
            result += pow(n%10,2);
            n /=10;
        }
        return result;
    }
    bool isHappy(int n) {
//         Space: O(n) solution
//         set<int> seen;
//         seen.insert(n);
        
//         while(n != 1){
//             n = generate(n);
//             if(seen.find(n) != seen.end()) break;
//             seen.insert(n);
//         }
        
//         return n == 1;
        
        // O(1) space solution
        // Find cycle in linked list
        
        int slow, fast;
        slow = fast = n;
        while(fast != 1){
            slow = generate(slow);
            fast = generate(generate(fast));
            
            if(slow == fast) break;
        }
        
        return fast == 1;
    }
};