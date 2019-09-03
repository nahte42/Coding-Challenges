class Solution {
public:
	vector<string> letterCombinations(string digits) {
		const char *tab[] = { "abc", "def", "ghi", "jkl", "nmo", "pqrs", "tuv", "wxyz" };
		string tmp;
        if(digits.empty()) return res;
		dfs(digits, 0, tmp, tab);
		return res;
	}
private:
	vector<string> res;
	void dfs(string &digits, int idx, string tmp,const char **tab)
	{
		if (idx == digits.size())
		{
			res.push_back(tmp);
			return;
		}
		int cnt = digits[idx] - '2';
		int n = strlen(tab[cnt]);
		for (int i = 0; i < n; i++)
		{
			tmp += tab[cnt][i];
			dfs(digits, idx + 1, tmp,tab);
			//unmake
			tmp.pop_back();
		}
	}
};