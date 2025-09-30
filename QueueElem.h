//ifndef用于多个文件重复引用一个文件，使用时#ifndef MYCLASS_H #define MYCLASS_H #endif
//也可以使用#pragma once来确保引用一次
#pragma once

#include <stdio.h>
#include <stdlib.h>

#define QueueElem int
