#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <stdexcept>
#include <climits>
#include <limits>
#include <chrono>
#include <algorithm>

using namespace std;

vector<vector<int>> matrizReplace(26, vector<int>(26));
vector<vector<int>> matrizTranspose(26, vector<int>(26));
vector<int> vectorInsert;
vector<int> vectorDelete;

vector<vector<int>> leerMatriz(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<vector<int>> matriz(26, vector<int>(26)); // Matriz 26x26

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return matriz;
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            archivo >> matriz[i][j];
            if (archivo.fail()) {
                cerr << "Error al leer el archivo en la posición (" << i << ", " << j << ")" << endl;
                archivo.close();
                return matriz;
            }
        }
    }

    archivo.close();
    return matriz;
}

vector<int> leerVector(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo.");
    }

    vector<int> vector(26);
    for (int i = 0; i < 26; ++i) {
        archivo >> vector[i];
        if (archivo.fail()) {
            throw runtime_error("Error al leer el archivo de vector.");
        }
    }

    if (vector.size() != 26) {
        throw invalid_argument("El archivo no contiene exactamente 26 números.");
    }
    
    archivo.close();
    return vector;
}

void cargarMatrices() {
    matrizReplace = leerMatriz("cost_replace.txt");
    matrizTranspose = leerMatriz("cost_transpose.txt");
    vectorInsert = leerVector("cost_insert.txt");
    vectorDelete = leerVector("cost_delete.txt");
}

int letra_a_numero(char letra) {
    letra = toupper(letra);
    if (letra >= 'A' && letra <= 'Z') {
        return letra - 'A';
    } else {
        throw invalid_argument("La letra debe estar entre A y Z");
    }
}

int costo_sub (char a, char b) {
    int costo;
    costo=matrizReplace[letra_a_numero(a)][letra_a_numero(b)];
    return costo;
}

int costo_ins (char b) {
    int costo;
    costo=vectorInsert[letra_a_numero(b)];
    return costo;
}

int costo_del (char a) {
    int costo;
    costo=vectorDelete[letra_a_numero(a)];
    return costo;
}

int costo_trans (char a, char b) {
    int costo;
    costo=matrizTranspose[letra_a_numero(a)][letra_a_numero(b)];
    return costo;
}

int calcularCosto(const string& palabra1, const string& palabra2) {
    int costoTotal = 0;
    int largoP1 = palabra1.size();
    int largoP2 = palabra2.size();
    int n = min(largoP1, largoP2);
    int i = 0;

    while (i < n) {
        if (i + 1 < n && palabra1[i + 1] == palabra2[i] && palabra1[i] == palabra2[i + 1]) {
            costoTotal += costo_trans(palabra1[i], palabra1[i + 1]);
            i += 2;
        } else {
            costoTotal += costo_sub(palabra1[i], palabra2[i]);
            ++i;
        }
    }

    // Insert or delete costs for remaining characters
    for (; i < largoP2; ++i) {
        costoTotal += costo_ins(palabra2[i]);
    }
    for (; i < largoP1; ++i) {
        costoTotal += costo_del(palabra1[i]);
    }

    return costoTotal;
}

int main() {
    cargarMatrices();
    ifstream archivo("palabras.txt");
    ofstream archivo_salida("resultado.txt");
    int N;

    if (!archivo) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    if (!archivo_salida) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    archivo >> N;
    archivo.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < N; ++i) {
        string linea;
        auto inicio = std::chrono::high_resolution_clock::now();  
        getline(archivo, linea);

        stringstream ss(linea);
        string palabra1, palabra2;
        getline(ss, palabra1, '|');
        getline(ss, palabra2, '|');

        int costo1 = calcularCosto(palabra1, palabra2);
        int costo2 = calcularCosto(palabra2, palabra1);
        int costoMin = min(costo1, costo2);
        auto fin = std::chrono::high_resolution_clock::now();
        auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);


        archivo_salida << "Palabras: " << linea << " Costo minimo: " << costoMin <<" Tiempo: "<< duracion.count()<<"ms"<< endl;
    }

    archivo.close();
    archivo_salida.close();

    return 0;
}
