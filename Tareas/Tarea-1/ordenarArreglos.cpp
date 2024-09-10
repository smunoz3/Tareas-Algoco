#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;
using namespace std::chrono;

// fuente: https://www.geeksforgeeks.org/merge-sort/
/*
Combina dos subarreglos ordenados en un único arreglo ordenado.

La función `merge` toma un arreglo `arr` y tres índices: `left`, `mid`, y `right`, 
que definen los límites de dos subarreglos ordenados dentro de `arr`. 
La función mezcla estos dos subarreglos en un solo subarreglo ordenado que reemplaza el contenido original del rango definido por `left` a `right`.
1. Calcula el tamaño de los dos subarreglos a mezclar (`L` y `R`).
2. Copia los elementos de los subarreglos de `arr` a dos vectores temporales `L` y `R`.
3. Compara y fusiona los elementos de `L` y `R` en el rango adecuado del arreglo `arr`.
4. Si quedan elementos en `L` después de la comparación, los copia al arreglo `arr`.
5. Si quedan elementos en `R` después de la comparación, los copia al arreglo `arr`.
*/
void merge(vector<int>& arr, int left,int mid, int right){ 
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// fuente: https://www.geeksforgeeks.org/merge-sort/
/*
Ordena un arreglo utilizando el algoritmo de ordenamiento Merge Sort.

La función `mergeSort` toma un arreglo `arr` y dos índices `left` y `right`, que definen el rango del subarreglo a ordenar. 
La función divide recursivamente el arreglo en mitades hasta que cada subarreglo contiene un solo elemento o está vacío,
 y luego combina estos subarreglos ordenados utilizando la función `merge`.

1. Verifica si el rango del subarreglo es válido (`left < right`). Si no es válido, retorna sin hacer nada.
2. Calcula el índice `mid`, que es el punto medio del subarreglo.
3. Llama recursivamente a `mergeSort` para ordenar la primera mitad del subarreglo (`left` a `mid`).
4. Llama recursivamente a `mergeSort` para ordenar la segunda mitad del subarreglo (`mid + 1` a `right`).
5. Fusiona los dos subarreglos ordenados en el rango definido utilizando la función `merge`.
*/
void mergeSort(vector<int>& arr, int left, int right){ 
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

//fuente: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
/*
Reorganiza un subarreglo alrededor de un pivote para el algoritmo de Quick Sort.

La función `partition` toma un arreglo `arr` y dos índices `low` y `high` que definen el rango del subarreglo a particionar. 
La función selecciona el último elemento del subarreglo como pivote,
 y reorganiza los elementos del subarreglo de manera que todos los elementos menores o iguales al pivote queden a su izquierda,
  y todos los elementos mayores queden a su derecha. Finalmente, coloca el pivote en su posición correcta y retorna su índice.

1. Selecciona el último elemento del subarreglo como el pivote (`pivot`).
2. Inicializa el índice `i` para rastrear la posición del último elemento menor o igual al pivote.
3. Recorre el subarreglo desde `low` hasta `high - 1`. Si un elemento es menor o igual al pivote, incrementa `i` y realiza un intercambio entre el elemento actual y el elemento en la posición `i`.
4. Coloca el pivote en la posición correcta (es decir, después del último elemento menor o igual al pivote) realizando un intercambio entre el pivote y el elemento en la posición `i + 1`.
5. Retorna el índice `i + 1`, que es la nueva posición del pivote en el subarreglo reorganizado.
*/

int partition(vector<int>& arr, int low, int high){ 
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//fuente: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
/*
Ordena un arreglo utilizando el algoritmo de Quick Sort.

La función `quickSort` toma un arreglo `arr` y dos índices `low` y `high` que definen el rango del subarreglo a ordenar. 
La función utiliza el algoritmo de Quick Sort para dividir el subarreglo en dos partes alrededor de un pivote, y luego aplica el algoritmo de forma recursiva a cada parte.

1. Verifica si el rango del subarreglo es válido (`low < high`). Si no es válido, retorna sin hacer nada.
2. Llama a la función `partition` para reorganizar el subarreglo alrededor de un pivote y obtener la posición del pivote (`pi`).
3. Llama recursivamente a `quickSort` para ordenar la parte del subarreglo a la izquierda del pivote (`low` a `pi - 1`).
4. Llama recursivamente a `quickSort` para ordenar la parte del subarreglo a la derecha del pivote (`pi + 1` a `high`).
*/

void quickSort(vector<int>& arr, int low, int high){ 
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//funte: https://cplusplus.com/forum/beginner/245026/
/*
Ordena un vector utilizando el algoritmo de Selection Sort.

La función `selectionSort` toma un vector `myVector` y el tamaño del vector `sizeOfVect`,
 y organiza los elementos del vector en orden ascendente utilizando el algoritmo de Selection Sort. 
El algoritmo busca el elemento más pequeño en el subarreglo no ordenado y lo intercambia con el primer elemento del subarreglo.

1. Itera sobre cada elemento del vector hasta el penúltimo (`i` desde `0` hasta `sizeOfVect - 2`).
2. Asume que el elemento actual (`i`) es el mínimo (`vectMin`).
3. Recorre el subarreglo restante (`j` desde `i + 1` hasta `sizeOfVect - 1`) para encontrar el índice del elemento más pequeño.
4. Si se encuentra un elemento más pequeño en el subarreglo, actualiza el índice del mínimo (`vectMin`).
5. Intercambia el elemento en la posición `i` con el elemento en la posición `vectMin`.
6. Repite el proceso hasta que todos los elementos del vector estén ordenados.
*/

void selectionSort(vector<int> myVector, int sizeOfVect){ 
    for (unsigned int i = 0; i < sizeOfVect - 1; i++){
        int vectMin = i;
        for (int j = i + 1; j < sizeOfVect; j++){
            if(myVector[j] < myVector[vectMin]){
                vectMin = j;
            }
        }
        int temp = myVector[i];
        myVector[i] = myVector[vectMin];
        myVector[vectMin] = temp;
    }
}


int main(){
    int N;
    cout << "Ingrese el tamaño de los arreglos: ";
    cin>>N;

    vector<int> array;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 99);
    for(int i=0;i<N;i++){
        array.push_back(distrib(gen));
    }

    vector<int> array1=array;
    vector<int> array2=array;
    vector<int> array3=array;
    vector<int> array4=array;

    auto start = high_resolution_clock::now();
    sort(array1.begin(), array1.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo del sort estandar: " << duration.count() << " microsegundos" <<endl;


    auto start2 = high_resolution_clock::now();
    mergeSort(array2, 0, N - 1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Tiempo del merge sort: " << duration2.count() << " microsegundos" <<endl;

    auto start3 = high_resolution_clock::now();
    quickSort(array3, 0, N - 1);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Tiempo del quick sort: " << duration3.count() << " microsegundos" <<endl;

    auto start4 = high_resolution_clock::now();
    selectionSort(array4, array4.size());
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << "Tiempo del selection sort: " << duration4.count() << " microsegundos" <<endl;
    return 0;
}