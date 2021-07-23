#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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
int ck[300005];
int CK = 0;

bool can(vector<int> &v, int k) {
    CK++;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        int x = v[i + k];
        if (ck[x] == CK)continue;
        r--;
        while (ck[x] != CK) {
            ck[x] = CK;
            x = v[x + k];
            r++;
        }
    }
    return r <= m;
}

void solve() {

    cin >> n >> m;
    vector<int> v(n * 2 + 1);
    map<int, int> t;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i + n] = v[i];
    }

    for (int i = 1; i <= n; i++) {
        int move = i - v[i];
        if (move < 0) move += n;
        t[move]++;
    }

    int cur = 0;
    vector<int> r;
    for (int k = 0; k < n; k++) {
        cur += t[k];
        if (k > 0) cur -= t[k - 1];
        int need = n - cur;
        if ((need + 1) / 2 > m)continue;
//        cout << "! " << k << " " << need << " " << m << endl;
        if (can(v, k)) r.pb(k);
    }

    cout << r.size() << " ";
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
