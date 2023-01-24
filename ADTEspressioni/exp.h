typedef struct node *Exp;

Exp eNum(double val);
Exp eSum(Exp l,Exp r);
Exp eSott(Exp l,Exp r);
Exp eMol(Exp l,Exp r);
Exp eDiv(Exp l,Exp r);
void printExp(Exp e);
double eEval(Exp e);