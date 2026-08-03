/**
 * Author: daubi
 * Date: 2024-09-11
 * Description: det(a - xI)
 */
vector<int> CharacteristicPolynomial(vector<vector<int>> a) {
    int n = a.size();
    for(int j = 0; j < n - 2; j++) {
        for(int i = j + 1; i < n; i++) {
            if(a[i][j] != 0) {
                swap(a[j + 1], a[i]);
                for(int k = 0; k < n; k++) swap(a[k][j + 1], a[k][i]);
                break;
            }
        }
        if(a[j + 1][j] != 0) {
            int flex = inv(a[j + 1][j]);
            for(int i = j + 2; i < n; i++) {
                if(a[i][j] == 0) continue;
                int coe = mul(flex, a[i][j]);
                for(int l = j; l < n; l++) a[i][l] = sub(a[i][l], mul(coe, a[j + 1][l]));
                for(int k = 0; k < n; k++) a[k][j + 1] = add(a[k][j + 1], mul(coe, a[k][i]));
            }
        }
    }
    vector<vector<int>> p(n + 1);
    p[0] = {1};
    for(int i = 1; i <= n; i++) {
        p[i].resize(i + 1);
        for(int j = 0; j < i; j++) {
            p[i][j + 1] = sub(p[i][j + 1], p[i - 1][j]);
            p[i][j] = add(p[i][j], mul(p[i - 1][j], a[i - 1][i - 1]));
        }
        int x = 1;
        for(int m = 1; m < i; m++) {
            x = mul(x, sub(0, a[i - m][i - m - 1]));
            int coe = mul(x, a[i - m - 1][i - 1]);
            for(int j = 0; j < i - m; j++) p[i][j] = add(p[i][j], mul(coe, p[i - m - 1][j]));
        }
    }
    return p[n];
}