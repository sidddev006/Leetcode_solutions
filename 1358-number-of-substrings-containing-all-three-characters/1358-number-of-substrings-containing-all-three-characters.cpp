class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count[3] = {0}; //0->a, 1->b, 2->c
        int left = 0;
        int total_count = 0;
        for(int right = 0; right < n; right++){
            count[s[right]-'a']++;
            while(count[0] > 0 && count[1] > 0 && count[2] > 0){
                total_count += n-right;
                count[s[left]-'a']--;
                left++;
            }
        }
        return total_count;
    }
};