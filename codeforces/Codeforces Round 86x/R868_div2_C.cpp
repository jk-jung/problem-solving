#include <cstring>
#include <cstdio>
#include <cmath>
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


const int MAX = 10000001;
vector<int> prime(MAX + 1);

void fast_factorization_for_many_numbers() {
    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) prime[j] = i;
    }
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    map<int, int> ck;

    for (int &x: v) {
        cin >> x;

        while (prime[x]) ck[prime[x]] ++, x /= prime[x];
        if (x > 1) ck[x] ++;
    }
    int r = 0, t = 0;
    for (auto [x, y]: ck)r += y / 2, t += y % 2;
    cout << r + t / 3 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fast_factorization_for_many_numbers();

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
