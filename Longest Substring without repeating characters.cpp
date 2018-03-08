#include<iostream>
#include<string>
#include<memory>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		int count = 0;
		int start = 0;
		int ret = 0;
		bool canUse[256];
		memset(canUse, true, sizeof(canUse));
		for (int i = 0; i < s.length(); i++)
		{
			if (canUse[s[i]])
			{
				canUse[s[i]] = false;
				count++;
			}
			else
			{
				ret = max(ret, count);
				while (true)
				{
					canUse[s[start]] = true;
					if (s[start] == s[i])
						break;
					start++;
				}
				canUse[s[i]] = false;
				count = i - start;
				start++;
				ret = max(ret, count);
			}
			ret = max(ret, count);
		}
		return ret;
	}
};
int main()
{
	Solution a;
	cout<<a.lengthOfLongestSubstring("tmmzuxt");
	system("pause");
	return 0;
}