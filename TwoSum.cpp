#include<iostream>
#include<unordered_map>
#include<vector>
class solution
public:
	std::vector<int> twoSum(std::vector<int> &num, int target)
	{
		std::unordered_map<int, int> m;
		for (int i = 0; i < (int)num.size(); i++)
		{
			m[num[i]] = i;
		}
		int com;
		std::vector<int> ret;
		for (int i = 0; i < (int)num.size(); i++)
		{
			com = target - num[i];
			auto tmp = m.find(com);
			if (tmp != m.end() && (*tmp).second != i)
			{
				ret.push_back(i);
				ret.push_back((*tmp).second);
				return ret;
			}
		}
		return ret;
	}
};
int main()
{
	solution s;
	std::vector<int> num = { 2, 7, 11, 15 };
	std::vector<int> ret = s.twoSum(num, 18);
	return 0;
}