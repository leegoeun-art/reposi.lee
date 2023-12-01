#include <stdio.h>

// 도시 정보를 저장하는 구조체
struct City {
    char name[100];
    char country[100];
    int population;
};

int main() {
    // 도시 정보를 저장하는 구조체 배열 선언
    struct City cities[3];

    // 사용자로부터 3개 도시에 대한 정보 입력 받기
    printf("Input three cities:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Name> ");
        scanf("%s", cities[i].name);

        printf("Country> ");
        scanf("%s", cities[i].country);

        printf("Population> ");
        scanf("%d", &cities[i].population);
    }

    // 입력 받은 도시 정보 출력
    printf("\nPrinting the three cities:\n");
    for (int i = 0; i < 3; ++i) {
        printf("%d. %s in %s with a population of %d people\n", i + 1, cities[i].name, cities[i].country, cities[i].population);
    }

    return 0;
}
