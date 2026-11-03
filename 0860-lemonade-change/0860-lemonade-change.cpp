class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for(int bill: bills){
            if(bill == 5) five++;
            else if(bill == 10){
                if(five >= 1){
                   five--;
                   ten++;
                }
                else return false;
            }
            else{
                if(ten >= 1 && five >=1){
                    ten--; five--;
                    twenty++;
                }
                else if(five >= 3) five-=3;
                else return false;
            }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna