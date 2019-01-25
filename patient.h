#ifndef PATIENT_H
#define PATIENT_H
#include<iostream>
#include <string>

struct node{
	std::string code;
	std::string name;
	int arrivingTime;
	int treatmentTime;
	node *next;
};
#endif