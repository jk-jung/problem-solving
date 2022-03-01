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


const int MAX = 10000000;
int prime[MAX + 1];
vi d(MAX + 1, 1 << 30);
int cc[1000];

void fast_factorization_for_many_numbers() {
    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }

    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) continue;
        else d[i + 1] = min(d[i + 1], i);

        for (int j = i + i; j <= MAX; j += i) {
            if (prime[j] != i)continue;
            if (1 + j + j / i + i >= MAX) break;

            int x = j, pos = 0;
            while (prime[x]) cc[pos++] = prime[x], x /= prime[x];
            if (x > 1)cc[pos++] = x;

            int cur = 1, t;

            for (int l = 0; l < pos;) {
                int k = cc[l], v = 0;
                while (l < pos && cc[l] == k)l ++, v++;
                t = cur;
                for (int _ = 1; _ <= v; _++) {
                    t *= k;
                    cur += t;
                }
            }
            if (cur <= MAX)
                d[cur] = min(d[cur], j);

        }
    }
}

void solve() {
    int x;
    cin >> x;
    int r = d[x] == (1 << 30) ? -1 : d[x];
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fast_factorization_for_many_numbers();
    d[1] = 1;

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
