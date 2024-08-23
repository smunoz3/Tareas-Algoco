#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, num;
    cin >> n >> num;

    vector<int> v(n);
    int pos;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] == num) {
            pos = i;
        }
    }

    map<int,int> m;
    m[0] = 1;
    int sum = 0;
    for(int i = pos+1; i < n; i++) {
        if(v[i] > num) sum++;
        else sum--;
        m[sum]++;
    }

    ll resp = m[0];
    sum = 0;
    for(int i = pos-1; i >= 0; i--) {
        if(v[i] > num) sum++;
        else sum--;
        resp += m[-sum];
    }

    cout << resp << endl;
    return 0;
}