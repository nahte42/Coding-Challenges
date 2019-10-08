class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == ""){
            if(needle == "")
                return 0;
            else
                return -1;
        }
        if(haystack == needle){
            return 0;
        }
        if(haystack.length() <= needle.length())
            return -1;

        for(int i = 0; i < haystack.length() - needle.length()+1; i++){
            if(needle == haystack.substr(i, needle.length()))
                return i;
        }
        return -1;
    }
};