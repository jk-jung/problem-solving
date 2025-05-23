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
    for (int &x: v)cin >> x, x--;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] == j && v[j] == i) {
                vi t = v;
                for (int k = i; k <= j; k++)t[k] = v[j - (k - i)];
                bool ok = true;
                for(int k=0;k<n;k++)if(t[k]!=k)ok=false;
                if(ok) {
                    cout << i + 1 << " " << j + 1 << endl;
                    return;
                }
            }
        }
    }
    cout << "0 0" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
