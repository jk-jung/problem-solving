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

struct Item {
    int i, a, b;
};

bool sf1(Item &a, Item &b) { return a.a > b.a; }

bool sf2(Item &a, Item &b) { return a.b > b.b; }

void solve() {
    int n;
    cin >> n;
    vector<Item> a(n), b;
    vi ok(n);
    for (int i = 0; i < n; i++) cin >> a[i].a, a[i].i = i;
    for (int i = 0; i < n; i++) cin >> a[i].b;
    b = a;

    sort(a.begin(), a.end(), sf1);
    sort(b.begin(), b.end(), sf2);

    int p1 = 0, p2 = 0;
    int va = a[p1].a, vb = b[p2].b;
    while (p1 < n || p2 < n) {
        bool end = true;
        if (p1 < n && a[p1].a >= va) vb = min(vb, a[p1].b), ok[a[p1++].i] = 1, end = false;
        if (p2 < n && b[p2].b >= vb) va = min(va, a[p2].a), ok[b[p2++].i] = 1, end = false;
        if(end) break;
    }

    for (auto x: ok)cout << x;
    cout << '\n';
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
