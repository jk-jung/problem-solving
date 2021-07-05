#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp    make_pair
#define pb    push_back
#define ab(x) (((x)<0)?-(x):(x))


class DSU {
public:
    vector<int> p;

    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) { return p[x] != x ? p[x] = find(p[x]) : x; }

    void unite(int x, int y) { p[find(x)] = p[find(y)]; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        DSU dsu(n);

        for (int i = 0; i < n; i++)cin >> a[i];
        for (int i = 0; i < n; i++)cin >> b[i];

        for (int i = 0; i < n; i++)
            dsu.unite(a[i] - 1, b[i] - 1);
        ll r = 1;
        for (int i = 0; i < n; i++) if (dsu.find(i) == i) r = r * 2 % 1000000007;
        cout << r << endl;

    }
}
