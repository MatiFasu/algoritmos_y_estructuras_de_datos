# Biblioteca_C++
## Introducción
Este es un proyecto realizado en la materia algoritmos y estructura de datos en la UTN.
Para esta materia se implemento las siguientes estructuras con sus repectivas funciones: Array, Map, List, Pilas y Colas.

## 1. Arrays  
El TAD Arr representa un array tipo T cuya capacidad física se incrementará automáticamente cuando su longitud (cantidad de elementos que contiene) 
se aproxime a la capacidad; dándole al usuario la “ilusión” de estar trabajando con una estructura de datos dinámica.

### Ejemplo de creación  
```cpp
- `Arr<int> a = arr<int>();` 
- `**arrAdd<int>(a,10);`  
- `arrAdd<int>(a,20);`  
- `arrAdd<int>(a,30);`  
```

## 2. Map
Un map consiste en una colección de pares {key, value}. Cada elemento (value) que agreguemos al map quedará vinculado a una clave (key)
a través de la cual, posteriormente, podremos recuperarlo, modificarlo o eliminarlo.
```diff
- NOTA: El tipo de dato de la clave (K) debe primitivo, string o cualquier otro cuya imple-mentación soporte
el uso de los operadores relacionales
```
### Ejemplo de creación  
```cpp
Map<string,int> m = map<string,int>();
mapPut<string,int>(m,"uno",1);
mapPut<string,int>(m,"dos",2);
mapPut<string,int>(m,"tres",3);
```

## 3. List  
Siendo p un Nodo* que contiene la dirección de memoria de un nodo, podemos imaginar una lista enlazada que se desprende a partir del nodo direccionado por p.
Observemos que el último nodo tiene, en su campo sig, el valor NULL (representado con un carácter X) indicando que dicho nodo contiene el último
elemento de la lista.

![imagen](https://github.com/user-attachments/assets/99221bdd-a8bb-4e9f-ad9b-19e9be8f5b0c)

### Ejemplo de creación  
```cpp
List<int> lst = list<int>();
listAdd<int>(lst,1);
listAdd<int>(lst,2);
listAdd<int>(lst,3);
```

### Stack y Queue
```cpp
Stack<int> st = stack<int>();
stackPush<int>(st,1);
stackPush<int>(st,2);
stackPush<int>(st,3);

while( !stackIsEmpty<int>(st) )
{
int e = stackPop<int>(st);
cout << e << endl; // Salida: 3,2,1
}

//***********************************

Queue<int> q = queue<int>();
queueEnqueue<int>(q,1);
queueEnqueue<int>(q,2);
queueEnqueue<int>(q,3);

cout << queueDequeue<int>(q) << endl; // Salida: 1
cout << queueDequeue<int>(q) << endl; // Salida: 2

queueEnqueue<int>(q,4);
queueEnqueue<int>(q,5);
while( !queueIsEmpty<int>(q) )
{
int e = queueDequeue<int>(q);
cout << e << endl; // Salida: 3,4,5
}

```


