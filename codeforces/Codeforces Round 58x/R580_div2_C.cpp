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
    if (n % 2 == 0) {
        cout << "NO\n";
    } else {
        vi r(n * 2);
        for (int i = 0; i < n; i++) {
            int a = i * 2 + 1, b = i * 2 + 2;
            if (i % 2)swap(a, b);
            r[i] = a;
            r[i + n] = b;
        }
        cout << "YES\n";
        for (int x: r)cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
