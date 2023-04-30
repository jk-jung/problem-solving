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
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        for (int st = 0; st < 2; st++) {
            if (!a.empty() && !b.empty()) {
                if (a.back() >= b.back()) {
                    if (st == 0)A += a.back();
                    a.pop_back();
                } else {
                    if (st == 1)B += b.back();
                    b.pop_back();
                }
            } else if (b.empty()) {
                if (st == 0) A += a.back();
                a.pop_back();
            } else {
                if (st == 1) B += b.back();
                b.pop_back();
            }
        }
    }
    cout << A - B << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
