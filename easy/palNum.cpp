#include<vector>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int y = x;
        vector<int> rev;
        while(y != 0){
            rev.push_back(y%10);
            y=y/10;
        }
        
        for(int i = 0; i < rev.size()/2; i++){
            if(rev[i] != rev[rev.size()-1-i])
                return false;
        }
        
        return true;
    }
};