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
    vi a(n), b(n), used(n + 1);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int r = 0;
    while (!b.empty()) {
        while (!b.empty()) {
            if (a.back() == b.back()) {
                a.pop_back();
                b.pop_back();
            } else if (used[a.back()])a.pop_back();
            else break;
        }
        if (!b.empty()) {
            r++;
            used[b.back()] = 1;
            b.pop_back();
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
