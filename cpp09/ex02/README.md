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



test : !!!!!!!!!!!!!!!!!!

Exercise 02 PmergeMe
Regular cases
Small list

Input: 3 5 9 7 4

Expected:

Before: 3 5 9 7 4

After: 3 4 5 7 9

Two timing lines for the two containers used.

Already sorted

Input: 1 2 3 4 5

Check: algorithm handles best-case quickly.

Reverse sorted

Input: 5 4 3 2 1

Check: algorithm handles worst-case.

Edge cases
Single element

Input: 42

Expected: Before: 42 After: 42 timings small.

Even and odd counts

Input: test with n=2, n=3, n=4, n=5 to ensure pairing logic in Ford-Johnson works.

Duplicates

Input: 3 3 2 2 1 1

Check: decide and document duplicate handling; algorithm must still sort.

Large input near limit

Input: 3000 unique integers

Check: memory usage, correctness, and timing differences between containers.

Invalid inputs and error messages
Negative or zero

Input: -1 2 or 0 5

Expected: Error (subject shows Error for -1).

Non-integer token

Input: 1 2 a

Expected: Error.

Too many arguments or empty

Input: no args

Expected: Error.

Performance and measurement
Timing reproducibility

Check: measure total time including parsing and data structure setup, not only the core sort. Use std::chrono::high_resolution_clock. Print microsecond or nanosecond precision.

Two containers

Check: implement algorithm separately for both containers (e.g., std::vector<int> and std::deque<int>). Ensure you do not reuse containers from previous exercises.

Stability and memory

Check: Ford-Johnson is comparison-based; ensure memory footprint is reasonable for 3000 elements.

Implementation checks
Correct Ford-Johnson implementation

Check: pairing, sorting pairs, inserting pendants in correct order. Provide comments in code explaining each step for reviewers.

Separate implementations

Check: avoid a single templated function if the subject advises separate implementations.

Timing output format

Check: match required lines and include container name in the message