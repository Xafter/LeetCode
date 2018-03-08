#include<iostream>

struct ListNode
{
	ListNode(int d=0, ListNode *n = NULL)
	{
		digit = d;
		next = n;
	}
	int digit;
	ListNode* next;
};
class solution
{
public:
	ListNode* AddTwoNumbers(ListNode *a, ListNode *b)
	{
		ListNode *p1 = a;
		ListNode *p2 = b;
		ListNode *head = new ListNode;
		ListNode *p = head;
		ListNode *pre = p;
		int c = 0;//½øÎ»
		while (p1 != NULL || p2 != NULL)
		{
			int x = p1 == NULL ? 0 : p1->digit;
			int y = p2 == NULL ? 0 : p2->digit;
			int sum = x + y + c;
			c = sum / 10;
			p->digit = sum % 10;
			p->next = new ListNode;
			pre = p;
			p = p->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		delete p;
		pre->next = NULL;
		return head;
	}
};
int main()
{
	int tmp1[3] = { 8, 5, 1 };
	int tmp2[3] = { 7, 5 };
	ListNode *a = new ListNode(8);
	ListNode *b = new ListNode(7);
	ListNode *t1 = a;
	ListNode *t2 = b;
	for (int i = 1; i < 3; i++)
	{
		t1->next = new ListNode(tmp1[i]);
		t2->next = new ListNode(tmp2[i]);
		t1 = t1->next;
		t2 = t2->next;
	}
	solution s;
	ListNode* ret = s.AddTwoNumbers(a, b);
	return 0;
}