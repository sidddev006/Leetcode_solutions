class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxL = 0, maxR = 0;
        int water = 0;
        while(left < right){
            if(height[left] < height[right]){
                maxL = max(maxL, height[left]);
                water += maxL - height[left];
                left++;
            }
            else{
                maxR = max(maxR, height[right]);
                water += maxR - height[right];
                right--;
            }
        }
        return water;
    }
};