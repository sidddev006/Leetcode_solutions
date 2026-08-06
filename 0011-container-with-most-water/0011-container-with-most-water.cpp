class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int answer = 0;
        while(left < right){
            int area = (right - left) * min(height[left], height[right]);
            answer = max(area, answer);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return answer;
    }
};