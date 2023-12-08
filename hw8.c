• 5개의 실수를 입력받아 이를 배열에 저장한 후, 표준편차를 구해 이를 출력하는 프로그램을 작성
하세요. 단, 표준편차를 구하는 부분은 배열을 인자로 받는 별도의 함수에 구현되어야 합니다.
• 표준편차를 구하는 공식은 오른쪽과 같으며,
이를 C언어에서 구현하기 위해서는
아래 헤더파일과 함수를 이용합니다.
hw8.c 파일을 만들어 개인 github 리파지토리에 올려 주시기 바랍니다. (기한: 다음 수업시간 전)
포인터 (2) 27
Enter 5 real numbers: 1 2 3 4 5
Standard Deviation = 1.414
#include <math.h>
double pow(double a, double b); // a의 b승을 반환
double sqrt(double x); // 루트 x를 반환




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
