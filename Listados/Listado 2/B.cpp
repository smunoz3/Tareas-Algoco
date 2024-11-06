#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    return a.substr(0, 2) < b.substr(0, 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<string> array(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> ws;
            getline(cin, array[i]);
        }

        sort(array.begin(), array.end(), compare);
        
        for (const auto& str : array) {
            cout << str << "\n";
        }
        
        cout << "\n";
    }
    
    return 0;
}
