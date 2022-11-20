#include <stdio.h>

double truncate_to_2_decimals(double n)
{
    return (double)((int)(n*100.0)) / 100.0;
}

double mean(int n, double numbers[])
{
    double r;
    int i;
    for(i = 0; i < n; i++) {
        r += numbers[i];
    }
    return r / (double)n;
}

double min_exchange(int n, double expenses[])
{
    double r;
    double mu = mean(n, expenses);
    int i;
    for(i = 0; i < n; i++) {
        double e = expenses[i];
        if(e < mu) {
            r += mu - e;
        }
    }
    return truncate_to_2_decimals(r);
}

int main(int argc, char *argv[])
{
    int n_students;

    while(scanf("%d", &n_students) != EOF) {
        if(n_students == 0) {
            break;
        }
        double expenses[n_students];
        int i;
        for(i = 0; i < n_students; i++) {
            scanf("%lf", &expenses[i]);
        }
        printf("$%.2lf\n", min_exchange(n_students, expenses));
    }
    return 0;
}