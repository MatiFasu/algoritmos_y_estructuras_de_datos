#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template <typename T>
struct Arr
{
   T* array;
   int len;
   int cap;
};

template <typename T>
Arr<T> arr(int size)
{
   Arr<T> q;
   q.array = new T[size];
   q.len = 0;
   q.cap = size;
   return q;
}

template <typename T>
Arr<T> arr()
{
   Arr<T> q;
   q.cap = 10;
   q.len = 0;
   q.array = new T[q.cap];

   return q;
}

template <typename T>
void redimensionar(T*& array, int cap, int newCap) //duplico la capacidad del array
{
   T* arrayAux = new T[newCap];
   for( int i = 0; i<cap; i++ )
   {
      arrayAux[i] = array[i];
   }
   delete[] array;
   array = arrayAux;
}

template <typename T>
int arrAdd(Arr<T>& a, T v)
{
   if( a.cap>a.len )
   {
      int pos = add<T>(a.array,a.len,v);
      return pos;
   }
   else
   {
      int newCap = a.cap*2;
      redimensionar(a.array,a.cap,newCap);
      a.cap = newCap;
      int pos = add<T>(a.array,a.len,v);
      return pos;
   }
}

template <typename T>
T* arrGet(Arr<T> a, int p)
{
   T* pos = &a.array[p];
   return pos;
}

template <typename T>
void arrSet(Arr<T>& a, int p, T t)
{
   T* pos = arrGet<T>(a,p);
   *pos = t;
}

template <typename T>
void arrInsert(Arr<T>& a, T v, int p)
{
   if( a.cap>a.len )
   {
      insert<T>(a.array,a.len,v,p);
   }
   else
   {
      int newCap = a.cap*2;
      redimensionar(a.array,a.cap,newCap);
      a.cap = newCap;
      insert<T>(a.array,a.len,v,p);
   }

}

template <typename T>
int arrSize(Arr<T> a)
{
   return a.len;
}

template <typename T>
T arrRemove(Arr<T>& a, int p)
{
   T t = remove<T>(a.array,a.len, p);
   return t;
}

template <typename T>
void arrRemoveAll(Arr<T>& a)
{
   a.len = 0;
}

template <typename T, typename K>
int arrFind(Arr<T>& a, K k, int cmpTK(T, K))
{
   int pos = find<T,K>(a.array,a.len,k,cmpTK);
   return pos;
}

template <typename T>
int arrOrderedInsert(Arr<T>& a, T t, int cmpTT(T, T))
{
   sort<T>(a.array,a.len,cmpTT);
   return orderedInsert<T>(a.array,a.len,t,cmpTT);
}

template <typename T>
void arrSort(Arr<T>& a, int cmpTT(T, T))
{
   sort<T>(a.array,a.len,cmpTT);
}

#endif
