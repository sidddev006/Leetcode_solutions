class Solution {
public:
    long long sumAndMultiply(int n) {
        long long non_zero = 0;
        long long temp = n;
        long long sum_digit = 0;
        long long pow10 = 1;
        while(temp != 0){
            long long digit = temp%10;
            sum_digit += digit;
            if(digit > 0) {
                non_zero += digit * pow10;
                pow10 *= 10;
            }
            temp /= 10;
        }
        return non_zero * sum_digit;
    }
};
