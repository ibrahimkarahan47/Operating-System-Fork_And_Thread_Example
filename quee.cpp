#include"quee.h"
using namespace std;

void quee::create(){
	front = NULL;
	back = NULL;
	time = 0;
}
bool quee::is_empty(){
	if (front != NULL && back != NULL){
		return false;
	}
	else
		return true;
}
const node* quee::top()
{
	return front;
}
void quee::enque(node *newptr){
	node *temp;
	temp = new node;
	temp->code = newptr->code;
	temp->arrivingTime = newptr->arrivingTime;
	temp->treatmentTime = newptr->treatmentTime;
	temp->name = newptr->name;
	temp->next = NULL;

	if (is_empty()) { // first element
		back = temp; 
		front = back;
	}
	else {
		back->next = temp;
		back = temp;
	}

}
node* quee::deque(){
	node *traverse;
	traverse = front;
	front = front->next;
	if (front == NULL)
		back = NULL;
	return traverse;
}

void quee::yaz(){
	node *traverse;
	traverse = front;
	while (traverse!=NULL){
		cout<<traverse->arrivingTime<<"      "<<traverse->treatmentTime<< " " << traverse->code <<" "<<traverse->name<< endl;
		traverse = traverse->next;
	}

}

void quee::treat(){
	time++;
}

