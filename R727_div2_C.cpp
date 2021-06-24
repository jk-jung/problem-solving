#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;


ll v[200005];
ll n, k, x;
vector<ll> gaps;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) scanf("%lld", v + i);
    sort(v, v + n);

    for (int i = 1; i < n; i++) {
        ll gap = v[i] - v[i - 1];
        if (gap > x) gaps.push_back(gap);
    }
    sort(gaps.begin(), gaps.end());
    int r = gaps.size() + 1;

    for (int i = 0; i < gaps.size(); i++) {
        ll need = (gaps[i]- 1) / x;
        if (need <= k && r >= 2) {
            k -= need;
            r--;
        }
    }

    cout << r << endl;
}
