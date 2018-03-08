#include<map>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	map<int, string> M;
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		int T = 2 * numRows - 2;
		for (int i = 0; i<s.length(); i++)
		{
			if (i%T < numRows)
				M[i%T] += s[i];
			else
				M[numRows - 1 - (i%T - numRows + 1)] += s[i];
		}
		string ret = "";
		for (int i = 0; i<numRows; i++)
		{
			ret += M[i];
		}
		return ret;
	}
};

int main()
{
	Solution a;
	cout<<a.convert("wocanima", 3);
	return 0;
}