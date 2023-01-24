#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exp.h"

struct node {
	char op;
	double val;
	struct node *left;
	struct node *right;
};

Exp eNum(double val) {
	Exp a = malloc(sizeof(struct node));
	a->op = '\0';
	a->val = val;
	a->left = NULL;
	a->right = NULL;
	return a;
}

Exp eSum(Exp l,Exp r) {
	Exp a = malloc(sizeof(struct node));
	a->op = '+';
	a->val = 0;
	a->left = l;
	a->right = r;
	return a ;
}

Exp eSott(Exp l,Exp r) {
	Exp a = malloc(sizeof(struct node));
	a->op = '-';
	a->val = 0;
	a->left = l;
	a->right = r;
	return a ;
}

Exp eMol(Exp l,Exp r) {
	Exp a = malloc(sizeof(struct node));
	a->op = '*';
	a->val = 0;
	a->left = l;
	a->right = r;
	return a ;
}

Exp eDiv(Exp l,Exp r) {
	Exp a = malloc(sizeof(struct node));
	a->op = '/';
	a->val = 0;
	a->left = l;
	a->right = r;
	return a ;
}

void printExp(Exp e) {
	if(e->op == '\0') {
		printf("%g",e->val);
	}else {
		printf("(");
		printExp(e->left);
		printf("%c",e->op);
		printExp(e->right);
		printf(")");
	}
}

double eEval(Exp e) {
	switch(e->op) {
		case '\0': return e->val; break;
			case '+' : return eEval(e->left)+eEval(e->right); break;
				case '-' : return eEval(e->left)+eEval(e->right); break;
						case '*' : return eEval(e->left)+eEval(e->right); break;
								case '/' : return eEval(e->left)+eEval(e->right); break;
	}
}



		
	
