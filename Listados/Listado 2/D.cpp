#include <bits/stdc++.h>

using namespace std;

void vprint(vector<vector<string>>& vec) {
    for (auto& i : vec) {
        for (auto& j : i) cout << j << ' ';
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string titulo, palabra;
    int longitud(-1), filas;
    getline(cin, titulo);
    stringstream flujo(titulo);
    unordered_map<string, int> atributos;
    while (flujo >> palabra) {
        atributos[palabra] = ++longitud;
    }
    ++longitud;

    cin >> filas;
    vector<vector<string>> tabla(filas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < longitud; ++j) {
            cin >> palabra;
            tabla[i].push_back(palabra);
        }
    }

    cin >> filas;
    while (filas--) {
        cin >> palabra;
        int i = atributos[palabra];
        stable_sort(tabla.begin(), tabla.end(),
            [&](auto& fila1, auto& fila2) { return fila1[i] < fila2[i]; });

        cout << titulo << '\n';
        vprint(tabla);
        if (filas != 0) cout << '\n';
    }
}