#include <iostream>
#include <chrono>
#include <cstdlib> 
#include <ctime>

using namespace std;
using namespace std::chrono;

// https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
/*
La función `multiplicarMatricesTradicional` multiplica dos matrices cuadradas (de tamaño n x n) de manera tradicional, utilizando tres bucles anidados.

1. La función utiliza tres bucles anidados:
   - El primer bucle (índice `i`) itera sobre las filas de la matriz A.
   - El segundo bucle (índice `j`) itera sobre las columnas de la matriz B.
   - El tercer bucle (índice `k`) se utiliza para calcular el producto y acumulación de los elementos correspondientes de la fila de A y la columna de B.
   
2. Inicialmente, se establece cada elemento de la matriz de salida `C[i][j]` en 0.

3. Luego, se realiza la multiplicación de cada elemento correspondiente de la fila `i` de A con la columna `j` de B y se suma al valor acumulado de `C[i][j]`.

4. Al final, la matriz C contiene el resultado de la multiplicación matricial de A * B.
*/

void multiplicarMatricesTradicional(int** A, int** B, int** C, int n) { 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/*
La función `transponeMatriz` realiza la transposición de una matriz cuadrada (de tamaño n x n) en su lugar, es decir, sin necesidad de utilizar una matriz auxiliar.

Funcionamiento:
1. Se utilizan dos bucles anidados:
   - El primer bucle (índice `i`) itera sobre las filas de la matriz.
   - El segundo bucle (índice `j`) itera sobre las columnas, comenzando desde `i + 1` para evitar repetir o sobreescribir elementos innecesariamente, ya que la matriz transpuesta intercambia los elementos de la posición `[i][j]` con `[j][i]`.
   
2. Para cada par de elementos que no están en la diagonal principal, se realiza el intercambio:
   - Se almacena el valor de `B[i][j]` en una variable temporal `temp`.
   - Luego se asigna a `B[i][j]` el valor de `B[j][i]`.
   - Finalmente, se asigna a `B[j][i]` el valor almacenado en `temp`.

3. Al final, la matriz original `B` queda transpuesta en su lugar.
*/

void transponeMatriz(int** B, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int temp = B[i][j];
            B[i][j] = B[j][i];
            B[j][i] = temp;
        }
    }
}

/*
La función `multiplyMatricesTranspuesta` multiplica dos matrices cuadradas (de tamaño n x n), pero con la diferencia de que primero transpone la matriz `B` para mejorar la eficiencia en el acceso a la memoria durante la multiplicación.

Funcionamiento:
1. Primero, se transpone la matriz `B` utilizando la función `transponeMatriz(B, n)`. Esto intercambia las filas por columnas en la matriz `B`, lo que permite acceder a los elementos de `B` de manera más eficiente en la memoria durante la multiplicación.

2. Luego, se utilizan tres bucles anidados:
   - El primer bucle (índice `i`) recorre las filas de la matriz `A`.
   - El segundo bucle (índice `j`) recorre las columnas de la matriz `B` transpuesta.
   
3. Dentro del segundo bucle, se inicializa la variable `temp` en 0, que almacenará el valor del producto escalar entre la fila `i` de `A` y la columna `j` de la matriz `B` transpuesta (que es ahora una fila original de `B`).

4. El tercer bucle (índice `k`) realiza la multiplicación entre los elementos correspondientes de la fila `i` de `A` y la fila `j` (columna original) de la matriz `B` transpuesta, acumulando el resultado en `temp`.

5. Al finalizar el tercer bucle, el valor acumulado en `temp` se asigna a `C[i][j]`, que es el resultado de la multiplicación para la posición `[i][j]` en la matriz resultado `C`.

6. Al final, la matriz `C` contiene el producto de `A` y la matriz original `B`.
*/

void multiplyMatricesTranspuesta(int** A, int** B, int** C, int n) {
    transponeMatriz(B,n);
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp = 0;
            for (int k = 0; k < n; k++) {
                temp += A[i][k] * B[j][k];
            }
            C[i][j]=temp;
        }
    }
}

