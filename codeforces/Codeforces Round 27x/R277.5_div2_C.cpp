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

void print_max(int n, int m) {
    for (int i = 0; i < n; i++) {
        int t = min(9, m);
        cout << t;
        m -= t;
    }
}

void print_min(int n, int m) {
    for (int i = 0; i < n; i++) {
        int t = (n - i - 1) * 9;
        int k = (i == 0 ? 1 : 0);
        while (t + k < m) k++;
        cout << k;
        m -= k;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        if (n != 1) cout << "-1 -1";
        else cout << "0 0";
    } else if (n * 9 < m)cout << "-1 -1";
    else {
        print_min(n, m);
        cout << " ";
        print_max(n, m);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
