class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        
        
    // Step 1: find all divisors of k
    vector<int> divisors;
    for (int i = 1 ;i<= sqrt(k);i++){
        if (k % i == 0){
            divisors.push_back(i);
            if (i != k / i)
                divisors.push_back(k / i);
        }
    }

    // Step 2: bucket each number by gcd(num, k)
    
    unordered_map<long long, long long> cnt;
    for (int num : nums){
        int g = gcd(num, k);
        cnt[g] += 1;
    }

    // Step 3: for every pair of divisors, check compatibility
    long long ans = 0;
    for (int d1 : divisors){ 
        for (int d2 : divisors){
            if (d1 > d2) continue;          // avoid checking both (d1,d2) and (d2,d1)
            if ((1LL*d1 * d2) % k != 0) continue;

            if (d1 == d2)
                ans += cnt[d1] * (cnt[d1] - 1) / 2;   // choose 2 distinct indices from same bucket
            else
                ans += cnt[d1] * cnt[d2];             // every element in bucket d1 pairs with every element in bucket d2
        }
    }

    return ans;
        
    }
};