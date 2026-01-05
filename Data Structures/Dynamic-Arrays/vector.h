    
#ifndef VECTOR_H


static int tail = 0;
static int capcity = 0;

int *vector_create(int size);
void vector_push_back(int value, int **__array);
void vector_pop_back(int **__array);
int *resize(int *array);


#endif // !VECTOR_H

