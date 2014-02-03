/**
 * Making Cpp wrapper
 * Functions will be called by a C program
 * 
 * @author:      Marco "soniyj" Matascioli
 * @date:        September 2013
 * @file:        map.cpp
 * 
 * Copyright (C) 2013. Marco "soniyj" Matascioli
 * This code is released under the term of the GPL v2.
 */

#include <iostream>
#include <map>

/* Generic Map */
typedef std::map<int, char*> Map;

/* Mapping name with a function pointer */
typedef void (*func_t)();
typedef std::map<std::string, func_t> MapStrFunc;
typedef std::map<char *, func_t> MapCharFunc;


/* C wrapper compiler */
extern "C" {
	void* map_create() {
		return reinterpret_cast<void*> (new Map);
	}

	void* map_create_func() {
		return reinterpret_cast<void*> (new MapCharFunc);
	}

	void map_put(void* map, int k, char* v) {
		Map* m = reinterpret_cast<Map*> (map);
		m->insert(std::pair<int, char*>(k, v));
	}

	void map_get(void* map, int k) {
		Map* m = reinterpret_cast<Map*> (map);
		std::cout << "Key: " << k << " Value: " << m->find(k)->second <<'\n';
	}

	void map_put_func(void* map, char* k, func_t v) {
		MapCharFunc* m = reinterpret_cast<MapCharFunc*> (map);
		m->insert(std::pair<char*, func_t>(k, v));
	}
	
	void map_get_func(void* map, char* k) {
		MapCharFunc* m = reinterpret_cast<MapCharFunc*> (map);
		std::cout << "Func: " << m->find(k)->second << '\n';
		(*m->find(k)->second)(); //Run the function
	}

	void map_get_all(void* map) {
		Map* m = reinterpret_cast<Map*> (map);
		std::map<int, char*>::iterator it = m->begin();
		for(it=m->begin(); it!=m->end(); ++it) {
			std::cout << "Key: " << it->first << " => Value: " << it->second << std::endl;
		}
	}

	void map_destroy(void* map) {
		Map* m = reinterpret_cast<Map*> (map);
		std::cout << "Object Destroyed\n";
		delete m;
	}
} /* extern "C" */
