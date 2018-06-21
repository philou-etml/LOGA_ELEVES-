#include <stdlib.h>
#include <stdio.h>
#include "FctFractorielle.h"
//#include <type>

main()
{
	double sliV_VarAffi = 0;
	int ValFib = 0;
	uint8 ValMultiple = 20;
	/*sliV_VarAffi = TestFonction();
	printf("%lf", sliV_VarAffi);
	printf("\n%lf", TestFonction());*/

	sliV_VarAffi = FctFactorielle(&ValMultiple);
	ValFib = fib(40);
	printf("%.0lf \n%d", sliV_VarAffi, ValFib);
	getchar();
}