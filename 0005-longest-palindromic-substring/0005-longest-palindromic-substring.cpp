class Solution {
public:
    // Time complexity is O(n2) and space complexity is O(1)
    string expand(int left, int right, const string& s) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        int len = right - left - 1;
        return s.substr(left + 1, len);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = s.substr(0, 1);
        for (int i = 0; i < n; i++) {
            string odd = expand(i, i, s);
            string even = expand(i, i + 1, s);
            if (odd.size() > ans.size())
                ans = odd;
            if (even.size() > ans.size())
                ans = even;
        }
        return ans;
    }
};