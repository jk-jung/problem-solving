#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] == v[j]) {
                cout << "yes";
                return;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            int s = min(v[i], v[i-1]);
            int e = max(v[i], v[i-1]);
            bool a = s < v[j] && v[j] < e;
            bool b = s < v[j-1] && v[j-1] < e;
            if (a != b) {
                cout << "yes";
                return;
            }
        }
    }
    cout << "no";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
