class Solution {
public:

    int space(const string& s, int i) {
        if (i == s.size() || s[i] != ' ')
            return i;

        return space(s, i + 1);
    }

    long long digit(const string& s, int i, long long num, long long limit) {

        // Base case
        if (i == s.size() || !isdigit(s[i]))
            return num;

        int d = s[i] - '0';

        // Check overflow BEFORE num * 10
        if (num > limit / 10 ||
            (num == limit / 10 && d > limit % 10)) {
            return limit;
        }

        num = num * 10 + d;

        return digit(s, i + 1, num, limit);
    }

    int myAtoi(string s) {

        int n = s.size();
        int i = 0;

        // 1. Skip whitespace recursively
        i = space(s, i);

        // 2. Determine sign
        bool negative = false;

        if (i < n && s[i] == '-') {
            negative = true;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Choose magnitude limit
        long long limit = negative
                        ? 2147483648LL
                        : 2147483647LL;

        // 4. Recursively build the number
        long long num = digit(s, i, 0, limit);

        // 5. Apply sign
        if (negative)
            return (num == 2147483648LL)
                   ? INT_MIN
                   : -(int)num;

        return (int)num;
    }
};