#include <vector>

class Solution {
    template <typename C> bool isMatchChar(C s, C p) {
        return p == '.' || s == p;
    }
public:
    bool isMatch(string s, string p) {
        std::vector<bool> dp(s.size());
        dp.push_back(true);
        while (p.size()) {
            if (p.back() == '*') {
                p.pop_back(); // cannot have p == "***"
                auto itdp = dp.rbegin();
                for (auto its = s.crbegin(); its != s.crend(); ++its, ++itdp) {
                    itdp[1] = itdp[1] || *itdp && isMatchChar(*its, p.back());
                }
            } else {
                auto itdp = dp.begin();
                for (auto its = s.cbegin(); its != s.cend(); ++its, ++itdp) {
                    *itdp = itdp[1] && isMatchChar(*its, p.back());
                }
                dp.back() = false;
            }
            p.pop_back();
        }
        return dp[0];
    }
};