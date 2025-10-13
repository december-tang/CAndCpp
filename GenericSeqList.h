#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define LIST_CAPACITY 100

typedef struct List{

	int size;//元素数量
	int head;
	int capacity;
	int elem_size;
	void* arr;
	void (*free_fun)(void*);
}List;


//内部实际调用函数，没有类型信息，只能从外部传参获得类型大小，通过typeof()获得类型
List* _initList(int elem_size,void (*free_fun)(void*));

void _addToList(List* list,void* elem,int elem_size);

//类型安全的宏接口中不需要指定类型，相当于只是一个占位，参数会被传递到内部的方法中。不需要以分号结尾
#define initList(elem_type,free_fun) _initList(sizeof(elem_type),free_fun)

#define addToList(list,elem) \
	typeof(elem) _temp = (elem);\
	_addToList((list),&_temp,sizeof(_temp))
