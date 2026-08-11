#include <stdio.h>
#include <math.h>

double minimumLoad(int population[], int n, int k) {

    double low = 0;
    double high = population[0];

    for (int i = 1; i < n; i++) {
        if (population[i] > high) {
            high = population[i];
        }
    }

    for (int iteration = 0; iteration < 100; iteration++) {

        double mid = (low + high) / 2.0;

        int clinicsNeeded = 0;

        for (int i = 0; i < n; i++) {
            clinicsNeeded += (int)ceil(population[i] / mid);
        }

        if (clinicsNeeded <= k) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}

int main() {

    int population[] = {200, 20, 50};
    int n = 3;
    int k = 5;

    double answer = minimumLoad(population, n, k);

    printf("%.2f\n", answer);

    return 0;
}