#include <iostream>
#include <vector>

using namespace std;

// Función para multiplicar dos matrices
void multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C) {
    int m = A.size();     // Número de filas en A
    int n = A[0].size();  // Número de columnas en A (y filas en B)
    int p = B[0].size();  // Número de columnas en B

    C.assign(m, vector<int>(p, 0)); // Inicializar la matriz C con ceros

    // Realizar la multiplicación de matrices
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Función para imprimir una matriz
void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    // Leer las dimensiones de las matrices
    cout << "Ingrese el tamaño de las matrices y luego las 2 matrices: ";
    cin >> n;

    // Inicializar las matrices
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }

    // Multiplicar las matrices
    multiplyMatrices(A, B, C);

    // Imprimir la matriz resultante
    cout << "La matriz resultante es:" << endl;
    printMatrix(C);

    return 0;
}