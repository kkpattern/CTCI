// Implement a MyQueue class which implements a queue using two stacks.
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "ctci/stacks.h"

typedef struct _MyQueue {
  Stacks *stacks;
} MyQueue;

// Initialize a MyQueue.
// @in length: The initial length of the queue.
// @return: Pointer to the newly initialized queue. NULL if any error on
//   allocating memory.
MyQueue *my_queue_init(size_t initial_length) {
  MyQueue *queue = (MyQueue *) malloc(sizeof(MyQueue));
  if (NULL == queue) return NULL;

  queue->stacks = stacks_init(2, initial_length);
  if (NULL == queue->stacks) {
    free(queue);
    return NULL;
  }
  return queue;
}

// Push a value into the queue.
// @in queue: The queue into which the value is pushed.
// @in value: The value to push.
// @return: 0 if the value is successfully pushed. 1 if any error on allocating
//   memory.
int my_queue_enqueue(MyQueue *queue, int value) {
  int result = stacks_push(queue->stacks, 1, value);
  if (2 == result) return 1;
  
  return 0;
}

// Pop a value out from the queue.
// @in queue: The queue from which the value is popped.
// @out value: The popped value.
// @return: 0 if the value is successfully popped. 1 if the queue is empty.
int my_queue_dequeue(MyQueue *queue, int *value) {
  int tmp;
  while (0 == stacks_pop(queue->stacks, 1, &tmp)) {
    stacks_push(queue->stacks, 2, tmp);
  }
  int result = stacks_pop(queue->stacks, 2, value);
  if (result == 2) return 1;

  while (0 == stacks_pop(queue->stacks, 2, &tmp)) {
    stacks_push(queue->stacks, 1, tmp);
  }
  return 0;
}

// Free a MyQueue.
// @in queue: The queue to free.
// @return: NULL.
MyQueue *my_queue_free(MyQueue *queue) {
  stacks_free(queue->stacks);
  free(queue);
  return NULL;
}

int main() {
  MyQueue *queue = my_queue_init(10);
  int value = 0;
  assert(1 == my_queue_dequeue(queue, &value));

  assert(0 == my_queue_enqueue(queue, 1));
  assert(0 == my_queue_dequeue(queue, &value));
  assert(1 == value);

  for (int i = 0; i < 5; ++i) {
    my_queue_enqueue(queue, i);
  }
  for (int i = 0; i < 5; ++i) {
    assert(0 == my_queue_dequeue(queue, &value));
  }

  my_queue_free(queue);
  return 0;
}
