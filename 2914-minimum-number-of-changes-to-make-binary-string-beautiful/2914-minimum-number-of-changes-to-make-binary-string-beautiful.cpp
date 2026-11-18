class Solution {
public:
    int minChanges(string s) {
        char curr = s[0];

        int cnt = 0;
        int mini = 0;

        for(int i = 0;i < s.length();i++){
            if(s[i]==curr){
                cnt++;
                continue;
            }

            if(cnt%2==0){
                cnt = 1;
            }
            else{
                cnt = 0;
                mini++;
            }
            curr = s[i];
        }
        return mini;
    }
};