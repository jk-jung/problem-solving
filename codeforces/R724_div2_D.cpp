#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define ab(x) (((x)<0)?-(x):(x))


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        map<int, int> ck;
        for (int i = 0; i < n; i++)cin >> v[i];

        ck[v[0]] = 1;
        bool r = true;
        for (int i = 1; i < n; i++) {
            int s = min(v[i - 1], v[i]);
            auto it = ck.lower_bound(s + 1);

            if (it != ck.end() && s < it->first && it->first < max(v[i - 1], v[i])) {
                r = false;
                break;
            }
            ck[v[i]] = 1;
        }
        cout << (r ? "YES" : "NO") << endl;
    }
}
