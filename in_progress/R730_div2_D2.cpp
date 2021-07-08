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


int xo(int a, int b, int k) {
    if (a < 0)return b;
    int r = 0, base = 1;
    while (a > 0 || b > 0) {
        r += base * ((a % k + b % k) % k);

        a /= k;
        b /= k;
        base *= k;
    }
    return r;
}

int rev(int a, int k) {
    int r = 0, base = 1;
    while (a > 0) {
        r += base * ((k - (a % k) + k) % k);
        a /= k;
        base *= k;
    }
    return r;
}

int xo_rev(int a, int b, int k) {
    if (a < 0)return b;
    if (b < 0)return a;
    int r = 0, base = 1;
    while (a > 0 || b > 0) {
        r += base * ((b % k - a % k + k) % k);

        a /= k;
        b /= k;
        base *= k;
    }
    return r;
}

void pp(int a, int k) {
    vector<int> v;
    if (a == 0)v.pb(0);
    while (a) {
        v.pb(a % k);
        a /= k;
    }
    cout << "[";
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
    cout << "]";
}

void solve() {
    int n, k;
    cin >> n >> k;

    int q = 0, r;
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << 0 << endl;
        else cout << (i ^ (i - 1)) << endl;
        cout.flush();
        cin >> r;
        if (r == 1)break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k = 4;


    vector<int> v;
    v.pb(0);
    for(int i=1;i<30;i++){
        int x = i;
        for(int j=0;j<=i;j++){
            int y = 0;
            if (j < v.size()) {
                y = v[j];
            }
            else if(j == i) v.pb(x);
            int z = xo_rev(x, y, k);
            x = z;
        }
        printf("[%d] %d: ", i, v.back());
        pp(v.back(), k);
        cout << endl;
    }
    return 0;
//    cout << xo(5, 8, k) << endl;
//    cout << xo_rev(5, 1, k) << endl;
//    return 0;
    cout << " @@@@@@@@@@@@@@@@@@@@@\n";
    int last = -1;
    for (int x = 5; x <= 5; x++) {
        for (int j = 0; j < 10; j++) {
            int y = 0;
            if (j > 0) {
                y = rev(xo(last, j, k), k);
            }

            int z = xo_rev(x, y, k);


            last = y;

            printf("[%d] %d %d %d | %d \n", j, x, y, z, xo_rev(z, j, k));
            if (x == y) printf("@@@@@@ %d %d\n", x, j);
            x = z;

//            cout << i;
//            pp(i, k);
//            cout << "  " << j;
//            pp(j, k);
//            cout<< "  " << x;
//            pp(x, k);
//            cout << endl;
//            printf("%d %d %d\n", i, j, x, xo_rev(x , j));
        }

//        cout << endl;
    }

//    int t;
//    cin >> t;
//    while (t--) {
//        solve();
//    }
}
