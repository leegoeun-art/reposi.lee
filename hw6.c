• 총 5개의 정수를 배열로 한꺼번에 입력 받아서, 홀수와 짝수를 구분지어 출력하는 프로그램을 작
성해 보세요.
hw6.c 파일을 만들어 개인 github에 올려 주시기 바랍니다. (기한: 다음 주 수업시간 전까지)
배열 39
Please input five integers: 3 7 10 15 18
Odd numbers: 3 7 15
Even numbers: 10 18

{
  
  
  int ary[5];
printf("please input five integers ");

for (int i = 0; i <5; i++)
  scanf("%d", &ary[i]);

printf("\n");

printf("Odd numbers: ");
for (int i = 0; i < 5; i++)
  if (ary[i] % 2 == 1) printf("%d", ary[1]);

printf("\nEven numbers: ");
for (int i=0; i<5; i++)
  if (ary[i] % 2 == 0) printf("%d", ary[i]);

return 0;
}
