도시의 이름, 속한 국가, 인구 수에 대한 정보를 저장할 수 있는 간단한 구조체를 정의하고, 구조체
배열을 선언해서 이러한 도시에 대한 정보를 저장하는 구조로 작성하세요. 메인 함수에는 사용자
로부터 3개 도시에 대한 정보를 입력 받고, 입력이 끝나면 이 도시에 대한 내용을 출력해 주세요.
hw10.c 파일을 만들어 개인 github 리파지토리에 올려 주시기 바랍니다. (기한: 다음 수업시간 전)

#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 30 //코드할 때 MAX 써있는 거 30으로 다 바뀜 
    
typedef struct city
{
    char name[MAX_STRING_SIZE]
    char country[MAX_STRING_SIZE]
    int population;
}city;

int main() {
    // 도시 정보를 저장하는 구조체 배열 선언
    struct City cities[3];

    // 사용자로부터 3개 도시에 대한 정보 입력 받기
    printf("Input three cities:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Name> ");
        fgets(city_list[i].name, MAX_STRING_SIZE, stdin);

        printf("Country> ");
        fgets(city_list[i].name, MAX_STRING_SIZE, stdin);

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
