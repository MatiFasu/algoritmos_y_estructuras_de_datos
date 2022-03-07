#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
	Node<T>* p;
};

template<typename T>
Stack<T> stack()
{
	Stack<T> t;
	t.p=NULL;
    return t;
}

template<typename T>
T* stackPush(Stack<T>& st,T v)
{
	T* t = NULL;
	t = new T();
	push<T>(st.p,v);
	*t=v;
	return t;	
}

template<typename T>
T stackPop(Stack<T>& st)
{
   T t = pop<T>(st.p);
   return t;
}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return st.p==NULL?true:false;
}

template<typename T>
int stackSize(Stack<T> s)
{
 	int i=0;
	Node<T>* aux = s.p;
	while(aux!=NULL)
	{
		aux = aux->sig;
		i++;
	}
	return i;
}

#endif
