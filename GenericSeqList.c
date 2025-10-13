#include "GenericSeqList.h"

List* _initList(int elem_size,void (*free_fun)(void*)){
	//判断入参有无问题
	if(elem_size==0){
		return NULL;
	}
	//为list对象开辟空间
	List* list = malloc(sizeof(List));
	if(!list) return NULL;
	list->elem_size = elem_size;
	list->capacity = LIST_CAPACITY;
	//为对象中的数组开辟空间
	list->arr = malloc(LIST_CAPACITY*elem_size);
	if(!list->arr){
		free(list);
		return NULL;
	}
	return list;
}

void _addToList(List*list,void* elem,int elem_size){
	if(!list|| !elem||elem_size!=list->elem_size){
		return;
	}

	//检查是否需要扩容
	if(list->size >= list->capacity){
		//执行扩容
	}
	//添加元素
	//找到数组结束位置，复制固定大小，改变size
	void*target = (char*)list->data + (list->size*list->list->elem_size);
	memcpy(target,elem,list->elem_size);
	list->size++;
}
