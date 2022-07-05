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


void solve() {
    int n;
    string s;
    vector<pair<char, int>> v;

    cin >> n >> s;
    vi color(n);
    for (int i = 0; i < n; i++)v.pb({s[i], i});

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (v[j - 1].F > v[j].F) {
                int &x = color[v[j - 1].S];
                int &y = color[v[j].S];
                if (x == 0 && y == 0)x = 1, y = 2;
                else if (x == 0) x = 3 - y;
                else if (y == 0) y = 3 - x;
                else if (x == y) {
                    cout << "NO\n";
                    return;
                }
                swap(v[j - 1], v[j]);
            }
        }
    }
    for(int &x:color)if(x == 0)x = 1;
    cout << "YES\n";
    for (int x: color)cout << 2 - x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
