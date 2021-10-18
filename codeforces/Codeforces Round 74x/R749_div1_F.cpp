#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

int n, k, c;
int r[1005][1005];

void solve() {
    cin >> n >> k;

    vector<vi> v(n), nxt;
    for (int i = 0; i < n; i++)v[i].pb(i);

    for (c = 1; v.size() != 1; c++) {
        nxt.clear();
        for (int i = 0; i < v.size(); i += k) {
            int j = i + 1;
            while (j < v.size() && j < i + k)
                v[i].insert(v[i].end(), v[j].begin(), v[j].end()), j++;
            nxt.pb(v[i]);
        }
        v = nxt;

        for (auto x: v) for (int i: x) for (int j: x)  if(!r[i][j]) r[i][j] = c;
    }

    cout << c - 1 << endl;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)cout<< r[i][j] <<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
