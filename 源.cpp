#include <iostream>
#include <cmath>
#include <map>
#include "Class.h"
using namespace std;

int main()
{
	
	int n;
	cin >> n;
	HanNoTa test(n);
	map<string, int> map1;
	int order[3];
	if (n % 2 == 0)
	{
		order[0] = 1;
		order[1] = 2;
		order[2] = 3;
	}
	else {
		order[0] = 1;
		order[1] = 3;
		order[2] = 2;
	}
	for (int i = n; i >= 1; i--)
	{
		test.push(test.queue1, i);
	}
	int test_ = 1;//留存上一次是push的哪个栈
	for (int i = 0; i < exp2(n) - 1; i++)
	{
		if (test_ == 1)
		{
			test_ = test.which_push(test.queue1, 1, order);
			printf("1->%d   ", test_);
			if (test_ == 1)
			{
				printf("%d\n", test.queue1->next->data_);
			}
			else if (test_ == 2) {
				printf("%d\n", test.queue2->next->data_);
			}
			else {
				printf("%d\n", test.queue3->next->data_);
			}
		}
		else if (test_ == 2) {
			test_ = test.which_push(test.queue2, 2, order);
			printf("2->%d   ", test_);
			if (test_ == 1)
			{
				printf("%d\n", test.queue1->next->data_);
			}
			else if (test_ == 2) {
				printf("%d\n", test.queue2->next->data_);
			}
			else {
				printf("%d\n", test.queue3->next->data_);
			}
		}
		else if (test_ == 3) {
			test_ = test.which_push(test.queue3, 3, order);
			printf("3->%d  ", test_);
			if (test_ == 1)
			{
				printf("%d\n", test.queue1->next->data_);
			}
			else if (test_ == 2) {
				printf("%d\n", test.queue2->next->data_);
			}
			else {
				printf("%d\n", test.queue3->next->data_);
			}
		}

	}
	

	return 0;
}