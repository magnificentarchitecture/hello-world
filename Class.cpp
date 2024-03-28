#include "Class.h"
struct Link;
HanNoTa::HanNoTa(int n)
{
    Link* q1 = new Link(0);
    Link* q2 = new Link(0);
    Link* q3 = new Link(0);
    queue1 = q1;
    queue2 = q2;
    queue3 = q3;
    N_ = n;
}
int HanNoTa::isEmpty(Link* queue)
{
   return queue->next == nullptr ? 1 : 0;
}
int HanNoTa::isSmall(Link* queue,int data)
{
    queue = queue->next;
    if (queue->data_ <= data)
        return true;
    return false;
}
int HanNoTa::pop(Link* queue)
{
    int tmp = 0;
    if (isEmpty(queue) == 1)
        {
            return -1;
        }
        else {
            Link* head = queue->next;
            queue->next = head->next;
            tmp = head->data_;
            delete head;
           
        }
     return tmp;
}

bool HanNoTa::push(Link* queue, int data)
{
    if (isEmpty(queue) == 1)
    {
        Link* node = new Link(data);
        node->next = queue->next;
        queue->next = node;
        return true;
    }else
    if (isSmall(queue, data) == 1)
    {
        return false;
    }
    else {
        Link* node = new Link(data);
        node->next = queue->next;
        queue->next = node;
        return true;
    }
    
}
HanNoTa::Link* HanNoTa::the_next(int* order, int queue_num)
{
    int i;//��ʾջ˳��ĽǱ꣬queue_num��ʾ����ջ��������ʽ
    Link* queue;
    for (i = 0; i <= 2; i++)
    {
        if (order[i] == queue_num)
        break;
    }
    int j = order[(i+1)%3];//j��ʾ����ջ������
    switch (j)
    {
    case 1:
        queue = queue1;
        break;
    case 2:
        queue = queue2;
        break;
    case 3:
        queue = queue3;
        break;
    default:
        queue = queue1;
    }
    return queue;
}
int HanNoTa::the_next_num(int* order, int queue_num)//������
{
    int i;//��ʾջ˳��ĽǱ꣬queue_num��ʾ����ջ��������ʽ
    
    for (i = 0; i <= 2; i++)
    {
        if (order[i] == queue_num)
        break;
    }
    int j = order[(i+1)%3];//j��ʾ����ջ������
    return j;
}
int HanNoTa::which_push(Link* queue_now, int queue_num,int* order)
{
    //��֪������Ŀ��ջ��������ʽ�͵�ַ��������ջ�����е�˳��
    //��this ָ�����ǿ��Է������е�ջ
    Link* queue_base = this->the_next(order, queue_num);
    int queue_num1 = queue_num;
    int queue_num2;
    for (Link* queue = queue_base;; queue = this->the_next(order, queue_num1))
    {
        queue_num1 = this->the_next_num(order, queue_num1);
        queue_num2 = this->the_next_num(order, queue_num1);
        for (Link* queue_ = this->the_next(order, queue_num1); queue_ != queue; queue_ = this->the_next(order, queue_num2))
        {
            queue_num2 = this->the_next_num(order, queue_num2);
            if (isEmpty(queue) != 1)
            {
                if (isEmpty(queue_) == 1)
                {
                    push(queue_, queue->data_);
                    pop(queue);
                    return queue_num2;
                }else if(isSmall(queue_,queue->data_) == 0){
                    push(queue_, queue->data_);
                    pop(queue);
                    return queue_num2;
                }
            }
        }
    }
    return false;
}
