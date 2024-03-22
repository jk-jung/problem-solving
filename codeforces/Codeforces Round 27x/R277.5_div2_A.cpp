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
    vi a(n), b;
    for (int &x: a)cin >> x;
    b = a;
    sort(b.begin(), b.end());
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if(a[j] == b[i]) {
                cout <<i << " " << j << endl;
                swap(a[i], a[j]);
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
