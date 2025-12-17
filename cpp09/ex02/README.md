The merge insertion sort / Ford Johnson Algorithm

basado en la estrategia fundamental de Divide y Vencerás del Merge Sort,
que es la base que usted debe modificar para integrar la inserción (el componente "Insert" del Ford-Johnson):
Pseudocódigo Conceptual de la Ordenación por Mezcla (Merge Sort)
El algoritmo se compone de dos funciones principales: la función recursiva MERGESORT (división) y la función MERGE (fusión).


1. Función MERGESORT (Divide)
Esta función divide continuamente la secuencia:
MERGESORT(Arreglo A, índice p, índice r):
  SI p < r ENTONCES
    // 1. Encontrar el punto medio
    q = (p + r) / 2 

    // 2. Dividir: Llamada recursiva a la mitad izquierda
    MERGESORT(A, p, q) [2]

    // 3. Dividir: Llamada recursiva a la mitad derecha
    MERGESORT(A, q + 1, r) [2]

    // 4. Conquistar/Fusionar las mitades ordenadas
    MERGE(A, p, q, r) [3], [4]
El paso de división continúa hasta que las sub-secuencias contienen solo elementos individuales.

2. Función MERGE (Fusión y Ordenación)
Esta función toma dos sub-arreglos ordenados (izquierdo y derecho) y los combina en una única secuencia ordenada.
MERGE(Arreglo A, índice p, índice q, índice r):
  // 1. Crear sub-arreglos temporales L y R
  n1 = q - p + 1 (Tamaño del sub-arreglo izquierdo)
  n2 = r - q (Tamaño del sub-arreglo derecho)
  
  Crear Arreglo L[1...n1] y Arreglo R[1...n2]

  // 2. Copiar datos a L y R
  Para i = 1 hasta n1:
    L[i] = A[p + i - 1]
  Para j = 1 hasta n2:
    R[j] = A[q + j]

  // 3. Comparar y fusionar los sub-arreglos temporales
  i = 1 // Índice inicial de L
  j = 1 // Índice inicial de R
  k = p // Índice inicial del arreglo principal A

  Mientras i <= n1 Y j <= n2:
    SI L[i] <= R[j] ENTONCES
      A[k] = L[i]
      i = i + 1
    SI NO
      A[k] = R[j]
      j = j + 1
    k = k + 1

  // 4. Copiar cualquier elemento restante (si L o R no están vacíos)
  Mientras i <= n1:
    A[k] = L[i]
    i = i + 1
    k = k + 1

  Mientras j <= n2:
    A[k] = R[j]
    j = j + 1
    k = k + 1

*+-
El Paso Clave del Ford-Johnson
La diferencia entre el Merge Sort estándar y el Merge-Insert Sort (Ford-Johnson) radica en cómo se manejan las secuencias pequeñas.
El Ford-Johnson típicamente utiliza el algoritmo de ordenación por inserción (Insertion Sort) para sub-secuencias de tamaño muy pequeño, ya que Insertion Sort es más eficiente que Merge Sort en esas condiciones. Además, el Ford-Johnson utiliza una técnica de inserción binaria específica para reinsertar elementos.