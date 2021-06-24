#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back

int n;
pair<ll, ll> v[100005];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
    sort(v, v + n);

    ll r = 0, tot = 0;
    int s = 0;
    int e = n - 1;

    for (; s <= e;) {
        if (v[s].first <= tot) {
            r += v[s].second;
            tot += v[s].second;
            s ++;
        } else {
            ll diff = v[s].first - tot;
            while (s <= e && diff > 0) {
                ll can = min(v[e].second, diff);

                v[e].second -= can;
                diff -= can;

                tot += can;
                r += can * 2;

                if (v[e].second == 0) e--;
            }
        }
    }

    cout << r << endl;
}