#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		int head = 0;
		int tail = height.size() - 1;
		int water, max = 0;
		while (tail - head >= 1)
		{
			if (height[head] <= height[tail])
			{
				water = height[head] * (tail - head);
				head++;
			}
			else
			{
				water = height[tail] * (tail - head);
				tail--;
			}
			if (water > max)
				max = water;
		}
		return max;
	}
};
int main()
{
	Solution a;
	vector<int> c = { 1, 5, 3, 2, 8, 9, 4, 3, 5, 3, 6, 11, 33, 2, 2, 2222, 55, 3 };
	cout << a.maxArea(c);
	return 0;
}