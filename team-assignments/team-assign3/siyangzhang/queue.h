#ifndef _QUEUE_H
#define _QUEUE_H

queue_t *newQueue();

void enqueue(queue_t *queue, int val);

int dequeue(queue_t *queue);

void print(queue_t *queue);