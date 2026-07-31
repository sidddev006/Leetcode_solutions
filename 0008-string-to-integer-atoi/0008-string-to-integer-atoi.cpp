class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long num = 0;
        int i = 0;
        int sign = 1;
        while (i < n) {
            if (s[i] == ' ')
                i++;
            else
                break;
        }
        if (i < n && s[i] == '-') {
                sign = -1;
                i++;
            } else if (i < n && s[i] == '+') {
                i++;
         }

        while (i < n && isdigit(s[i])) {
            if(sign == 1){
                if(num > INT_MAX/10 || (num == INT_MAX / 10 && (s[i] - '0') > 7))
                return INT_MAX;
            }
            else{
                if(num > INT_MAX/10 || (num == INT_MAX / 10 && (s[i] - '0') > 8))
                return INT_MIN;
            }
            num = num * 10 + (s[i] - '0');
            i++;
        }    
        
        return sign * num;
    }
};
