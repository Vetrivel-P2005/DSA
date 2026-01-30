class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int n = height.size();
        int i=0,j=n-1;
        while(i<j){
            int h = min(height[i],height[j]);
            int area = h*(j-i);
            max_area = max(area,max_area);
            if(height[i]<height[j]){
                ++i;
            }else{
                --j;
            }
        }
        return max_area;
    }
};