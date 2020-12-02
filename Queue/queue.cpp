#include <iostream>
#include "queue.h"
using namespace std;

void Queue::Push(int item) {
    if (Full())
    {
        cout << "ť�� ���� á���ϴ�." << endl;
        return;
    }
    if (!head) //head�� tail�� null�� ��,
    {
        head = tail = new Node(item);  // 
        //cout << Number() << " - " << item << endl;
        return;
    }
    tail->next = new Node(item);
    tail = tail->next;
}

int Queue::Pop() {
    if (Empty())
    {
        cout << "ť�� ����ֽ��ϴ�." << endl;
        return -1;
    }
    int ret = head->data;
    Node* n = head->next;
    delete head;
    head = n;
    return ret;
}
int Queue::Number() {
    Node* t = head;
    int count = 0;
    while (t)
    {
        t = t->next;
        count++;
    }
    return count;
}

int Queue::Empty() {
    return (Number() == 0);
}

int Queue::Full() {
    return(Number() == Queuesize);
}