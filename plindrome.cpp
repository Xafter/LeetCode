#include<string>
#include<iostream>
using namespace std;
class Solution
{
public:
	bool isPlindrome(int x)
	{
		if (x < 0)
			return false;
		int q = x;
		int tmp = 0;
		int rev = 0;
		while (q != 0)
		{
			rev = rev * 10 + q % 10;
			if (tmp != rev / 10)
				return false;
			tmp = rev;
			q = q / 10;
		}
		return x == rev;
	}
};
int main()
{
	int a = 12221;
	Solution x;
	cout << x.isPlindrome(a);
	return 0;
}