/*
* Liberty Anderson
* ITDEV 185 900
* Assignment 2 Extra Credit
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string studentLeader = "",
		studentEnd = "",
		studentTemp,
		lineSeperator;
	ifstream studentFile;

	studentFile.open("students.txt");

	//loop file, compare input with values
	while (studentFile >> studentTemp) {

		if (studentLeader == "") {	//first line
			studentLeader = studentTemp;
		}
		else if (studentEnd == "") { //second line

			if (studentTemp.compare(studentLeader) < 0) {
				//student end not populated but newest name is before current student leader
				studentEnd = studentLeader;
				studentLeader = studentTemp;
			}
			else {
				//student end not populated and new name is after current student leader
				studentEnd = studentTemp;
			}
		}
		else if (studentTemp.compare(studentLeader) < 0) {
			//new value is before current student leader
			studentLeader = studentTemp;
		}
		else if (studentTemp.compare(studentEnd) > 0) {
			//new value is after current student end
			studentEnd = studentTemp;
		}

	}

	//report
	lineSeperator.assign(25, '-');
	cout << lineSeperator << endl;
	cout << "According to the roster on file, ";
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