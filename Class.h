#ifndef _CLASS_H_
#define _CLASS_H_
#include <cstring>
class HanNoTa {
	struct Link {
		int data_;
		Link* next;
		Link(int data) : data_(data),next(nullptr)
		{

		}

	};
public:
	HanNoTa(int n);
	
	~HanNoTa()
	{

	}
	bool push(Link* queue, int data);
	int pop(Link* queue);
	int isEmpty(Link* queue);
	int isSmall(Link* queue,int data);
	int which_push(Link* queue_now,int queue_num,int* order);//包括pop现有的push进入下一个
	Link* the_next(int* order, int queue_num);
	int the_next_num(int* order, int queue_num);
	public:
	Link* queue1;
	Link* queue2;
	Link* queue3;
	int N_;
};

#endif

