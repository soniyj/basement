/**
 * This program will show how to use C++ functions thru a C program
 *
 * @author:      Marco "soniyj" Matascioli
 * @date:        September 2013
 * @file:        main.c
 *
 * Copyright (C) 2013. Marco "soniyj" Matascioli
 * This code is released under the term of the GPL v2.
 */

#include <stdlib.h>
#include <stdio.h>

extern void* map_create();
extern void* map_create_func();
extern void map_put(void*, int, char*);
extern void map_put_func(void* map, char* k, void(*func_t)());
extern void map_get(void*, int);
extern void map_get_func(void* map, char* k);
extern void map_destroy(void*);

void f() {
	printf("This is a C code\n");
}

int main() {
	void* Map = map_create();
	void* MapF = map_create_func();
	
	printf("Simple map operation\n");
	map_put(Map, 1, "Test 1");
	map_get(Map, 1);
	map_put(Map, 2, "Test 2");
	map_get(Map, 2);
	printf("\n");

	printf("Map function pointer operation\n");
	map_put_func(MapF, "Marco", &f);
	map_get_func(MapF, "Marco");
	printf("\n");
	
	map_destroy(Map);
	map_destroy(MapF);
	return 0;
}
