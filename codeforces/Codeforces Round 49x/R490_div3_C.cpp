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
    int n, k;
    string s;
    map<int, int> ck;
    cin >> n >> k >> s;
    for (char x: s)ck[x]++;
    for (char c = 'a'; c <= 'z'; c++) {
        if (ck[c] <= k) {
            k -= ck[c];
        } else {
            for (char x: s) {
                if (x < c)continue;
                if (x == c) {
                    if (k > 0)k--;
                    else cout << x;
                } else {
                    cout << x;
                }
            }
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
