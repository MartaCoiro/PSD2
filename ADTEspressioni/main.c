#include <stdio.h>
#include <string.h>
#include "exp.h"

int main() {
	Exp e = eSum(eSott(eNum(6.1),eNum(7)),eMol(eDiv(eNum(5),eNum(3)),eNum(4)));
	printExp(e);
	printf("\nIl valore dell'espressione e' : %g",eEval(e));
	
	return 0;
}