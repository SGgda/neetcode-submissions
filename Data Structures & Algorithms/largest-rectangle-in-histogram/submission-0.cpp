class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int maxArea=0;
        int leftBoundary=0;
        for (int i = 0; i < heights.size(); i++) {
            
            while(!st.empty() && heights[i]<heights[st.top()]){
                int rightBoundary=i;
                int height=heights[st.top()];
                st.pop();
                if(st.empty()){
                   leftBoundary=-1;
                }else{
                     leftBoundary=st.top();
                }
                int width=rightBoundary-leftBoundary-1;
                int area=width*height;
                maxArea=max(area,maxArea);


            }
            st.push(i);
        }
        return maxArea;
    }
};