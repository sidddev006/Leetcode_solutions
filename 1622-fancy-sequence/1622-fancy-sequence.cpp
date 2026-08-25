class Fancy {
public:
    const long long MOD = 1e9 + 7;
    vector<long long> base;   // value "normalized" back to what it would've been at mult=1, add=0
    long long mult = 1, add = 0;

    Fancy() {}

    long long power(long long a, long long b, long long mod) {
        long long res = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long a, long long mod) {
        return power(a, mod - 2, mod); // Fermat's Little Theorem, valid since mod is prime
    }

    void append(int val) {
        // val = base * mult + add (mod p)  -->  base = (val - add) * inverse(mult) (mod p)
        long long b = ((val - add) % MOD + MOD) % MOD;
        b = (b * modInverse(mult, MOD)) % MOD;
        base.push_back(b);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mult = (mult * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx < 0 || idx >= (int)base.size()) return -1;
        return (int)((base[idx] * mult + add) % MOD);
    }
};