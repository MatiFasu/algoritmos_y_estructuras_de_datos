
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Arr.hpp"

using namespace std;

template<typename K,typename T>
struct Map
{
	Arr<K> key;
	Arr<T> value;
	int cont;
};

template<typename K,typename T>
Map<K,T> map()
{
	Map<K,T> x;
	x.key = arr<K>();
	x.value = arr<T>();
	x.cont = 0;
	return x;
}

template <typename K>
int cmpKeyKey(K u, K v)
{
   return u<v?-1:u>v?1:0;
}

template<typename K,typename T>
T* mapGet(Map<K,T>& m,K k)
{
   int pos = arrFind<K, K>(m.key,k,cmpKeyKey);
   if( pos>=0 )
   {
      T* x = arrGet<T>(m.value,pos);
      return x;
   }
   else
   {
      return NULL;
   }
}

template<typename K,typename T>
T* mapPut(Map<K,T>& m,K k,T v)
{
   int pos = arrFind<K, K>(m.key,k,cmpKeyKey);
   if( pos<0 )
   {
      pos=arrAdd<K>(m.key,k);
      pos=arrAdd<T>(m.value,v);
   }
   else
   {
      arrSet<T>(m.value,pos,v);
   }
   return mapGet<K, T>(m,k);
}

template<typename K,typename T>
bool mapContains(Map<K,T>& m,K k)
{
	/*bool n = false;
	
	for(int i=0; i<arrSize<K>(m.key); i++)
	{
		K* comp = arrGet<K>(m.key,i);
		if( *comp==k )
		{
			n = true;
		}
	}
	
	return n;*/
	
	int pos = arrFind<K, K>(m.key,k,cmpKeyKey);
    return pos>=0?true:false;
}

template<typename K,typename T>
T mapRemove(Map<K,T>& m,K k)
{
   int pos = arrFind<K, K>(m.key,k,cmpKeyKey);
   K rk = arrRemove<K>(m.key,pos);
   T rt = arrRemove<T>(m.value,pos);
   return rt;
}

template<typename K,typename T>
void mapRemoveAll(Map<K,T>& m)
{
	arrRemoveAll<K>(m.key);
	arrRemoveAll<T>(m.value);
}

template<typename K,typename T>
int mapSize(Map<K,T> m)
{
   return arrSize(m.key);
}

template<typename K,typename T> 
bool mapHasNext(Map<K,T>& m)
{
   bool n = true;
   if( m.cont==mapSize<K,T>(m))
   {
   		n=false;
   }
   return n;
}

template<typename K,typename T> 
K mapNextKey(Map<K,T>& m)
{
	K* k = arrGet<K>(m.key,m.cont);
	m.cont++;
	
    return *k;
}

template<typename K,typename T> 
T* mapNextValue(Map<K,T>& m)
{
   T* t = arrGet<T>(m.value,m.cont);
   m.cont++;
   
   return t;
}


template<typename K,typename T> 
void mapReset(Map<K,T>& m)
{
	m.cont=0;
}

template<typename K,typename T> 
void mapSortByKeys(Map<K,T>& m,int cmpKK(K,K))
{
	arrSort<K>(m.key,cmpKK);
}

template<typename K,typename T> 
void mapSortByValues(Map<K,T>& m,int cmpTT(T,T))
{
	arrSort<T>(m.value,cmpTT);
}

#endif
