#include<string>
#include<iostream>
using namespace std;
class Solution
{
public:
	int Myatoi(string str)
	{
		int res = 0;
		int tmp = res;
		bool flag = true;
		bool first = false;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ' && first == false)
				continue;
			if (str[i] == '+' && first == false)
			{
				first = true;
				continue;
			}
			if (str[i] == '-' && first == false)
			{
				first = true;
				flag = false;
				continue;
			}
			if (str[i] >= 0x30 && str[i] < 0x40)
			{
				if (flag)
				{
					res = res * 10 + str[i] - 0x30;
					if (res / 10 != tmp)
						return INT_MAX;
				}
				else
				{
					res = res * 10 - str[i] + 0x30;
					if (res / 10 != tmp)
						return INT_MIN;
				}
				tmp = res;
				continue;
			}
			break;
		}
		return res;
	}
};
int main()
{
	Solution a;
	cout << a.Myatoi("   -128") << endl;
	cout << a.Myatoi("   +128") << endl;
	cout << a.Myatoi("   -12 8") << endl;
	cout << a.Myatoi("   -124234324234234238**") << endl;
	cout << a.Myatoi("   +128432434234324243424  *") << endl;
	return 0;
}