class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int area=0;
        int j = (int)height.size()-1;
        int s=0;
        while(i!=j)
        {
            s = height[i]>=height[j]?((j-i)*height[j--]):(j-i)*height[i++];
            area = s>area?s:area;
        
        }
        return area;
    }
};