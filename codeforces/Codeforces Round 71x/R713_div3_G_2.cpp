/*
 * 𝑑(𝑎⋅𝑏)=𝑑(𝑎)⋅𝑑(𝑏)  if 𝑔𝑐𝑑(𝑎,𝑏)=1
 *
 */

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
int v[MAX + 1];

void fast_factorization_for_many_numbers() {

    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }

    v[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) {
            v[i] = i + 1;
        } else {
            int x = i, v1 = 1;
            while (x % prime[i] == 0) v1 = v1 * prime[i] + 1, x /= prime[i];
            v[i] = v1 * v[x];
        }
    }
    for (int i = 1; i <= MAX; i++)if(v[i] <= MAX)d[v[i]] = min(d[v[i]], i);
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
