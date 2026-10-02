class Solution {
public:
    vector<string> result;
    string num;
    long long target;

    void backtrack(int idx, string expr, long long eval, long long last) {
        if (idx == (int)num.size()) {
            if (eval == target) result.push_back(expr);
            return;
        }

        long long cur = 0;
        for (int j = idx; j < (int)num.size(); j++) {
            // skip operands with leading zeros (but allow "0" itself)
            if (j > idx && num[idx] == '0') break;

            cur = cur * 10 + (num[j] - '0');
            string curStr = num.substr(idx, j - idx + 1);

            if (idx == 0) {
                // first operand: no operator in front
                backtrack(j + 1, curStr, cur, cur);
            } else {
                backtrack(j + 1, expr + "+" + curStr, eval + cur, cur);
                backtrack(j + 1, expr + "-" + curStr, eval - cur, -cur);
                backtrack(j + 1, expr + "*" + curStr,
                          eval - last + last * cur, last * cur);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;
        backtrack(0, "", 0, 0);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna