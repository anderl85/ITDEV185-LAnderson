/*
* Liberty Anderson
* ITDEV 185 900
* Assignment 2
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string studentLeader = "",	
		   studentEnd = "",		
		   studentTemp,
		   lineSeperator;
	int noStudents;

	cout << "Enter the number of students... ";
	cin >> noStudents;
	cin.ignore();	//buffer

	//validation
	while (noStudents < 1 || noStudents > 20) {
		cout << "That's not a valid number of students!\n"
				"Enter the number of students... ";
		cin >> noStudents;
	}

	//loop input, compare input with values
	for (int i = 0; i < noStudents; i++) {
		//prompt spec first name
		cout << "Enter the student name... ";
		getline(cin, studentTemp);

		if (studentLeader == "") {	//first input
			studentLeader = studentTemp;
		}
		else if (studentEnd == "") { //second input

			if (studentTemp.compare(studentLeader) < 0) {	
				//student end not populated but newest name is before current student leader
				studentEnd = studentLeader;
				studentLeader = studentTemp;
			}
			else {
				//student end not populated and new input is after current student leader
				studentEnd = studentTemp;
			}
		}
		else if (studentTemp.compare(studentLeader) < 0) {	
			//input value is before current student leader
			studentLeader = studentTemp;
		}
		else if (studentTemp.compare(studentEnd) > 0) {
			//input value is after current student end
			studentEnd = studentTemp;
		}
		
	}
	
	//report
	lineSeperator.assign(25, '-');
	cout << lineSeperator << endl;
	cout << studentLeader << " should be at the head of the line, and ";
	if (studentEnd == "") {
		//only one student
		cout << "will be lonely there." << endl;
	}
	else {
		cout << studentEnd << " should be at the end of the line." << endl;
	}
	
	return 0;
}