class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0) {
            res.push_back("");
            return res;
        }
        res.push_back("(");
        vector<int> p;//number of right brackets - number of left brackets
        p.push_back(-1);
        vector<int> left;//number of left brackets can be use
        left.push_back(n-1);
        n = 2*(n-1);
        for(int i = 1;i<=n;i++){
            int l = res.size();
            for(int j = 0;j<l;j++){
                if(p[j]==0) {
                    res[j]+='(';
                    left[j]--;
                    p[j]--;
                }
                else{
                    if(left[j]>0){
                        res.push_back(res[j]+'(');
                        left.push_back(left[j]-1);
                        p.push_back(p[j]-1);
                    }
                    res[j]+=')';
                    p[j]++;
                }
            }
        }
        for(int j = 0;j<res.size();j++)
            res[j]+=')';
        return res;
    }
};