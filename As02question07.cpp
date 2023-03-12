#include <iostream>
using namespace std;

// Original function
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Tail recursive function
int tailFactorial(int n, int assignor = 1) {
    if (n == 0)
        return assignor;
    else
        return tailFactorial(n - 1, n * assignor);
}

int main() {
    cout << "Factorial of 7: " << factorial(7) << endl;
    cout << "Tail Recursive Factorial of 7: " << tailFactorial(7) << endl;
    return 0;
}
