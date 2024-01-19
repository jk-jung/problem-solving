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

void solve() {
    int n, p, q;
    string s;
    cin >> n >> p >> q >> s;
    for (int i = 0; i <= 100; i++) {
        if (n - i * p >= 0 && (n - i * p) % q == 0) {
            int j = (n - i * p) / q;
            cout << i + j << endl;
            for (int k = 0; k < i; k++) cout << s.substr(k * p, p) << endl;
            for (int k = 0; k < j; k++) cout << s.substr(i * p + k * q, q) << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
