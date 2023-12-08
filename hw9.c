연습문제 21-1을 응용하여, 
“문자열”을 입력받아, 이 문자열 내의 대문자는 소문자로, 소문자는 대
문자로 바꾸고, 다른 문자는 그대로 출력해주는 프로그램을 작성하세요. 
• 입출력 예시 (입력은 볼드체)
hw9.c 파일을 만들어 개인 github 리파지토리에 올려 주시기 바랍니다. (기한: 다음 수업시간 전)
문자와 문자열 관련 함수 40
Input> Hi, my name is ANONYMOUS!
Output> hI, MY NAME IS anonymous!
  ===================

#include <stdio.h>
#include <string.h>



{
  return ch;
}
int main8(void)(buffer) - 1; i++)
{
unsigned int i;
char buffer[50];
printf("input >");
fgets (buffer,sizeof(buffer),stdin);

for (i=0; i<strlen(buffer) -1; i++)
  buffer[i] =convcase(buffer[i]);
buffer[i] = 0;

printf("output> %s", buffer);
}


