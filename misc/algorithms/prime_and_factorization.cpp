#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))


const int MAX = 100;

void fast_factorization_for_many_numbers() {
    vector<int> prime(MAX + 1);
    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) prime[j] = i;
    }

    for (int i = 2; i <= MAX; i++) {
        int x = i;
        vi factors;

        while (prime[x]) factors.pb(prime[x]), x /= prime[x];
        if (x > 1) factors.pb(x);

        // for debug
        cout << i << " : ";
        for (int y: factors)cout << y << " ";
        cout << endl;
    }
}

int main() {
    fast_factorization_for_many_numbers();
}