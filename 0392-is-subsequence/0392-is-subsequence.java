class Solution {
    public boolean isSubsequence(String s, String t) {
        int r1 = s.length();
        int r2 = t.length();
        int l1 = 0,l2 = 0;
        while(l1 < r1 && l2 < r2){
            if(s.charAt(l1) == t.charAt(l2)){
                l1++;
            }
            l2++;
        }
        return l1 == r1;
    }
}