class BipartiteMatching {
public:
    int n, m, CK;
    vi L, R, ck;
    vector<vi> v;

    void init(int _n, int _m, vector<vi> _v) {
        n = _n, m = _m, v = _v;
        L.resize(n, -1);
        R.resize(m, -1);
        ck.resize(n, -1);
    }

    int match() {
        int r = 0;
        for (int i = 0; i < n; i++, CK++)r += find(i);
        return r;
    }

    bool find(int x) {
        if(ck[x] == CK) return false;
        ck[x] = CK;

        for (int y: v[x]) {
            if (R[y] == -1 || find(R[y])) {
                R[y] = x;
                L[x] = y;
                return true;
            }
        }
        return false;
    }
};