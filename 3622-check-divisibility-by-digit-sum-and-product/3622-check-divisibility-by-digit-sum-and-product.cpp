class Solution {
public:
    /*
    at first i have to calculate the digit sum and then the product of digits and then add them and then see if they are divisible by n
    */
    bool checkDivisibility(int n) {
        int temp = n;
        int sum_digits = 0;
        int pro_digits = 1;
        while(temp != 0){
            int digit = temp%10;
            sum_digits += digit;
            pro_digits *= digit;
            temp /= 10;
        }
        int summation = sum_digits+pro_digits;
        return n% summation == 0;
    }
};