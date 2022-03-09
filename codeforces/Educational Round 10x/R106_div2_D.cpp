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




const int MAX = 20000000;
int ff[MAX+ 5];

void fast_factorization_for_many_numbers() {
    vector<int> prime(MAX + 1);
    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) if(prime[j] == 0)prime[j] = i;
    }

    for (int i = 2; i <= MAX; i++) {
        int x = i, c = 0, last = -1;

        while (prime[x]) {
            if(prime[x] != last) c ++;
            last = prime[x];
            x /= prime[x];
        }
        if (x > 1 && x != last) c++;
        ff[i] = c;
    }
}

int ck(int g, int c, int d, int x) {
    int t = x / g + d;
    if (t % c) return 0;
    t /= c;
    return 1 << ff[t];
}

void solve() {
    int c, d, x;
    cin >> c >> d >> x;

    int r = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i)continue;

        r += ck(i, c, d, x);
        if (i * i != x) r += ck(x / i, c, d, x);
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fast_factorization_for_many_numbers();
    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
