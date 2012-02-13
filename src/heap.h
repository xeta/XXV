#ifndef HEAP_H_
#define HEAP_H_

#define heap_type int
#define heap_step sizeof(heap_type)

heap_type* heap_parent(heap_type*, heap_type*);
heap_type* heap_left(heap_type*, heap_type*);
heap_type* heap_right(heap_type*, heap_type*);

#endif /* HEAP_H_ */
