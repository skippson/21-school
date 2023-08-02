#include <stdio.h>
#define NMAX 10

int input(long int *a, int *n, long int *k);
void cycle(long int *a, int n, long int k);
void mi_cycle(long int *a, int n, long int k);
void output(long int *a, int n);

int main() {
    int n;
    long int data[NMAX], k;
    if (input(data, &n, &k) == 0) {
        printf("n/a");
        return 0;
    }
    if(k < 0){
       mi_cycle(data, n, k);
    } else{
        cycle(data, n, k);
    }
    output(data, n);

    return 0;
}

int input(long int *a, int *n, long int *k) {
    if (scanf("%d", n) && (*n <= 10) && (*n > 0)) {
        for (int i = 0; i < *n; i++) {
            if (scanf("%ld", &a[i])) {
                continue;
            } else {
                return 0;
            }
        }
        if(scanf("%ld", k) == 0){
            return 0;
        } else{
            return 1;
        }
    } else {
        return 0;
    }
}

void cycle(long int *a, int n, long int k) {
    long int temp[k];
    if (k > n) {
        k = k % n;
    }
    for (int i = 0; i < n; i++) {
        if ((i - k) < 0) {
            temp[i] = a[i];
            a[i] = 0;
        } else {
            long int d = a[i - k];
            a[i - k] = a[i];
            a[i] = d;
        }
    }
    for (int i = 0; i < k; i++) {
        int y = n - (-1 * (i - k));
        a[y] = temp[i];
    }
}

void mi_cycle(long int *a, int n, long int k){
    k *= -1;
    long int temp[k];
    if (k > n) {
        k = k % n;
    }
    int j = k - 1;
    for(int i = (n - 1); i >= 0; i--){
        if((i + k) >= n){
            temp[j] = a[i];
            a[i] = 0;
            j--;;
        } else{
            int d = a[i];
            a[i] = a[i+k];
            a[i+k] = d;
        }
    }
    for(int i = k - 1; i >= 0; i--){
        a[i] = temp[i];
    }

}

void output(long int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%ld ", a[i]);
    }
    printf("%ld", a[n - 1]);
}
