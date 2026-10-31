class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(int i = 0;i < wordList.size();i++){
            st.insert(wordList[i]);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string s1 = q.front().first;
            int cnt = q.front().second;
            q.pop();

            for(int i = 0;i < s1.length();i++){
                char original = s1[i];

                for(char ch = 'a';ch <= 'z';ch++){
                    s1[i] = ch;

                    if(st.find(s1)!=st.end()){
                        if(s1 == endWord){
                            return cnt + 1;
                        }
                        st.erase(s1);
                        q.push({s1,cnt+1});
                    }
                }
                s1[i] = original;
            }
        }
        return 0;
    }
};