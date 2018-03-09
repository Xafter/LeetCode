#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();
		if (p.length() >= 2 && p[1] == '*')
		{
			bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
			return first_match && isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
		}
		else
		{
			bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
			return first_match && isMatch(s.substr(1), p.substr(1));
		}
	}
};
int main()
{
	Solution a;
	bool c = a.isMatch("aa", ".*");
	return 0;
}