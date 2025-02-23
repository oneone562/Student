#define _CRT_SECURE_NO_WARNINGS 1
#include "student.h"


int main()
{
	StudentManager manager;
	int choice=1;
	string name, id;
	double score;
	
	while (true) {
		cout << "\n1. Add Student\n2. Delete Student"
				"\n3. Find Student\n4. Display All Students"
				"\n5. Modify Student\n6.sort by scort\n7.sort by name\n0. Exit";
		cout << "ÊäÈëÄãµÄÑ¡Ôñ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter name, id, and score: ";
			cin >> name >> id >> score;
			manager.addStudent(Student(name, id, score));
			break;
		case 2:
			cout << "Enter student id to delete:";
			cin >> id;
			manager.deleteStudent(id);
			break;
		case 3:
			cout << "Enter student id to find:";
			cin >> id;
			if (Student* student = manager.findStudent(id)) {
				student->display();
			}
			else 
				cout << "student not found" << endl;
			break;
		case 4:
			manager.displayAllStudents();
			break;
		case 5:
			cout << "Enter student id and new score:";
			cin >> id >> score;
			manager.modifyStudent(id, score);
			break;
		case 6:
			manager.sortByscore();
			cout << "sort by score\n";
			manager.displayAllStudents();
			break;
		case 7:
			manager.sortByname();
			cout << "sort by name\n";
			manager.displayAllStudents();
			break;
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
	
	return 0;
}
