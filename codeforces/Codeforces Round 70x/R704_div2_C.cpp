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

int n, m;
string a, b;

vi calc() {
    vi r(m);
    for (int i = 0, k = 0; i < n; i++) {
        if (k < m && a[i] == b[k]) r[k++] = i;
    }
    return r;
}

void solve() {
    cin >> n >> m >> a >> b;

    vi L = calc();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vi R = calc();
    for(int &x: R)x = n - x - 1;
    reverse(R.begin(), R.end());

    int r = 0;
    for (int i = 1; i < m; i++) {
        r = max(r, R[i] - L[i - 1]);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
