/**
 * Author: allvik
 * Date: ?
 * Description: subset convolution
 * Time: O(2^n * n^2) (500 ms n = 20 with pragms)
 */

void transform(int n, int N, vector <int>& b, const vector <int>& a, const vector <int>& pc, bool rev) {
    if (!rev) {
        b.assign(N << n, 0);
        for(int i = 0; i < (int)a.size(); ++i) b[pc[i] + i*N] = a[i];
    }
    for(int w = 1; w <= (1<<n); ++w) {
        for(int d = 0; !(w&(1<<d)); ++d){
            int W = N * (w - (1<<d)), dd = N<<d;
            for(int i = N * (w - (2<<d)); i < W; ++i) {
                if (!rev) b[i + dd] = add(b[i + dd], b[i]);
                else b[i + dd] = sub(b[i + dd], b[i]);
            }
        }
    }
}
vector<int> SubsetConvolution(const vector<int>& a, const vector<int>& b){
    int n = 0;
    while((1 << n) < max(a.size(),b.size())) n++;
    int N = n+1;
    vector<int> pc(1<<n,0);
    for(int i = 1; i < (1<<n); ++i) pc[i] = pc[i - (i&-i)] + 1;
    vector<int> bufA, bufB;
    transform(n, N, bufA, a, pc, false);
    transform(n, N, bufB, b, pc, false);
    for(int i = 0; i < (1<<n); i++) {
        int I = i * N;
        vector<int> Q(N);
        for(int ja = 0; ja <= pc[i]; ++ja) {
            for(int jb = pc[i] - ja, x = min(n - ja, pc[i]); jb <= x; ++jb){
                Q[ja + jb] = add(Q[ja + jb], mul(bufA[ja + I], bufB[jb + I]));
            }
        }
        copy(Q.begin(), Q.end(), bufA.begin() + I);
    }
    transform(n, N, bufA, a, pc, true);
    vector<int> res(1<<n);
    for(int i = 0; i<(1<<n); ++i) res[i] = bufA[pc[i] + i*N];
    return res;
}
