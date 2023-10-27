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
    cin >> n >> k;

    vector<string> r, v(n - k + 1);
    char a = 'A';
    r.pb(string(1, a));
    int cnt = 1;
    for (int i = 0; i <= n - k; i++) {
        string t;
        v[i] = t;
        cin >> t;
        if (t == "YES") {
            while (r.size() < i + k) {
                if (a++ == 'Z')a = 'A', cnt++;
                string l = string(1, a);
                if(cnt == 2)l += tolower(a);
                r.pb(l);
            }
        } else if (t == "NO") {
            r.pb(r[max(0, (int) r.size() - k + 1)]);
        }
    }
    while (r.size() < n) {
        if (a++ == 'Z')a = 'A', cnt++;
        string l = string(1, a);
        if(cnt == 2)l += tolower(a);
        r.pb(l);
    }
    for (int i = 0; i < r.size(); i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
