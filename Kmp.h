#include <stdio.h>
#include <stdlib.h>
#include  <string.h>


//create a pattern arr with kmp method
void createNextArr(char* pattern,int next[]);

void findMaxSubString(char* mainString,char* pattern,int next[]);
