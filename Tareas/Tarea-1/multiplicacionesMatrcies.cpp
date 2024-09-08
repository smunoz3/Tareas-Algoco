#include <iostream>
#include <chrono>
#include <cstdlib> 
#include <ctime>

using namespace std;
using namespace std::chrono;


void multiplicarMatricesTradicional(int** A, int** B, int** C, int n) { // https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transponeMatriz(int** B, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int temp = B[i][j];
            B[i][j] = B[j][i];
            B[j][i] = temp;
        }
    }
}


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


void add(int** matrixA, int** matrixB, int** matrixC, unsigned int mSize) {
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void sub(int** matrixA, int** matrixB, int** matrixC, unsigned int mSize) {
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }   
}


void printMatrix(int** matrix, unsigned int mSize) {
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

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


void imprimirMatriz(int** matriz, int tamaño) {
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
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

    // Llena las matrices
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

    auto start = high_resolution_clock::now(); // Captura el tiempo de inicio
    multiplicarMatricesTradicional(A, B, C, n); // Multiplicar matrices
    auto stop = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration = duration_cast<microseconds>(stop - start); // Calcula la duración
    cout << "Tiempo algotitmo tradicional: " << duration.count() << " microsegundos" << endl;


    auto start2 = high_resolution_clock::now(); // Captura el tiempo de inicio
    multiplyMatricesTranspuesta(A, B, C, n); // Multiplicar matrices
    auto stop2 = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration2 = duration_cast<microseconds>(stop2 - start2); // Calcula la duración
    cout << "Tiempo algotitmo transponiendo la matriz: " << duration2.count() << " microsegundos" << endl;


    auto start3 = high_resolution_clock::now(); // Captura el tiempo de inicio
    strassenR(A, B, C, n); // Multiplicar matrices
    auto stop3 = high_resolution_clock::now(); // Captura el tiempo de finalización
    auto duration3 = duration_cast<microseconds>(stop3 - start3); // Calcula la duración
    cout << "Tiempo algotitmo strassen: " << duration3.count() << " microsegundos" << endl;
    
    
    return 0;
}