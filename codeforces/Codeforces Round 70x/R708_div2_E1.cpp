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
int temp[2111], TEMP;
vector<int> prime(MAX + 1);

void fast_factorization_for_many_numbers() {

    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) if (!prime[j]) prime[j] = i;
    }
}


vi get(int x) {
    TEMP = 0;
    while (prime[x]) temp[TEMP++] = prime[x], x /= prime[x];
    if (x > 1) temp[TEMP++] = x;

    int cnt = 0, last = -1;

    vi fac;
    for (int j = 0; j < TEMP; j++) {
        if (last != temp[j]) {
            if (cnt % 2)fac.pb(last);
            cnt = 1;
            last = temp[j];
        } else {
            cnt++;
        }
    }
    if (cnt % 2)fac.pb(last);
    return fac;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi v(n);

    vector<vi> fac(n);
    for (int &x: v)cin >> x;
    int r = 1;
    set<vi> cur;
    for (int x: v) {
        vi t = get(x);
        if (cur.count(t)) {
            r++;
            cur.clear();
        }
        cur.insert(t);
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
