#include "GenericSeqList.h"

List* _initList(int elem_size,void (*free_fun)(void*)){
	if(elem_size==0){
		return NULL;
	}

	List* list = malloc(sizeof(List));
	if(!list) return NULL;
	list->elem_size = elem_size;
	list->arr = malloc(LIST_CAPACITY*elem_size);
	if(!list->arr){
		free(list);
		return NULL;
	}
	return list;
}

void _addToList(List*list,void* elem,int elem_size){

}
