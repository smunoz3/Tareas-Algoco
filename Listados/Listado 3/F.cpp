#include <iostream>
#include <vector>

int main() {
    std::vector<int> decryptedArray(256, 0);

    for (int i = 0; i < 256; ++i) {
        int y = i ^ (i << 1);
        decryptedArray[y % 256] = i;
    }

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int nextNum;
        std::cin >> nextNum;
        std::cout << decryptedArray[nextNum] << std::endl;
    }

    return 0;
}
