class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int u = st.top();
                st.pop();
                int v = st.top();
                st.pop();
                st.push(v + max(2 * u, 1));
            }
        }
        return st.top();
    }
};