#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        if (n == 1) {
            std::cout << "1\n1\n";
            continue;
        } else if (n == 2) {
            std::cout << "2\n1 2\n";
            continue;
        } else if (n == 3) {
            std::cout << "3\n1 2 4\n";
            continue;
        }

        std::cout << n << "\n";
        ll partial_factorial = 1;
        for (int i = 1; i <= n - 1; ++i) {
            std::cout << i << " ";

            if (i * 2 > (n - 1)) {
                partial_factorial *= i;
            }
        }

        std::cout << partial_factorial << "\n";
    }
}