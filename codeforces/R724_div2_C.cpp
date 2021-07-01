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


int D[500005];
int K[500005];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        map<pair<int, int>, int> ck;

        for (int i = 1; i <= n; i++) {
            D[i] = D[i - 1];
            K[i] = K[i - 1];
            if (s[i - 1] == 'D') D[i]++;
            else K[i]++;

            if (D[i] == 0 || K[i] == 0)
                cout << i << " ";
            else {
                int g = gcd(D[i], K[i]);
                auto k = make_pair(D[i] / g, K[i] / g);
                ck[k] = ck[k] + 1;
                cout << ck[k] << " ";
            }
        }
        cout << endl;
    }
}
