#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T> 
int add(T arr[], int& len, T v)
{
	arr[len]=v;
	len++;
	return len-1;
}

template <typename T>
void insert(T arr[], int& len, T v, int pos)
{
	for(int i=len-1;i>=pos;i--)
	{
		arr[i+1]=arr[i];
	}
	
	arr[pos]=v;
	len++;
}

template <typename T>
T remove(T arr[], int& len, int pos)
{
    T ret = arr[pos];
	for(int i=pos+1; i<len; i++)
	{
		arr[i-1]=arr[i];
	}
	
	len--;
	return ret;
}

template <typename T, typename K>
int find(T arr[], int len, K v, int cmpTK(T,K))
{
    int ret=-1;
    
    int pos=0;
    while( pos<len )
	{	
		T c2 = arr[pos]; 
		int c1 = cmpTK(c2,v);
		
		if( c1==0 )
		{
			ret=pos;
		}
		
    	pos++;
	}
	
	return ret;
}

template <typename T>
int orderedInsert(T arr[], int& len, T v, int cmpTT(T,T))
{
	int ret=0;
	
	int i=0;
	while( i<len )
	{
		T a1 = arr[i];
		T a2 = arr[i+1];
		
		if( cmpTT(a1,v)<0 && cmpTT(a2,v)>0 )
		{
			ret=i+1;
		}
		
		if( cmpTT(v,a1)>0 )
		{
			ret=i+1;
		}
		 
		 i++;
	}
	
	insert<T>(arr,len,v,ret);
	
    return ret;
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T,T))
{
	T aux;
	
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len-1;j++)
		{
			T a1 = arr[j];
			T a2 = arr[j+1];
			
			if( cmpTT(a1,a2)>0 )
			{
				aux = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = aux;
			}		
		}
	}
}

#endif
