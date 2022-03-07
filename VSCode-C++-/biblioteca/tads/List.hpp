#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
	Node<T>* p;
   Node<T>* aux;
   int leng;
   int pos;
};

template<typename T>
List<T> list()
{
   /*List<T> t;
   t.p=NULL;
   return t;*/
    List<T> x;
   x.p = NULL;
   x.aux = x.p;
   x.leng = 0;
   x.pos = 0;
   return x;
   
}

template<typename T>
T* listAdd(List<T>& lst,T v)
{
	T* t = NULL;
	t = new T();
	add<T>(lst.p,v);
	*t = v;
	return t;
}

template<typename T,typename K>
T listRemove(List<T>& lst,K k, int cmpTK(T,K))
{
	return remove<T>(lst.p,k,cmpTK);
}

template <typename T>
T listRemoveFirst(List<T>& lst){
    return removeFirst<T>(lst.aux);
}

template<typename T,typename K>
T* listFind(List<T> lst,K k, int cmpTK(T,K))
{
   T* t = NULL;
   t = new T();
   
   Node<T>* v = find<T,K>(lst.p,k,cmpTK);
   if(v!=NULL)
   {
		*t = v->info;
   }
   else
   {
		*t = NULL;
   }
   
   return t;
   
}

template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
	/*T* k = NULL;
	k = new T();
	
	Node<T>* v = orderedInsert<T>(lst.p,t,cmpTT);
	if(v!=NULL)
	{
		*k = v->info;
	}
	else
	{
		*k = NULL;
	}
	
    return k;*/
    
    Node<T>* x = orderedInsert<T>(lst.p,t,cmpTT);
   lst.aux = lst.p;
   T* y = &x->info;
   lst.leng++;
   return y;
    
}

template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
	sort<T>(lst.p,cmpTT);
}

template<typename T>
bool listIsEmpty(List<T> lst)
{
	bool n = true;
	if(lst.p!=NULL)
	{
		n=false;
	}
	return n;
}

template<typename T>
int listSize(List<T> lst)
{
	int i=0;
	while(lst.p!=NULL)
	{
		lst.p = (lst.p)->sig;
		i++;
	}
	return i;
}

template<typename T>
bool listHasNext(List<T>& lst)
{
   bool n = true;
   if(lst.p==NULL)
   {
		n=false;
   }
   return n;
}

template<typename T>
T* listNext(List<T>& lst)
{
   T* t = NULL;
   t = new T();
   *t = (lst.p)->info;
   lst.p = (lst.p)->sig;
   return t;
}

template<typename T>
void listReset(List<T>& lst)
{
	lst.aux = lst.p;
    lst.pos = 0;
}

template<typename T>
void listFree(List<T>& lst)
{
	while(lst.p!=NULL)
	{
		Node<T>* aux = lst.p;
		delete lst.p;
		lst.p = aux;
	}
}

#endif
