#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() == 1)
			return s;
		bool **P = new bool *[s.length()];
		for (int i = 0; i<s.length(); i++)
		{
			P[i] = new bool[s.length()];
		}
		int max = 0;
		string res;
		for (int i = 0; i<s.length(); i++)
			P[i][i] = true;
		for (int i = 0; i<s.length(); i++)
		for (int j = 0; j <= i; j++)
		{
			if (i - j <= 1)
				P[j][i] = (s[i] == s[j]);
			else
			{
				P[j][i] = (P[j + 1][i - 1] && (s[i] == s[j]));
			}
			if (i - j + 1>max && P[j][i])
			{
				max = i - j + 1;
				res = s.substr(j, max);
			}
		}
		return res;
	}
};
class Solution1 {
public:
	string longestPalindrome(string s) {
		int len = 2*s.length() - 1;
		int center = 0;
		int radius = 0;
		int start = 0;
		int end = 0;
		int max = 0;
		string res;
		for (center = 0; center < len; center++)
		{
			for (radius = 0; center - radius >= 0 && center + radius < len;)
			{
				if (center % 2 != 0 && radius == 0)
				{
					radius += 1;
					continue;
				}
				if (s[(center - radius) / 2] == s[(center + radius) / 2])
				{
					radius += 2;
				}
				else
					break;
			}
			start = (center - radius + 2) / 2;
			end = (center + radius - 2) / 2;
			if (end - start + 1 > max)
			{
				max = end - start + 1;
				res = s.substr(start, max);
			}
		}
		return res;
	}
};
int main()
{
	Solution1 a;
	cout<<a.longestPalindrome("baac");
	string c = "abc";
	string d = "def";
	cout<<c + d[1];
	return 0;
}