#include <stdio.h>
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
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        n *= 2;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size() / 2; i ++)
            cout << v[i] << " " << v[i + v.size() / 2] << " ";
        cout << endl;
    }
}
