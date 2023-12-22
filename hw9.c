[연습문제21-1] 사용자로부터 알파벳 문자 입력 받아서,
대문자 > 소문자, 소문자> 대문자
단, 문자의 입출력에는 getchar 함수와 putchar 함수를 사용. 
그리고 프로그램 사용자가 알파벳 이외의 문자를 입력하는 경우에는 그에 따른 오류 메시지를 간단히 출력하기로 하자
  
#include <stdio.h>
  
int convCase(int ch) // 모든 문자의 대소문자간 차의 크기는 같다.
{ 
  const int diff = 'a' - 'A'; 
  if (ch >= 'A' && ch <= 'Z')   문자 ch 가 대문자 알파벳 범위에 속하는지 확인.
      return ch + diff;     ch+diff 대문자인 경우 소문자로 변환한 값을 반환, diff 더하면 대문자>소문자
  else if (ch >= 'a' && ch <= 'z')   -> 문자 ch 가 소문자 알파벳 범위에 속하는지 확인.
      return ch - diff;        -> return ch - diff;: 소문자인 경우에는 대문자로 변환한 값을 반환합니다. diff를 빼면 소문자에서 대문자로 변환됩니다.
  else
      return -1;
}  

int main(void)
{
  int ch;   -> 정수형 변수 ch 선언  . 이 변수는 사용자로부터 입력 받은 문자를 저장할 때 사용됩니다.
  printf("문자 입력: ");
  ch = getchar(); // 문자 입력
  ch = convCase(ch); // 문자 변환 > ch = getchar();: getchar() 함수를 사용하여 사용자로부터 한 문자를 입력받고, 그 값을 변수 ch에 저장합니다.
   
  ->ch = convCase(ch);: convCase() 함수를 호출하여 문자 ch의 대소문자를 변환합니다. 반환된 값으로 ch를 갱신합니다.
  
  
  
  if (ch == -1)      - if (ch == -1): 변환 결과가 -1이면 (범위를 벗어난 입력인 경우) 다음 블록을 실행합니다.
  {
      puts("범위를 벗어난 입력입니다.");
      return -1;
  }
  putchar(ch); // 변환된 문자 출력
  return 0;
}     



  
[hw9] 
“문자열”을 입력받아, 이 문자열 내의 대문자는 소문자로, 소문자는 대문자로 바꾸고, 다른 문자는 그대로 출력해주는 프로그램을 작성하세요. 
• 입출력 예시 (입력은 볼드체)
문자와 문자열 관련 함수 40
Input> Hi, my name is ANONYMOUS! (볼드체)
Output> hI, MY NAME IS anonymous!

  [정답]
#include <stdio.h>
#include <string.h>
int convCase(int ch)
{ 
    const int diff = 'a' - 'A'; 
    if (ch >= 'A' && ch <= 'Z')
return ch + diff;
else if (ch >= 'a' && ch <= 'z')
return ch - diff;
else
return -1;

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


unsigned int i;: 부호 없는 정수형 변수 i를 선언합니다. 이 변수는 반복문에서 사용됩니다.

char buffer[50];: 길이가 50인 문자 배열 buffer를 선언합니다. 이 배열은 입력받은 문자열을 저장하는 데 사용됩니다.

printf("input> ");: 사용자에게 입력을 요청하는 메시지를 출력합니다.

fgets(buffer, sizeof(buffer), stdin);: fgets 함수를 사용하여 사용자로부터 문자열을 입력받고, 이를 buffer에 저장합니다. 입력받을 수 있는 최대 문자 수는 sizeof(buffer) - 1입니다.

for (i = 0; i < strlen(buffer) - 1; i++): 반복문을 사용하여 문자열의 각 문자에 접근합니다. strlen(buffer) - 1은 개행 문자를 제외한 문자열의 길이를 나타냅니다.

buffer[i] = convCase(buffer[i]);: convCase 함수를 호출하여 buffer[i]에 저장된 문자의 대소문자를 변환합니다.

buffer[i] = 0;: 반복문을 통해 변환된 문자열의 끝을 나타내는 null 문자('\0')를 추가합니다.

printf("output> %s", buffer);: 변환된 문자열을 출력합니다.
