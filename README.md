# Biblioteca_C++
## Introducción
Este es un proyecto realizado en la materia algoritmos y estructura de datos en la UTN.
Para esta materia se implemento las siguientes estructuras con sus repectivas funciones: Array, Map, List, Pilas y Colas.

## 1. Arrays  
El TAD Arr representa un array tipo T cuya capacidad física se incrementará automáticamente cuando su longitud (cantidad de elementos que contiene) se aproxime a la capacidad; dándole al usuario la “ilusión” de estar trabajando con una estructura
de datos dinámica.

### Ejemplo de creación  
```cpp
- `Arr<int> a = arr<int>();` 
- `**arrAdd<int>(a,10);`  
- `arrAdd<int>(a,20);`  
- `arrAdd<int>(a,30);`  
```
```diff
## 2. Mapas (`Map`)  
Un map consiste en una colección de pares {key, value}. Cada elemento (value) que agreguemos al map quedará vinculado a una clave (key) a través de la cual, posteriormente, podremos recuperarlo, modificarlo o eliminarlo.
NOTA in red: El tipo de dato de la clave (K) debe primitivo, string o cualquier otro cuya imple-mentación soporte el uso de los operadores relacionales
```

