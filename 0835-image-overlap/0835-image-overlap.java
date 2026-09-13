class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        List<int[]>onesA = new ArrayList<>();
        List <int[]>onesB = new ArrayList<>();
        int n = img1.length;
        for(int i = 0; i<n;i++){
            for(int j = 0; j<n;j++){
                if(img1[i][j] == 1){
                    onesA.add(new int[]{i,j});
                }
                if(img2[i][j] == 1){
                    onesB.add(new int[]{i,j});
                }
            }
        }
        Map<Integer, Integer> offsetCount = new HashMap<>();
        int maxOverlap = 0;
        for(int[] a: onesA){
            for(int[] b: onesB){
                int dx = b[0]-a[0];
                int dy = b[1] - a[1];
                int key = (dx+30) * 61 +(dy+30);
                offsetCount.merge(key, 1, Integer::sum);
                maxOverlap = Math.max(maxOverlap, offsetCount.get(key));
            }
        }
        return maxOverlap;
    }
}