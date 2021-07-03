#include <stdio.h>

bool is_pow_of_two(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main() {
    for (int i = 0; i <= 128; i++) {
        printf("%d %d\n", i, is_pow_of_two(i));
    }
}


