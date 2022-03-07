#include <iostream>

#include "biblioteca\funciones\arrays.hpp"
#include "biblioteca\funciones\files.hpp"
#include "biblioteca\funciones\lists.hpp"
#include "biblioteca\funciones\strings2.hpp"
#include "biblioteca\funciones\tokens.hpp"

#include "biblioteca\tads\Arr.hpp"
#include "biblioteca\tads\Map.hpp"
#include "biblioteca\tads\List.hpp"
#include "biblioteca\tads\Queue.hpp"
#include "biblioteca\tads\Stack.hpp"

#include "main.hpp"
#include<math.h>
#include <stdlib.h>

using namespace std;

void eliminarRepetidos(Arr<int>& ar)
{
    for(int i=0; i<arrSize<int>(ar); i++)
    {
        for(int j=0; j<arrSize<int>(ar); j++)
        {
            int* v1 = arrGet<int>(ar,i);
            int* v2 = arrGet<int>(ar,j);

            if( *v1 == *v2 && i!=j )
            {
                //cout<< *v1 <<", "<< *v2 <<endl;
                arrRemove<int>(ar,j);
            }

        }
    }
}

int main()
{   
    Arr<int> ar = arr<int>();
    arrAdd<int>(ar,1);
    arrAdd<int>(ar,2);
    arrAdd<int>(ar,3);
    arrAdd<int>(ar,3);
    arrAdd<int>(ar,4);
    arrAdd<int>(ar,5);
    arrAdd<int>(ar,5);
    arrAdd<int>(ar,2);
    arrAdd<int>(ar,6);
    arrAdd<int>(ar,7);
    arrAdd<int>(ar,1);

    eliminarRepetidos(ar);

    cout<<"\nArray:"<<endl;
    for(int i=0; i<arrSize(ar); i++)
    {
        int* v = arrGet<int>(ar,i);
        cout<< *v <<endl;
    }

    return 0;
}