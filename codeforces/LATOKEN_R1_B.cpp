#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp    make_pair
#define pb    push_back
#define ab(x) (((x)<0)?-(x):(x))


ll calc(vector<int> &v) {
    ll r = 0;

    for (int i = 0; i < v.size(); i++) {
        if (i != 0 && i + 1 < v.size() && v[i - 1] < v[i] && v[i] > v[i + 1]) {
            ll t = max(v[i - 1], v[i + 1]);
            r += v[i] - t;
            v[i] = t;
        }
    }
    for(int i=0;i<v.size();i++){
        if (i > 0) r += max(0, v[i - 1] - v[i]);
        if (i + 1 < v.size()) r += max(0, v[i + 1] - v[i]);
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m = 2000000000;
        cin >> n;
        vector<int> v(n), c;
        for (int i = 0; i < n; i++) {

            cin >> v[i];
            if (v[i] > 0 && v[i] < m) m = v[i];
        }
        v.push_back(0);
        c.push_back(0);

        ll r = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) {
                c.push_back(0);
                r += calc(c);
                c.clear();
                c.push_back(0);
            } else c.push_back(v[i]);
        }
        cout << r << endl;
    }
}
