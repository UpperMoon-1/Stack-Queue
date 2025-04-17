/**
 * -------------------------------------
 * @file  queue.c
 * file description
 * -------------------------------------
 * @author Giuseppe Akbari, 169057752, akba7752@mylaurier.ca
 *
 * @version 2025-02-22
 *
 * -------------------------------------
 */
#include <stdio.h>
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) { //insert to the end
// your code
	qp->length++;
	if (qp->front == NULL) {
		qp->front = np;
		qp->rear = np;
	} else {
		qp->rear->next = np;
		qp->rear = np;
	}
	return;

}

NODE* dequeue(QUEUE *qp) { //remove the front
// your code
	NODE *node = qp->front;
	if (qp->length != 0) {
		qp->length--;
		if (qp->length == 0) {
			qp->front = NULL;
			qp->rear = NULL;
		} else {
			node = qp->front;
			qp->front = qp->front->next;

		}
	}
	return node;

}

void clean_queue(QUEUE *qp) {
	clean(&(qp->front));
	qp->front = NULL;
	qp->rear = NULL;
	qp->length = 0;
}
