#include <stdio.h>
#include <stdlib.h>
#include "HaffList.h"
#include <string.h>

void createHaffmanTree(LinkedList*list,HaffmanNode** node);

void selectChildren(HaffmanNode* node,LinkedList*list);

void midSeek(HaffmanNode*node,char* str);
