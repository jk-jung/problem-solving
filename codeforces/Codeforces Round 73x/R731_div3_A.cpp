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
        int x[3], y[3];
        for (int i = 0; i < 3; i++) {
            cin >> x[i] >> y[i];
        }
        int r = ab(x[0] - x[1]) + ab(y[0] - y[1]);

        if (x[0] == x[1] && x[1] == x[2] && min(y[0], y[1]) < y[2] && y[2] < max(y[0], y[1])) {
            cout << r + 2<< endl;
        } else if (y[0] == y[1] && y[1] == y[2] && min(x[0], x[1]) < x[2] && x[2] < max(x[0], x[1])) {
            cout << r + 2<< endl;
        } else {
            cout << r << endl;
        }
    }
}
