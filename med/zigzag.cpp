class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string *con = new string[numRows];
        int i = 0; int j = 0;
        bool forW = true;
        bool bacW = false;
        
        while(j < s.length()){
            con[i] += s[j];
            if(forW){
                i++;
                if(i == numRows){
                    forW = false;
                    bacW = true;
                    i = numRows - 2;
                    j++;
                    continue;
                }
                j++;
            }
            if(bacW){
                i--;
                if(i == -1){
                    forW = true;
                    bacW = false;
                    i = 1;
                    j++;
                    continue;
                }
                j++;
            }
        }
        s = "";
        for(int k = 0; k < numRows; k++){
            s+=con[k];
        }
        
        return s;
    }
};