class Solution {
public:
    vector<int>NSL(vector<int>&a,int n){
        stack<pair<int,int>>st;
        vector<int>left(n);

        for(int i = 0;i < n;i++){
            while(!st.empty() && st.top().first>=a[i]){
                st.pop();
            }
            if(st.empty()) left[i] = -1;
            else left[i] = st.top().second;

            st.push({a[i],i});
        }
        return left;

    }  
    vector<int>NSR(vector<int>&a,int n){
        stack<pair<int,int>>st;
        vector<int>right(n);

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=a[i]){
                st.pop();
            }
            if(st.empty()) right[i] = n;
            else right[i] = st.top().second;

            st.push({a[i],i});
    } 
    return right;
    } 
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left = NSL(heights,n);
        vector<int>right = NSR(heights,n);

        int maxi = 0;
        for(int i = 0;i < n;i++){
            int width = right[i] - left[i] - 1;
            int area = heights[i]*width;

            maxi = max(maxi,area);
        }
        return maxi;
    }
};