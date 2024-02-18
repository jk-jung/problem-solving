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
    int n = a.size();
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])c++;
    }
    if(c % 2)cout << "impossible";
    else {
        c /= 2;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (c) {
                    cout << a[i];
                    c--;
                }
                else cout << b[i];
            } else cout << a[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
