도시의 이름, 속한 국가, 인구 수에 대한 정보를 저장할 수 있는 간단한 구조체를 정의하고, 구조체
배열을 선언해서 이러한 도시에 대한 정보를 저장하는 구조로 작성하세요. 메인 함수에는 사용자
로부터 3개 도시에 대한 정보를 입력 받고, 입력이 끝나면 이 도시에 대한 내용을 출력해 주세요.

+) 입력버퍼를 비우는 함수
    while(getchar()!='\n')
printf("세 개의 도시 정보를 입력하세요:\n");: 사용자에게 세 개의 도시 정보를 입력하라는 안내 메시지를 출력합니다.

for (i = 0; i < 3; i++) {: 반복문을 사용하여 세 번의 도시 정보를 입력받습니다. i는 반복문의 제어 변수로 사용됩니다.

printf("도시 이름> ");: 사용자에게 도시 이름을 입력하라는 안내 메시지를 출력합니다.

fgets(city_list[i].name, MAX_STRING_SIZE, stdin);: 사용자가 입력한 도시 이름을 city_list[i].name에 저장합니다. 
fgets 함수는 키보드로부터 입력을 받아 문자열을 읽어옵니다. MAX_STRING_SIZE는 최대 입력 가능한 문자열의 길이를 나타냅니다.

    [정 답]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 50 // 코드할 때 MAX 써있는 거 30으로 다 바뀜 

typedef struct city {
    char name[MAX_STRING_SIZE];
    char country[MAX_STRING_SIZE];
    int population;
} City;

int main(void) {
    City city_list[3] = { {0} };
    int i;

    printf("세 개의 도시 정보를 입력하세요:\n");
    for (i = 0; i < 3; i++) {
        printf("도시 이름> ");
        fgets(city_list[i].name, MAX_STRING_SIZE, stdin);

        printf("국가 이름> ");
        fgets(city_list[i].country, MAX_STRING_SIZE, stdin);

        printf("인구 수> ");
        scanf("%d", &(city_list[i].population));

        while (getchar() != '\n');
    }
    printf("\n");

    printf("입력된 도시 정보 출력:\n");
    for (i = 0; i < 3; i++) {
        city_list[i].name[strlen(city_list[i].name) - 1] = '\0';
        city_list[i].country[strlen(city_list[i].country) - 1] = '\0';
        printf("% d. % s in % s with a population of % d people \n",
            i + 1, city_list[i].name, city_list[i].country, city_list[i].population);
    }

    return 0;
}
