#include <stdio.h>

void decimalToBinary(int decimal) {
    if (decimal > 0) {
        decimalToBinary(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main() {
    int decimal;
    printf("양의 정수를 입력하세요: ");
    scanf("%d", &decimal);

    if (decimal < 0) {
        printf("음수가 아닌 양의 정수를 입력하세요.\n");
    } else {
        printf("2진수로 변환: ");
        if (decimal == 0) {
            printf("0");
        } else {
            decimalToBinary(decimal);
        }
        printf("\n");
    }

    return 0;
}
