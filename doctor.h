#ifndef DOCTOR_H
#define DOCTOR_H
#include<iostream>
#include <string>
#include<fstream>
#include <cstring>
#include "quee.h"

#define RED_STANDART_TREATMENT_DURATION 1
#define YELLOW_STANDART_TREATMENT_DURATION 2
#define GREEN_STANDART_TREATMENT_DURATION 3

using namespace std;

struct doctor{
	quee redQuee;
	quee yellowQuee;
	quee greenQuee;
	void treat();
	void getPatientsFromFile();
};


#endif
