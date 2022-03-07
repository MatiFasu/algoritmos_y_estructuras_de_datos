#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
	Node<T>* p;
};

template<typename T>
Queue<T> queue()
{
	Queue<T> t;
	t.p=NULL;
    return t;
}

template<typename T>
T* queueEnqueue(Queue<T>& q,T v)
{
	T* t = NULL;
	t = new T();
	enqueue<T>(q.p,v);
	*t = v;
	return t;
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
   return dequeue<T>(q.p);
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
   return q.p==NULL?true:false;
}

template<typename T>
int queueSize(Queue<T> q)
{
	return listSize<T>(q.p);
}

#endif
