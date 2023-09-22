#include <stdio.h>

int main(void) {
	double kilo;
	double mile;
	printf("Please enter kilometers: ");
	scanf_s("%lf", &kilo);
	mile = (1 / 1.609) * kilo;
	printf("%.1f km is equal to %.1f miles.", kilo, mile);
	return 0;
}