class Solution {
public:
    int myAtoi(string str) {
        if(str.length() == 0)
            return 0;
        
        string num = "";
        int myNum = 0;
        
        for(int i = 0; i < str.length(); i++){
            if(isalpha(str[i]) || str[i] == '.')
                return 0;
            if(str[i] == ' ' || str[i] == '+'){
                if(str[i] == '+' && !isdigit(str[i+1])){
                    return 0;
                }
                continue;
            }
            if(str[i] == '-'){
                if(!isdigit(str[i+1]))
                    return 0;
                num+=str[i];
                continue;
            }
            if(str[i] == '0' || str[i] == '+'){
                if(!isdigit(str[i+1]))
                    return 0;
                continue;
            }
            while(isdigit(str[i])){
                num+=str[i];
                i++;
            }
            break;
        }
        cout<<"num after while "<<num<<endl;
        cout<<num.length()<<endl;
        if(num.length() <= 1)
            if(!isdigit(num[0]))
                return 0;
        if(!isdigit(num[1]) && num.length() > 1){
            return 0;
            
        }
        if(num.length() == 10){
            if(stoi(num.substr(0,num.length()-1)) >= 214748364){
                if(stoi(num.substr(0,num.length()-1)) > 214748364){
                    return 2147483647;
                }
                if(stoi(num.substr(num.length()-1, 1))>=7)
                    return 2147483647;
            }
        }
        //cout<<num<<endl;
        if(num.length() >= 11){
            if(num[0] != '-')
                return 2147483647;
            if(num.length() > 11)
                return -2147483648;
            if(stoi(num.substr(0, num.length()-1)) <= -214748364){
                if(stoi(num.substr(0, num.length()-1)) < -214748364)
                    return -2147483648;
                if(stoi(num.substr(num.length()-1, 1)) >= 8)
                    return -2147483648;
            }
        }
        myNum = stoi(num);
        
        
        return myNum;
        
        
    }
};