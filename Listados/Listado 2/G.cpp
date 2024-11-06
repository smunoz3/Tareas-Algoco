#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, u;
    cin >> n >> u;

    vector<int> pintura(n);

    for(int i = 0; i < n; i++){
        cin >> pintura[i];
    }

    sort(pintura.begin(), pintura.end());
    long long desp = 0;
    for(int i = 0; i < u; i++){
        int qtd; cin >> qtd;
        desp += (long long) *lower_bound(pintura.begin(), pintura.end(), qtd) - qtd;
    }

    cout << desp << endl;
}