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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vi used(n), is_pal(n);
    string L, R;
    for (auto &s: v)cin >> s;
    for (int i = 0; i < n; i++) {
        string a = v[i];
        reverse(a.begin(), a.end());

        if (a == v[i])is_pal[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (used[i] || used[j])continue;
            if (a == v[j]) {
                L += v[i];
                R = v[j] + R;
                used[i] = used[j] = 1;
                break;
            }
        }
    }

    string r;
    for(int i=0;i<n;i++)if(!used[i] && is_pal[i]){ r = v[i]; break;}
    r = L + r + R;
    cout << r.size() << endl;
    cout << r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
