/**
 * -------------------------------------
 * @file  queue.h
 * file description
 * -------------------------------------
 * @author Giuseppe Akbari, 169057752, akba7752@mylaurier.ca
 *
 * @version 2025-02-22
 *
 * -------------------------------------
 */
#ifndef QUEUE_H
#define QUEUE_H
#include "common.h"

typedef struct queue {
	int length;
	NODE *front;
	NODE *rear;
} QUEUE;

void enqueue(QUEUE *qp, NODE *np);
NODE* dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

#endif /* QUEUE_H_ */
