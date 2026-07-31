class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int conv = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == 'I'){
                if(i + 1 < n && s[i+1] == 'V'){
                    conv += 4;
                    i++;
                    continue;
                }
                else if(i + 1 < n && s[i+1] == 'X'){
                    conv += 9;
                    i++;
                    continue;
                }
                else conv += 1;
            } 
            else if(s[i] == 'V') conv += 5;
            else if(s[i] == 'X'){
                if(i + 1 < n && s[i+1] == 'L'){
                    conv += 40;
                    i++;
                    continue;
                }
                else if(i + 1 < n && s[i+1] == 'C'){
                    conv += 90;
                    i++;
                    continue;
                }
                else conv += 10;
            }
            else if(s[i] == 'L') conv += 50;
            else if(s[i] == 'C'){
                if(i + 1 < n && s[i+1] == 'D'){
                    conv += 400;
                    i++;
                    continue;
                }
                else if(i + 1 < n && s[i+1] == 'M'){
                    conv += 900;
                    i++;
                    continue;
                }
                else conv += 100;
            }
            else if(s[i] == 'D') conv += 500;
            else if(s[i] == 'M') conv += 1000;
        }
        return conv;
    }
};