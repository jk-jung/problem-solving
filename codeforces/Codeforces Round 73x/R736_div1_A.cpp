#include <string.h>
#include <stdio.h>
#include <math.h>
#include <set>
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

int n, m;
set<int> v[200005], tar;
int deg[200005];
int used[200005];

void add(int s, int e) {
    if (s > e)swap(s, e);
    v[s].insert(e);
    tar.erase(s);
}

void del(int s, int e) {
    if (s > e)swap(s, e);
    v[s].erase(e);
    if (v[s].empty())tar.insert(s);
}

int process() {
    cout << tar.size() << endl;
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)tar.insert(i + 1);
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        add(s, e);
    }

    int q;
    cin >> q;
    while (q--) {
        int o, a, b;
        cin >> o;
        if (o == 3) {
            process();
        } else {
            cin >> a >> b;

            if (o == 1)add(a, b);
            else del(a, b);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
