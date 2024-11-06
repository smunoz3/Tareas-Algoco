#include <iostream>
#include <fstream>
#include <vector>

#include <sstream>   // Para manejar la conversión de cadena a número
#include <stdexcept> // Para manejar excepciones

using namespace std;

vector<vector<int>> leerMatriz(const string nombreArchivo) {
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

std::vector<int> leerVector(const std::string nombre_archivo) {
    std::ifstream archivo(nombre_archivo);
    
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo.");
    }

    std::string linea;
    std::getline(archivo, linea);
    
    std::stringstream ss(linea); 
    std::vector<int> vector;
    int numero;
    char separador;

    while (ss >> numero) {
        vector.push_back(numero);
        ss >> separador;
    }

    // Verificar que se leyeron exactamente 26 números
    if (vector.size() != 26) {
        throw std::invalid_argument("El archivo no contiene exactamente 26 números.");
    }
    
    archivo.close();
    return vector;
}

int letra_a_numero(char letra) {
    letra = toupper(letra);

    if (letra >= 'A' && letra <= 'Z') {
        return letra - 'A';
    } else {
        throw std::invalid_argument("La letra debe estar entre A y Z");
    }
}

int costo_sub (char a, char b) {
    int costo;
    vector<vector<int>> matriz = leerMatriz("cost_replace.txt");
    costo=matriz[letra_a_numero(a)][letra_a_numero(b)];
    return costo;
}

int costo_ins (char b) {
    int costo;
    vector<int> vector = leerVector("cost_insert.txt");
    costo=vector[letra_a_numero(b)];
    return costo;
}

int costo_del (char a) {
    int costo;
    vector<int> vector = leerVector("cost_delete.txt");
    costo=vector[letra_a_numero(a)];
    return costo;
}

int costo_trans (char a, char b) {
    int costo;
    vector<vector<int>> matriz = leerMatriz("cost_transpose.txt");
    costo=matriz[letra_a_numero(a)][letra_a_numero(b)];
    return costo;
}


int main() {
    string palabra1;
    string palabra2;
    int largoP1=palabra1.size();
    int largoP2=palabra2.size();
    int costoMin = INT_MAX;
    int costo1=0;
    int costo2=0;
    //Palabra1 a Palabra2

    for(int i=0;i<largoP1;i++){
        if((i<largoP1 && i<largoP2) //Revisa rango 
        && (palabra1[i+1]==palabra2[i]) &&(palabra1[i]==palabra2[i+1])){
            costo1 += costo_trans(palabra1[i],palabra1[i+1]);
            i+=1;
        }
        palabra1[i];


    }    

    return 0;
}
