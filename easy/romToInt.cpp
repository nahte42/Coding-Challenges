class Solution {
public:
     int romanToInt(string s) {
        // Rule:
        // 'I'= 1, 'X' = 10,'C' = 100, 'M' = 1000, 'V' = 5, 'L' = 50, 'D' = 500;
        // Adjacent(Left) >= Adjacent(Right): Right + Left;
        // Adjacent(Left) < Adjacent(Right): Right - Left;
        unordered_map<char,int>m({{'I',1}, {'X',10}, {'C',100}, {'M',1000}, {'V',5}, {'L',50}, {'D',500}});
        if(s.size()==0) return 0;
        string::iterator r=s.end()-1;
        string::iterator l=r-1;
        int sum=m[*r];
        while(r-s.begin()>=0){
           if(m[*r]<=m[*l]) sum+=m[*l];
           else sum-=m[*l];
           l--;
           r--;
        }
        return sum;
    }
};