//Count the number of prime numbers less than a non-negative number, n.


class Solution {
public:
    
    vector<bool> sieveOfEratosthenes(int n){
        vector<bool> isPrime(n+1,true);
        isPrime[2] = true;
        for(int i = 2; i*i <= n; i++){
            if(isPrime[i]){
                for(int j = i*i; j <= n; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        
        return isPrime;
    }
    int countPrimes(int n) {
        if(n <=1) return 0;
        vector<bool> isPrime = sieveOfEratosthenes(n);
        int ans = 0;
        for(int i = 2; i<n; i++)
            if(isPrime[i]) ans++;
        return ans;
    }
};