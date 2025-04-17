/**
 * -------------------------------------
 * @file  expression.c
 * file description
 * -------------------------------------
 * @author Giuseppe Akbari, 169057752, akba7752@mylaurier.ca
 *
 * @version 2025-02-22
 *
 * -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

QUEUE infix_to_postfix(char *infixstr) {
// your code
	char *p = infixstr;
	QUEUE queue = { 0 };
	STACK stack = { 0 };
	int sign = 1;
	int num = 0;
	while (*p) {
		if (*p == '-' && (p == infixstr || *(p - 1) == '(')) {
			sign = -1;
		} else if (mytype(*p) == 0) { //*p is a digit
			num = *p - '0';
			while (*(p + 1) >= '0' && *(p + 1) <= '9') {
				num = num * 10 + *(p + 1) - '0';
				p++;
			}
			enqueue(&queue, new_node(sign * num, 0));
			sign = 1;
		} else if (mytype(*p) == 1) { //*p is an operator +,-...
			NODE *hol = stack.top;
			while (stack.top && priority(hol->data) >= priority(*p)) {
				enqueue(&queue, pop(&stack));
				hol = stack.top;
			}
			push(&stack, new_node(*p, mytype(*p)));
		} else if (mytype(*p) == 2) { //*p == '('
			push(&stack, new_node(*p, mytype(*p)));
		} else if (mytype(*p) == 3) { //*p==')'
			NODE *tol = stack.top;
			while (stack.top && tol->data != '(') {
				enqueue(&queue, pop(&stack));
				tol = stack.top;
			}
			pop(&stack);
		}
		p++;
	}
	while (stack.top) {
		enqueue(&queue, pop(&stack));
	}
	return queue;
}

int evaluate_postfix(QUEUE queue) {
// your code
	NODE *p = queue.front;
	STACK stack = { 0 };
	int type = 0;
	while (p) {
		type = p->type;
		if (type == 0) {
			push(&stack, new_node(p->data, 0));
		} else if (type == 1) {
			int operator = p->data;
			NODE *operand2 = pop(&stack);
			NODE *op1 = stack.top;
			if (operator == '+') {
				op1->data = op1->data + operand2->data;
			} else if (operator == '-') {
				op1->data = op1->data - operand2->data;
			} else if (operator == '*') {
				op1->data = op1->data * operand2->data;
			} else if (operator == '/') {
				op1->data = op1->data / operand2->data;
			}
			free(operand2);
		}
		p = p->next;
	}
	NODE *h = stack.top;
	int result = h->data;
	clean_stack(&stack);
	return result;

	return 0;
}

int evaluate_infix(char *infixstr) {
// your code
	QUEUE q = infix_to_postfix(infixstr);

	return evaluate_postfix(q);
}
