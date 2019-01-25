#include "doctor.h"

void doctor::getPatientsFromFile()
{
	redQuee.create();
	yellowQuee.create();
	greenQuee.create();
	ifstream input;
	string line;
	string name, complaint;
	int arriving_time, treatment_time;
	input.open("patientsInfo.txt");
	if (input.is_open()){
		getline(input, line);
		while (!input.eof())
		{
			input >> name >> arriving_time >> treatment_time >> complaint;
			node temp;
			temp.name = name;
			temp.arrivingTime = arriving_time;
			temp.treatmentTime = treatment_time;
			temp.code = complaint;
			
			if (strcmp(temp.code.c_str(), "RED") == 0)
				redQuee.enque(&temp);
			else if (strcmp(temp.code.c_str(), "YELLOW") == 0)
				yellowQuee.enque(&temp);
			else
				greenQuee.enque(&temp);
		}
	}
}
void doctor::treat()
{
	int current_time = 1;
	const node *redTop;
	const node *yellowTop;
	const node *greenTop;
	const node *priorityPatient;
	node *activePatient;

	int treatTimeDuration = 0;

	while (!redQuee.is_empty() || !yellowQuee.is_empty() || !greenQuee.is_empty())
	{
		redTop = redQuee.top();
		yellowTop = yellowQuee.top();
		greenTop = greenQuee.top();

		if (redTop == NULL && yellowTop == NULL)
			priorityPatient = greenTop;
		else if (redTop == NULL)
			priorityPatient = yellowTop;
		else
			priorityPatient = redTop;


		if (yellowTop != NULL && priorityPatient->arrivingTime > yellowTop->arrivingTime)
			priorityPatient = yellowTop;
		if (greenTop != NULL && priorityPatient->arrivingTime > greenTop->arrivingTime)
			priorityPatient = greenTop;

		if (strcmp(priorityPatient->code.c_str(), "RED") == 0)
		{
			treatTimeDuration = RED_STANDART_TREATMENT_DURATION;
			activePatient = redQuee.deque();
		}
		else if (strcmp(priorityPatient->code.c_str(), "YELLOW") == 0)
		{
			if (priorityPatient->treatmentTime < YELLOW_STANDART_TREATMENT_DURATION )
				treatTimeDuration = priorityPatient->treatmentTime;
			else
				treatTimeDuration = YELLOW_STANDART_TREATMENT_DURATION;

			activePatient = yellowQuee.deque();

		}
		else if (strcmp(priorityPatient->code.c_str(), "GREEN") == 0)
		{
			if (priorityPatient->treatmentTime < GREEN_STANDART_TREATMENT_DURATION)
				treatTimeDuration = priorityPatient->treatmentTime;
			else
				treatTimeDuration = GREEN_STANDART_TREATMENT_DURATION;

			activePatient = greenQuee.deque();
		}

		while (treatTimeDuration)
		{
			cout << current_time << ". time slice " << activePatient->name << endl;

			if (activePatient->treatmentTime > 0)
				activePatient->treatmentTime -= 1; //1 time slot tedavi uygula
			
			treatTimeDuration--;
			current_time++;
		}

		if (strcmp(activePatient->code.c_str(), "RED") == 0)
		{
			if (activePatient->treatmentTime > 0)
			{
				activePatient->code = "YELLOW";
				yellowQuee.enque(activePatient);
			}
		}
		else if (strcmp(activePatient->code.c_str(), "YELLOW") == 0)
		{
			if (activePatient->treatmentTime > 0)
			{
				activePatient->code = "GREEN";
				greenQuee.enque(activePatient);
			}
		}
		else if (strcmp(activePatient->code.c_str(), "GREEN") == 0)
		{
			if (activePatient->treatmentTime > 0)
				greenQuee.enque(activePatient);
		}
	}
}