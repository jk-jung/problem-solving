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

bool f(int x) {
    vi v(10);
    while (x) {
        v[x % 10]++;
        x /= 10;
    }
    for (int i = 0; i < 10; i++)if (v[i] > 1)return false;
    return true;
}

void solve() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (f(i)) {
            cout << i << endl;
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
