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
    string a, b;
    cin >> a >> b;
    map<char, int> A, B;
    for (char c: a) A[c]++;
    for (char c: b) B[c]++;
    int r1 = 0, r2 = 0;
    for (auto [k,v]: A) {
        int t = min(v, B[k]);
        r1 += t;
        A[k] -= t;
        B[k] -= t;
    }
    for (auto [k, v]: A) {
        char x = islower(k) ? toupper(k) : tolower(k);
        r2 += min(v, B[x]);
    }
    cout << r1 << " " << r2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
