class Solution {
public:

string longestCommonPrefix(vector<string>& strs) 
{
    string prefix;
    if(strs.size() == 0)
        return "";
    if(strs.size() == 1)
        return strs[0];
    prefix = compare(strs[0], strs[1]);
    if(prefix == "")
        return "";
    else
        for(int i = 1; i < strs.size(); ++i)
        {
            prefix = compare(prefix, strs[i]);
            if(prefix == "")
                return "";
        }
    return prefix;
}
string compare(string &s1, string &s2)
{
    string prefix;
    for(int i = 0; i<s1.size() && i<s2.size(); ++i)
    {
        if(s1[i] == s2[i])
            prefix += s1[i];
        else
            return prefix;
    }
    return prefix;
}
};