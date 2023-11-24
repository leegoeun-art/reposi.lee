#include <stdio.h>
#include <math.h>

double calculateMean(double arr[], int size) {
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}

double calculateStandardDeviation(double arr[], int size) {
    double mean = calculateMean(arr, size);
    double sumSquaredDiff = 0.0;

    for (int i = 0; i < size; i++) {
        sumSquaredDiff += pow(arr[i] - mean, 2);
    }

    return sqrt(sumSquaredDiff / size);
}

int main() {
    double numbers[5];

    printf("Enter 5 real numbers: ");
    for (int i = 0; i < 5; i++) {
        scanf("%lf", &numbers[i]);
    }

    double standardDeviation = calculateStandardDeviation(numbers, 5);
    printf("Standard Deviation = %.3lf\n", standardDeviation);

    return 0;
}
