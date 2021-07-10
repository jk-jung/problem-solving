#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<int> v(4);
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        int a = max(v[0], v[1]);
        int b = max(v[2], v[3]);
        if (a < b) swap(a, b);
        sort(v.begin(), v.end());
        cout << (a == v[3] && b == v[2] ? "YES" : "NO") << endl;
    }
}
