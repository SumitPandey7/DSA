class Solution {
    unordered_map<string,int>mpp;
    vector<vector<string>>ans;
    string b;
private:
    void dfs(string word,vector<string>&seq){
        if(word == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mpp[word];
        int n = word.size();
        for(int i = 0;i < n;i++){
            char original = word[i];
            for(char c = 'a';c <= 'z';c++){
                word[i] = c;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1 == steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        b = beginWord;
        q.push({beginWord});
        int m = beginWord.size();
        st.erase(beginWord);
        mpp[beginWord] = 0;
        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word == endWord) break;
            for(int i = 0;i < m;i++){
                char original = word[i];
                for(char c = 'a';c<='z';c++){
                    word[i] = c;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps+1;
                    }
                }
             word[i] = original;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>seq = {endWord};
            dfs(endWord,seq);
        }
        return ans;
    }
};