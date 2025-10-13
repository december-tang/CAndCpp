//此类主要用来实现泛型List,sortList方法为回调函数,其他基本函数统一处理
#define bool char

#define listMaxSize 16
#define TRUE 1
#define FALSE 0
typedef struct ListNode{
	struct ListNode* next;
	QueueElem data;
}ListNode;

typedef struct List{
	ListNode* head;
	ListNode* tail;
	int size;
}LinkedList;

typedef void (*fun_callback)(LinkedList*queue);

LinkedList* generic_list_create(int elem_size,void (*free_func)(void*));

void generic_elem_add(LinkedList*list,void*element,int elem_size);

void generic_elem_remove(LinkedList*list,int index);

void generic_elem_remove_elem(LinkedList*list,void*element);

void* generic_elem_get(LinkedList*list,int index);


#define LIST_CREATE(type,free_func) generic_list_create(sizeof(type),free_func)

#define LIST_ADD(list,element) \
		typeof(element) _temp = (element);\
		generic_list_add(list,&_temp,sizeof(element))

#define LIST_GET(list,index,type) (type*)generic_list_get((list),(index))

#define LIST_REMOVE(list,index) generic_list_remove((list),(index))

//对remove函数进行重载
#define LIST_REMOVE(list,element) \
	typeof(element) _temp = (element);\
	generic_list_remove_elem((list),(element))


//void addToLinkedList(LinkedList*queue,QueueElem data);

//bool removeFromLinkedList(LinkedList*queue,QueueElem data);

//void printLinkedList(LinkedList*queue);

