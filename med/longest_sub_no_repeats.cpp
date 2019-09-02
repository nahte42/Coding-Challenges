void clear_vec(vector<int> &checkRep){
    for(int i = 0; i < checkRep.size(); i++){
        checkRep[i] = 0;
    }  
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};