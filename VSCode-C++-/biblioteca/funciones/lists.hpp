#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T> 
struct Node
{
	T info;
	Node<T>* sig;
};

template <typename T> Node<T>* add(Node<T>*& p, T x)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = x;
   nuevo->sig = NULL;
   
   if( p!=NULL )
   {
		Node<T>* aux = p;
		while( aux->sig!=NULL )
		{
			aux = aux->sig;
		}
		
		aux->sig = nuevo;    
   }
   else
   {
		p = nuevo;
   }
   
   return nuevo;
}

template <typename T> Node<T>* addFirst(Node<T>*& p,T e)
{
	Node<T>* nuevo = new Node<T>();
	nuevo->info = e;
	nuevo->sig = NULL;
	
	if( p!=NULL )
	{
		nuevo->sig = p;
		p = nuevo;
	}
	else
	{
		p = nuevo;
	}
	
	return nuevo;
}

template <typename T> void free(Node<T>*& p)
{
	while( p!=NULL )
	{
		Node<T>* aux = p->sig;
		delete p;
		p = aux;
	}
}

template <typename T, typename K>
Node<T>* find(Node<T>* p, K v, int cmpTK(T,K) )
{
    Node<T>* aux = p;
	while( aux!=NULL && cmpTK(aux->info,v)!=0  )
	{
		aux = aux->sig;
	}
	
	return aux;
}

template <typename T, typename K>
T remove(Node<T>*& p, K v, int cmpTK(T,K))
{
	T t;
	Node<T>* aux=p;
	Node<T>* ant=NULL;
	
	while( aux!=NULL && cmpTK(aux->info,v)!=0)
	{
		ant = aux;
		aux = aux->sig;
	}
	
	if( ant==NULL )
	{
		p = aux->sig;
	}
	else
	{
		ant->sig = aux->sig;
	}
	
	t = aux->info;
	delete aux;
		
	return t;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   T t;
   
   Node<T>* aux = p;
   t = aux->info;
   p = aux->sig;
   
   delete aux;
   
   return t;
}

template <typename T>
void insertFirst(Node<T>*& p, T v)
{
	Node<T>* nuevo = new Node<T>();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	if( p!=NULL )
	{
		nuevo->sig = p;
		p = nuevo;
	}
	else
	{
		p = nuevo;
	}
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T v, int cmpTT(T,T) )
{
	Node<T>* nuevo = new Node<T>();
	nuevo->info = v;
	
	Node<T>* aux = p;
	Node<T>* aux2 = p;
	Node<T>* ant = NULL;
	while( aux!=NULL && cmpTT(aux->info,v)<0 )
	{
		ant = aux;
		aux = aux->sig;
	}
	
	while( aux2!=NULL && cmpTT(aux2->info,v)>0 )
	{
		remove<T>(p,aux2->info,cmpTT);
		aux2 = aux2->sig;
	}
	
	if( ant==NULL)
	{
		nuevo->sig = p;
		p = nuevo;
	}
	else
	{
		ant->sig = nuevo;
		if( aux==NULL )
		{
			nuevo->sig = NULL;
		}
		else
		{
			nuevo->sig = aux;
		}
	}
	
	return nuevo;
}

template <typename T> 
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
	Node<T>* ret = new Node<T>();
	Node<T>* v = find<T,T>(p,e,cmpTT);
	T t;
	if(v!=NULL)
	{
		enc=true;
		ret = v;
	}
	else
	{
		enc=false;
		orderedInsert(p,e,cmpTT);
	}
	
	return ret;
}

template <typename T>
void sort(Node<T>*& p, int cmpTT(T,T))
{
	Node<T>* aux = p;
	while( aux!=NULL )
	{
		Node<T>* j = aux->sig;
		while( j!=NULL )
		{
			if( cmpTT(aux->info,j->info)>0 )
			{
				T t = j->info; 
				j->info = aux->info; // 2
				aux->info = t; //1
			}
			
			j = j->sig;
		}
		
		aux = aux->sig;
	}
}

template <typename T> bool isEmpty(Node<T>* p)
{
   bool n;
   
   if(p!=NULL)
   {
   		n=false;
   }
   else
   {
   		n=true;
   }
   
   return n;
}

template <typename T>  
Node<T>* push(Node<T>*& p, T v)
{
	Node<T>* nuevo = new Node<T>();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
	return nuevo;
}

template <typename T> 
T pop(Node<T>*& p)
{
    Node<T>* aux = p;
	p = p->sig;
	T v = aux->info;
	delete aux;
	return v;
}

template <typename T>
Node<T>* enqueue(Node<T>*& p, Node<T>*& q, T v)
{
	Node<T>* nuevo = new Node<T>();
	nuevo->info = v;
	nuevo->sig = NULL;
	if( q!=NULL )
	{
		q->sig = nuevo;
	}
	else
	{
		p = nuevo;
	}
	
	q = nuevo;
	
	return nuevo;
}

template <typename T> //sobrecarga
Node<T>* enqueue(Node<T>*& q,T e)
{
	Node<T>* nuevo = new Node<T>();
	nuevo->info = e;
	
	if( q!=NULL )
	{
		nuevo->sig = q->sig;
		q->sig = nuevo;
	}
	else
	{
		nuevo->sig=nuevo;
	}
	
	q = nuevo;
	
	return nuevo;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T ret = p->info;
   Node<T>* aux = p;
   p = p->sig;
   delete aux;
   
   if(p==NULL)
   {
		q=NULL;
   }
   	
   return ret;
}

template <typename T> //sobrecarga
T dequeue(Node<T>*& q)
{
	Node<T>* aux = q->sig;
	q->sig = aux->sig;
	T ret = aux->info;
	
	if( aux==q )
	{
		q = NULL;
	}
	
	delete aux;
	return ret;
}

#endif
