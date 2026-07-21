import java.util.Arrays;
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int l = nums1.length + nums2.length;
        int []sorted = new int[l];
        for(int i=0;i<nums1.length;i++)
            sorted[i] = nums1[i];
        for(int j =0;j<nums2.length;j++)
            sorted[nums1.length + j] = nums2[j];
        Arrays.sort(sorted);
        if (l % 2 == 1)
            return (double)sorted[l/2];
        else
            return (double)(sorted[(l/2)-1] + sorted[l/2])/2.0;
        
    }
}