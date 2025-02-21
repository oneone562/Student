#pragma once
#include <iostream>
using namespace std;
#include <vector>



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
		cout << "名字" << name << "ID" << id << "成绩" << score << endl;
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

};