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

int a[10000];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s == string(n, '1')) {
            a[i] = 0;
        }else a[i] = 1;
    }
    int r = 0, rr = 0;
    for (int i = 0; i < m; i++) {
        if (a[i])r++;
        else r = 0;
        rr = max(r, rr);
    }
    cout << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
