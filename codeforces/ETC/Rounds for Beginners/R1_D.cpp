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

void solve() {
    int n;
    cin >> n;
    vi used(n), r(n, -1);

    for (int i = 0; i < n - 2; i += 2) {
        used[i + 2] = 1;
        r[i] = i + 2;
    }
    for (int i = n - 1, pos = n - 1; i >= 0; i--) {
        if (r[i] != -1)continue;
        while (used[pos])pos--;
        r[i] = pos --;
    }

    for (int x: r)cout << x + 1<< " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
