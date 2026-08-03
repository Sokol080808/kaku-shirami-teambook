/**
 * Author: talant(KAN)
 * Date: 2024-08-9
 * Description: Simplex
 * Time: exponential XD(ok for 200-300 variables/bounds)
 */

/* solver for linear programs of the form
maximize c^T x, subject to A x <= b, x >= 0
outputs target function for optimal solution and
the solution by reference
if unbounded above : returns inf, if infeasible : returns -inf
create Simplex_Steep <ld > LP(A, b, c), then call LP. Solve (x)
*/
template <typename DOUBLE>
struct Simplex_Steep {
    using VD = vector<DOUBLE>;
    using VVD = vector<VD>;
    using VI = vector<int>;
    DOUBLE EPS = 1e-12;
    int m, n;
    VI B, N;
    VVD D;
    Simplex_Steep(const VVD &A, const VD &b, const VD &c)
        : m(b.size()), n(c.size()), B(m), N(n + 1), D(m + 2, VD(n + 2)) {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) D[i][j] = A[i][j];
        for (int i = 0; i < m; i++) {
            B[i] = n + i;
            D[i][n] = -1;
            D[i][n + 1] = b[i];
        }
        for (int j = 0; j < n; j++) {
            N[j] = j;
            D[m][j] = -c[j];
        }
        N[n] = -1;
        D[m + 1][n] = 1;
    }
    void Pivot(int r, int s) {
        for (int i = 0; i < m + 2; i++)
            if (i != r)
                for (int j = 0; j < n + 2; j++)
                    if (j != s) D[i][j] -= D[r][j] * D[i][s] / D[r][s];
        for (int j = 0; j < n + 2; j++)
            if (j != s) D[r][j] /= D[r][s];
        for (int i = 0; i < m + 2; i++)
            if (i != r) D[i][s] /= -D[r][s];
        D[r][s] = 1.0 / D[r][s];
        swap(B[r], N[s]);
    }
    bool Simplex(int phase) {
        int x = m + (int)(phase == 1);
        while (true) {
            int s = -1;
            DOUBLE c_val = -1;
            for (int j = 0; j <= n; j++) {
                if (phase == 2 && N[j] == -1) continue;
                DOUBLE norm_sq = 0;
                for (int k = 0; k <= m; k++) norm_sq += D[k][j] * D[k][j];
                norm_sq = max(norm_sq, EPS);
                DOUBLE c_val_j = D[x][j] / sqrtl(norm_sq);
                if (s == -1 || c_val_j < c_val ||
                    (c_val == c_val_j && N[j] < N[s])) {
                    s = j;
                    c_val = c_val_j;
                }
            }
            if (D[x][s] >= -EPS) return true;
            int r = -1;
            for (int i = 0; i < m; i++) {
                if (D[i][s] <= EPS) continue;
                if (r == -1 || D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||
                    (D[i][n + 1] / D[i][s] == D[r][n + 1] / D[r][s] &&
                     B[i] < B[r]))
                    r = i;
            }
            if (r == -1) return false;
            Pivot(r, s);
        }
    }
    DOUBLE Solve(VD &x) {
        int r = 0;
        for (int i = 1; i < m; i++)
            if (D[i][n + 1] < D[r][n + 1]) r = i;
        if (D[r][n + 1] <= -EPS) {
            Pivot(r, n);
            if (!Simplex(1) || D[m + 1][n + 1] < -EPS)
                return -numeric_limits<DOUBLE>::infinity();
            for (int i = 0; i < m; i++)
                if (B[i] == -1) {
                    int s = -1;
                    for (int j = 0; j <= n; j++)
                        if (s == -1 || D[i][j] < D[i][s] ||
                            (D[i][j] == D[i][s] && N[j] < N[s]))
                            s = j;
                    Pivot(i, s);
                }
        }
        if (!Simplex(2)) return numeric_limits<DOUBLE>::infinity();
        x = VD(n);
        for (int i = 0; i < m; i++)
            if (B[i] < n) x[B[i]] = D[i][n + 1];
        return D[m][n + 1];
    }
};
