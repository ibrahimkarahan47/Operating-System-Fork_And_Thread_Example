#ifndef QUEEE_H
#define QUEEE_H

#include<iostream>
#include <string>
#include "patient.h"

struct quee{
	node *front, *back;
	void create();
	bool is_empty();
	void enque(node *newptr);
	node* deque();
	const node* top();
	void yaz();
	int time;
	void treat();
};
#endif