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
	//构造函数
	Student(string name, string id, double score) :
		name(name), id(id), score(score) {}
	//获取学生信息
	string getName()const { return name; }
	string getId()const { return id; }
	double getScore()const { return score; }
	//修改学生信息
	void setName(string newName) { name = newName; }
	void setScore(double newScore) { score = newScore; }
	//打印学生信息
	void display()const {
		cout << "名字:" << name << "ID:" << id << "成绩:" << score << endl;
	}
};
class StudentManager {
private:
	vector< Student>students;
public:
	//添加学生
	void addStudent(const Student& student) {
		students.push_back(student);
	}
	// 删除学生（根据学号）
	void deleteStudent(const string& id) {
		students.erase(
			remove_if(students.begin(), students.end(),
				[&id](const Student& s) {return s.getId() == id; }),
			students.end());
			}
	//查找学生
	Student* findStudent(const string& id) {
		for (auto& student : students) {
			if (student.getId() == id) {
				return &student;
			}
		}
		return nullptr;//返回空指针，未找到
	}
	//显示所有学生
	void displayAllStudents()const {
		for (const auto& student : students) {
			student.display();
		}
	}
	//修改学生c成绩（根据学号）
	void modifyStudent(const string& id, double newScore) {
		Student* student = findStudent(id);
		if (student) {
			student->setScore(newScore);
		}
		else {
			cout << "未找到该学号！" << endl;
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
	//保存学生信息到文件
	void saveToFile(const string&filename)const{
		ofstream outFile(filename);
		if (!outFile) {
			cerr << "无法打开文件" << filename << endl;
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
	//从文件加载学生信息
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