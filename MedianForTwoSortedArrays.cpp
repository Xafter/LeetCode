#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int m = nums1.size();
		int n = nums2.size();
		if (m>n)
			return findMedianSortedArrays(nums2, nums1);
		int lo = 0;
		int hi = 2 * m;
		int c1, c2, L1, L2, R1, R2 = 0;
		while (hi >= lo)
		{
			c1 = (lo + hi) / 2;
			c2 = m + n - c1;
			L1 = c1 == 0 ? -37767 : nums1[(c1 - 1) / 2];
			L2 = c2 == 0 ? -32767 : nums2[(c2 - 1) / 2];
			R1 = c1 == 2 * m ? 65535 : nums1[c1 / 2];
			R2 = c2 == 2 * n ? 65535 : nums2[c2 / 2];
			if (L1>R2)
				hi = c1 - 1;
			else if (L2>R1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(L1, L2) + min(R1, R2)) / 2.0;
	}
};
int main()
{
	Solution a;
	vector<int>nums1 = { 1, 2 };
	vector<int>nums2 = { 3, 4 };
	double r = a.findMedianSortedArrays(nums1, nums2);
	return 0;
}