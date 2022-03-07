#include <iostream>
using namespace std;

#include "biblioteca/funciones/arrays.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/lists.hpp"
#include "biblioteca/funciones/strings2.hpp"
#include "biblioteca/funciones/tokens.hpp"

#include "biblioteca/tads/Arr.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Stack.hpp"

bool esAlfabeto(string k)
{
    bool ret;

    char c = stringToChar(k);

    if (length(k)==1 && ( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ) )
    {
        ret = true;
    }
    else
    {
        ret = false;
    }

    return ret;
}

string separarPalabras(string& s)
{
    int pos = indexOf(s, ' ');

    string k = substring(s, 0, pos);

    s = substring(s, pos + 1);
    
    if (tokenCount(s, ' ') == 1)
    {
        s = s + " ";
    }
    if (tokenCount(s, ' ') == 0)
    {
        s = "";
    }

    return k;
}


int main()
{
    Map<string, int> m = map<string, int>();

    string s = "hola foca hola tornado foca hola tornado chau chau";

    int cont = 1;

    while( !isEmpty(s) )
    {

        string k = separarPalabras(s);

        if (mapContains<string, int>(m, k))
        {
            int* v = mapGet<string, int>(m, k);

            *v = *v + 1;
        }
        else
        {
            cont = 1;
            mapPut<string, int>(m, k, cont);
        }

    }

    cout << endl;
    while (mapHasNext<string, int>(m))
    {
        string k = mapNextKey<string, int>(m);
       
        cout << k << " -> ";

        int* v = mapGet<string, int>(m, k);

        cout << *v << endl;
    }


}