/*
La función `add` suma dos matrices cuadradas (de tamaño mSize x mSize) y almacena el resultado en una tercera matriz.

Funcionamiento:
1. Se utilizan dos bucles anidados:
   - El primer bucle (índice `i`) recorre las filas de las matrices `matrixA` y `matrixB`.
   - El segundo bucle (índice `j`) recorre las columnas de las matrices `matrixA` y `matrixB`.

2. En cada iteración, se suman los elementos correspondientes de `matrixA[i][j]` y `matrixB[i][j]`, y el resultado se almacena en `matrixC[i][j]`.

3. Al finalizar ambos bucles, la matriz `matrixC` contendrá la suma elemento por elemento de las matrices `matrixA` y `matrixB`.
*/

void add(int** matrixA, int** matrixB, int** matrixC, unsigned int mSize) {
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

/*
La función `sub` resta dos matrices cuadradas (de tamaño mSize x mSize) y almacena el resultado en una tercera matriz.

Funcionamiento:
1. Se utilizan dos bucles anidados:
   - El primer bucle (índice `i`) recorre las filas de las matrices `matrixA` y `matrixB`.
   - El segundo bucle (índice `j`) recorre las columnas de las matrices `matrixA` y `matrixB`.

2. En cada iteración, se realiza la resta de los elementos correspondientes de `matrixA[i][j]` menos `matrixB[i][j]`, y el resultado se almacena en `matrixC[i][j]`.

3. Al finalizar ambos bucles, la matriz `matrixC` contendrá la resta elemento por elemento de las matrices `matrixA` y `matrixB`.
*/

void sub(int** matrixA, int** matrixB, int** matrixC, unsigned int mSize) {
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }   
}

// fuente: https://github.com/dmonaldo/strassen-matrix-multiplication 
/*
La función `strassenR` implementa el algoritmo de Strassen para la multiplicación de matrices cuadradas de tamaño `mSize x mSize`. Este algoritmo es más eficiente que la multiplicación tradicional, ya que reduce la complejidad temporal de O(n^3) a aproximadamente O(n^2.81), utilizando una estrategia de divide y vencerás.

Funcionamiento:
1. **Caso base**: Si el tamaño de la matriz (`mSize`) es 1, simplemente se multiplica el único elemento de `matrixA` y `matrixB` y se almacena el resultado en `matrixC`.

2. **División**: Si el tamaño es mayor que 1, el algoritmo divide las matrices `matrixA` y `matrixB` en submatrices de tamaño `newMSize` (que es `mSize / 2`):
   - `matrixA` se divide en `matrixA11`, `matrixA12`, `matrixA21`, y `matrixA22`.
   - `matrixB` se divide en `matrixB11`, `matrixB12`, `matrixB21`, y `matrixB22`.

3. **Cálculo de las sumas y restas auxiliares**: Se calculan varias matrices auxiliares (`s1` a `s10`) a partir de las submatrices de `matrixA` y `matrixB`, usando operaciones de suma y resta.

4. **Cálculo de los productos auxiliares**: Se realizan las llamadas recursivas a la función `strassenR` para calcular los productos intermedios `p1` a `p7`, utilizando las submatrices de `matrixA`, `matrixB`, y las matrices auxiliares.

5. **Combinación de resultados**: Una vez calculados los productos, se combinan usando sumas y restas para formar las submatrices `matrixC11`, `matrixC12`, `matrixC21`, y `matrixC22` que componen la matriz resultante `matrixC`.

6. **Reconstrucción de la matriz original**: Las submatrices `matrixC11`, `matrixC12`, `matrixC21`, y `matrixC22` se ensamblan en la matriz final `matrixC`.

7. **Liberación de memoria**: Al final, se libera la memoria asignada dinámicamente para las submatrices, matrices auxiliares, y productos intermedios.

Este método es más eficiente para matrices grandes debido a la reducción en la cantidad de multiplicaciones necesarias.
*/

