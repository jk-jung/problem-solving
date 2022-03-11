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

struct Data {
    int x, w, i;
};

bool sf(Data &a, Data &b) {
    return a.w < b.w;
}

bool sf2(Data &a, Data &b) {
    return a.x < b.x;
}

Data v[200005];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)cin >> v[i].x >> v[i].w, v[i].i = i;

    sort(v, v + m, sf);
    sort(v, v + n * 2, sf2);
    int r = 0;
    for (int i = 0; i < n * 2; i++)r += v[i].w;

    cout << r << endl;
    for (int s = 0, e = n * 2 - 1; s < e; s++, e--) {
        cout << v[s].i + 1 <<" " << v[e].i + 1 << '\n';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
