#include<iostream>
using namespace std;
class Solution {
public:
	int reverse(int x)
	{
		int res = 0;
		int tmp = res;
		while (x != 0)
		{
			res = res * 10 + x % 10;
			if (res / 10 != tmp)
				return 0;
			x = x / 10;
			tmp = res;
		}
		return res;
	}
};
int main()
{
	Solution a;
	cout<< a.reverse(123);
	return 0;
}