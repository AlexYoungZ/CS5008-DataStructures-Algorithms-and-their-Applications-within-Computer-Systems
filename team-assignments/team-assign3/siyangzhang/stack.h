#ifndef _STACK_H
#define _STACK_H

stack_t *newStack();

int isEmpty(stack_t *stack);

void push(stack_t *stack, int val);

int pop(stack_t *stack);

int peek(stack_t *stack);

void print(stack_t *stack);