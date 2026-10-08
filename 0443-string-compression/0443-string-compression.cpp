class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        vector<char> ans;
        int i = 0;

        while (i < n) {
            ans.push_back(chars[i]);

            int j = i + 1;

            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            if (j - i > 1) {
                string s = to_string(j - i);

                for (char c : s) {
                    ans.push_back(c);
                }
            }

            i = j;
        }

        for (i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }

        return ans.size();
    }
};