void strassenR(int** matrixA, int** matrixB, int** matrixC, unsigned int mSize) {
    if (mSize == 1) {
        matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
        return;
    } else {
        int newMSize = mSize / 2;

        int** matrixA11 = new int*[newMSize];
        int** matrixA12 = new int*[newMSize];
        int** matrixA21 = new int*[newMSize];
        int** matrixA22 = new int*[newMSize];
        int** matrixB11 = new int*[newMSize];
        int** matrixB12 = new int*[newMSize];
        int** matrixB21 = new int*[newMSize];
        int** matrixB22 = new int*[newMSize];
        int** matrixC11 = new int*[newMSize];
        int** matrixC12 = new int*[newMSize];
        int** matrixC21 = new int*[newMSize];
        int** matrixC22 = new int*[newMSize];
        int** s1 = new int*[newMSize];
        int** s2 = new int*[newMSize];
        int** s3 = new int*[newMSize];
        int** s4 = new int*[newMSize];
        int** s5 = new int*[newMSize];
        int** s6 = new int*[newMSize];
        int** s7 = new int*[newMSize];
        int** s8 = new int*[newMSize];
        int** s9 = new int*[newMSize];
        int** s10 = new int*[newMSize];
        int** p1 = new int*[newMSize];
        int** p2 = new int*[newMSize];
        int** p3 = new int*[newMSize];
        int** p4 = new int*[newMSize];
        int** p5 = new int*[newMSize];
        int** p6 = new int*[newMSize];
        int** p7 = new int*[newMSize];
        int** tempMatrixA = new int*[newMSize];
        int** tempMatrixB = new int*[newMSize];

        for (int i = 0; i < newMSize; i++) {
            matrixA11[i] = new int[newMSize];
            matrixA12[i] = new int[newMSize];
            matrixA21[i] = new int[newMSize];
            matrixA22[i] = new int[newMSize];
            matrixB11[i] = new int[newMSize];
            matrixB12[i] = new int[newMSize];
            matrixB21[i] = new int[newMSize];
            matrixB22[i] = new int[newMSize];
            matrixC11[i] = new int[newMSize];
            matrixC12[i] = new int[newMSize];
            matrixC21[i] = new int[newMSize];
            matrixC22[i] = new int[newMSize];
            s1[i] = new int[newMSize];
            s2[i] = new int[newMSize];
            s3[i] = new int[newMSize];
            s4[i] = new int[newMSize];
            s5[i] = new int[newMSize];
            s6[i] = new int[newMSize];
            s7[i] = new int[newMSize];
            s8[i] = new int[newMSize];
            s9[i] = new int[newMSize];
            s10[i] = new int[newMSize];
            p1[i] = new int[newMSize];
            p2[i] = new int[newMSize];
            p3[i] = new int[newMSize];
            p4[i] = new int[newMSize];
            p5[i] = new int[newMSize];
            p6[i] = new int[newMSize];
            p7[i] = new int[newMSize];
            tempMatrixA[i] = new int[newMSize];
            tempMatrixB[i] = new int[newMSize];
        }

        for (int i = 0; i < newMSize; i++) {
            for (int j = 0; j < newMSize; j++) {
                matrixA11[i][j] = matrixA[i][j];
                matrixA12[i][j] = matrixA[i][j + newMSize];
                matrixA21[i][j] = matrixA[i + newMSize][j];
                matrixA22[i][j] = matrixA[i + newMSize][j + newMSize];
                matrixB11[i][j] = matrixB[i][j];
                matrixB12[i][j] = matrixB[i][j + newMSize];
                matrixB21[i][j] = matrixB[i + newMSize][j];
                matrixB22[i][j] = matrixB[i + newMSize][j + newMSize];
            }
        }

        sub(matrixB12, matrixB22, s1, newMSize);
        add(matrixA11, matrixA12, s2, newMSize);
        add(matrixA21, matrixA22, s3, newMSize);
        sub(matrixB21, matrixB11, s4, newMSize);
        add(matrixA11, matrixA22, s5, newMSize);
        add(matrixB11, matrixB22, s6, newMSize);
        sub(matrixA12, matrixA22, s7, newMSize);
        add(matrixB21, matrixB22, s8, newMSize);
        sub(matrixA11, matrixA21, s9, newMSize);
        add(matrixB11, matrixB12, s10, newMSize);

        strassenR(matrixA11, s1, p1, newMSize);
        strassenR(s2, matrixB22, p2, newMSize);
        strassenR(s3, matrixB11, p3, newMSize);
        strassenR(matrixA22, s4, p4, newMSize);
        strassenR(s5, s6, p5, newMSize); 
        strassenR(s7, s8, p6, newMSize);
        strassenR(s9, s10, p7, newMSize);

        add(p5, p4, tempMatrixA, newMSize); 
        sub(tempMatrixA, p2, tempMatrixB, newMSize); 
        add(tempMatrixB, p6, matrixC11, newMSize); 
        add(p1, p2, matrixC12, newMSize);
        add(p3, p4, matrixC21, newMSize);
        add(p5, p1, tempMatrixA, newMSize); 
        sub(tempMatrixA, p3, tempMatrixB, newMSize); 
        sub(tempMatrixB, p7, matrixC22, newMSize); 

        for (int i = 0; i < newMSize; i++) {
            for (int j = 0; j < newMSize; j++) {
                matrixC[i][j] = matrixC11[i][j];
                matrixC[i][j + newMSize] = matrixC12[i][j];
                matrixC[i + newMSize][j] = matrixC21[i][j];
                matrixC[i + newMSize][j + newMSize] = matrixC22[i][j];
            }
        }

        for (int i = 0; i < newMSize; i++) {
            delete[] matrixA11[i];
            delete[] matrixA12[i];
            delete[] matrixA21[i];
            delete[] matrixA22[i];
            delete[] matrixB11[i];
            delete[] matrixB12[i];
            delete[] matrixB21[i];
            delete[] matrixB22[i];
            delete[] matrixC11[i];
            delete[] matrixC12[i];
            delete[] matrixC21[i];
            delete[] matrixC22[i];
            delete[] s1[i];
            delete[] s2[i];
            delete[] s3[i];
            delete[] s4[i];
            delete[] s5[i];
            delete[] s6[i];
            delete[] s7[i];
            delete[] s8[i];
            delete[] s9[i];
            delete[] s10[i];
            delete[] p1[i];
            delete[] p2[i];
            delete[] p3[i];
            delete[] p4[i];
            delete[] p5[i];
            delete[] p6[i];
            delete[] p7[i];
            delete[] tempMatrixA[i];
            delete[] tempMatrixB[i];
        }
        delete[] matrixA11;
        delete[] matrixA12;
        delete[] matrixA21;
        delete[] matrixA22;
        delete[] matrixB11;
        delete[] matrixB12;
        delete[] matrixB21;
        delete[] matrixB22;
        delete[] matrixC11;
        delete[] matrixC12;
        delete[] matrixC21;
        delete[] matrixC22;
        delete[] s1;
        delete[] s2;
        delete[] s3;
        delete[] s4;
        delete[] s5;
        delete[] s6;
        delete[] s7;
        delete[] s8;
        delete[] s9;
        delete[] s10;
        delete[] p1;
        delete[] p2;
        delete[] p3;
        delete[] p4;
        delete[] p5;
        delete[] p6;
        delete[] p7;
        delete[] tempMatrixA;
        delete[] tempMatrixB;
    }
}


int main(){
    int n;
    cout << "Ingrese el tamaño de las matrices: ";
    cin >> n;
    srand(time(0));

    int** A = new int*[n];
    int** B = new int*[n]; 
    int** C = new int*[n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j]=rand() % 10;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j]=rand() % 10;
        }
    }

    auto start = high_resolution_clock::now(); 
    multiplicarMatricesTradicional(A, B, C, n);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Tiempo algotitmo tradicional: " << duration.count() << " microsegundos" << endl;

    auto start2 = high_resolution_clock::now(); 
    multiplyMatricesTranspuesta(A, B, C, n);
    auto stop2 = high_resolution_clock::now(); 
    auto duration2 = duration_cast<microseconds>(stop2 - start2); 
    cout << "Tiempo algotitmo transponiendo la matriz: " << duration2.count() << " microsegundos" << endl;

    auto start3 = high_resolution_clock::now(); 
    strassenR(A, B, C, n); 
    auto stop3 = high_resolution_clock::now(); 
    auto duration3 = duration_cast<microseconds>(stop3 - start3); 
    cout << "Tiempo algotitmo strassen: " << duration3.count() << " microsegundos" << endl;
    
    return 0;
}