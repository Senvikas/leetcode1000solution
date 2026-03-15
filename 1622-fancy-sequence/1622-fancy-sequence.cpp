class Fancy {
public:
    vector<long long> seq;
    vector<long long> multInv; // store inverse multipliers
    long long mod = 1e9+7;
    long long add = 0, mult = 1;

    // fast exponentiation for modular inverse
    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        // store normalized value
        long long inv = modPow(mult, mod-2); // modular inverse of current mult
        seq.push_back(((val - add + mod) % mod * inv) % mod);
        multInv.push_back(inv);
    }

    void addAll(int inc) {
        add = (add + inc) % mod;
    }

    void multAll(int m) {
        mult = (mult * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (seq[idx] * mult + add) % mod;
    }
};