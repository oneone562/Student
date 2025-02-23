#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <fstream>



class Student {
private:
	string name;
	string id;
	double score;

public:
	//���캯��
	Student(string name, string id, double score) :
		name(name), id(id), score(score) {}
	//��ȡѧ����Ϣ
	string getName()const { return name; }
	string getId()const { return id; }
	double getScore()const { return score; }
	//�޸�ѧ����Ϣ
	void setName(string newName) { name = newName; }
	void setScore(double newScore) { score = newScore; }
	//��ӡѧ����Ϣ
	void display()const {
		cout << "����:" << name << "ID:" << id << "�ɼ�:" << score << endl;
	}
};
class StudentManager {
private:
	vector< Student>students;
public:
	//���ѧ��
	void addStudent(const Student& student) {
		students.push_back(student);
	}
	// ɾ��ѧ��������ѧ�ţ�
	void deleteStudent(const string& id) {
		students.erase(
			remove_if(students.begin(), students.end(),
				[&id](const Student& s) {return s.getId() == id; }),
			students.end());
			}
	//����ѧ��
	Student* findStudent(const string& id) {
		for (auto& student : students) {
			if (student.getId() == id) {
				return &student;
			}
		}
		return nullptr;//���ؿ�ָ�룬δ�ҵ�
	}
	//��ʾ����ѧ��
	void displayAllStudents()const {
		for (const auto& student : students) {
			student.display();
		}
	}
	//�޸�ѧ��c�ɼ�������ѧ�ţ�
	void modifyStudent(const string& id, double newScore) {
		Student* student = findStudent(id);
		if (student) {
			student->setScore(newScore);
		}
		else {
			cout << "δ�ҵ���ѧ�ţ�" << endl;
		}
	}
	void sortByscore() {
		sort(students.begin(), students.end(),
			[](const Student& a, const Student& b) {
				return a.getScore() < b.getScore();
			});
	}
	void sortByname() {
		sort(students.begin(), students.end(),
			[](const Student& a, const Student& b) {
				return a.getName() < b.getName();
			});
	}
	//����ѧ����Ϣ���ļ�
	void saveToFile(const string&filename)const{
		ofstream outFile(filename);
		if (!outFile) {
			cerr << "�޷����ļ�" << filename << endl;
			return;
		}
		for (const auto& student : students) {
			outFile << student.getName() << " " 
					<< student.getId()<< " " 
					<< student.getScore() << endl;
		}
		outFile.close();
		cout << "Student data saved to" << filename << endl;
	}
	//���ļ�����ѧ����Ϣ
	void loadFromFile(string& filename) {
		ifstream inFile(filename);
		if (!inFile) {
			cerr<< "Failed to open file for reading!\n";
			return;
		}
		students.clear();
		string name, id;
		double score;
		while (inFile >> name >> id >> score) {
			students.push_back(Student(name, id, score));
		}
		inFile.close();
		cout << "Student data loaded from" << filename << "!\n";
	}
};