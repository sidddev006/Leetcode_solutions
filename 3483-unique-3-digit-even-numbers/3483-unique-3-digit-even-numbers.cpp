class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {0};
        for(int d:digits) cnt[d]++;
        int ans = 0;
        for(int a = 1; a<=9;++a){
            for(int b=0; b<=9;++b){
                for(int c=0; c<=9;c++){
                    if(c %2 != 0) continue;
                    int need[10] = {0};
                    need[a]++; need[b]++; need[c]++;
                    bool ok = true;
                    for(int v= 0; v<10&&ok;v++){
                        if(need[v] > cnt[v]) ok = false;
                    }
                    if(ok) ans++;
                }
            }
        }
        return ans;
    }
};