#include<iostream>
#include<fstream>
#include<string>
#include"quee.h"
#include "doctor.h"
using namespace std;


int main(){
	doctor d;
	d.getPatientsFromFile();
	d.treat();

	getchar();
}
