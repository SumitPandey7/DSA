class Solution {
public:
    int largestArea(vector<int>&h){
        int n = h.size();
        vector<int>left(n),right(n);
        stack<pair<int,int>>st;
        for(int i = 0;i < n;i++){
            while(!st.empty() && st.top().first>=h[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top().second;
            }
        st.push({h[i],i});
    }
    while(!st.empty()){
        st.pop();
    }

    for(int i = n-1;i >= 0;i--){
            while(!st.empty() && st.top().first>=h[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n;
            }
            else{
                right[i] = st.top().second;
            }
        st.push({h[i],i});
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        int w = right[i]-left[i]-1;
        ans = max(ans,h[i]*w);
    }
    return ans;
}

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>h(m,0);
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == '1'){
                    h[j]++;
                }
                else{
                    h[j] = 0;
                }
            }
        ans = max(ans,largestArea(h));
        }
        return ans;
    }
};