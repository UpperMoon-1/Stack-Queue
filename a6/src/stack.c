/**
 * -------------------------------------
 * @file  stack.c
 * file description
 * -------------------------------------
 * @author Giuseppe Akbari, 169057752, akba7752@mylaurier.ca
 *
 * @version 2025-02-22
 *
 * -------------------------------------
 */

#include <stdio.h>
#include "stack.h"

//stack adds and removes from the top of the stack

void push(STACK *sp, NODE *np) { //add one to the top of the stack
// your code
	if (sp->top == NULL) { //the stack is empty
		sp->length++;
		sp->top = np;

	} else { //the stack is not empty, add one to the top os the stack i.e. new node the the top of stack
		sp->length++;
		np->next = sp->top;
		sp->top = np;

	}

}

NODE* pop(STACK *sp) {
// your code
	if (sp->length > 0) {
		if (sp->length == 1) {
			sp->length--;
			NODE *del = sp->top;
			sp->top = NULL;
			del->next = NULL;
			return del;
		} else {
			sp->length--;
			NODE *del = sp->top;
			sp->top = del->next;
			del->next = NULL;
			return del;

		}
	}
}

void clean_stack(STACK *sp) {
	clean(&(sp->top));
	sp->top = NULL;
	sp->length = 0;
}
