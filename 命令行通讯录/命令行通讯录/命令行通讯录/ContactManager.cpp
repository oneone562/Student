#define _CRT_SECURE_NO_WARNINGS 1
#include <algorithm>
#include <cctype>
#include "ContactManager.h"
#include <fstream>
#include <sstream>

using namespace std;

std::vector<Contact>::iterator ContactManager::findContactByName(const std::
	string& name) {
	// 使用STL的find_if算法查找匹配的联系人
	return std::find_if(contacts_.begin(), contacts_.end(), [&name](const Contact& c)
		{return c.getName() == name;
		});
}


std::vector<Contact>::const_iterator ContactManager::findContactByName(const std::
	string& name)const {
	return std::find_if(contacts_.begin(), contacts_.end(), [&name](const Contact& c)
		{return c.getName() == name;
		});

}



//添加联系人
void ContactManager::addContact(const Contact& contact) {
	auto it = findContactByName(contact.getName());
	if (it != contacts_.end()) {
		cout << "联系人名字" << contact.getName() << "已经存在" << endl;
		return;
	}
	contacts_.push_back(contact);
	cout << "联系人添加成功" << endl;
}
//删除联系人
bool ContactManager::deleteContact(const std::string& name) {
	auto it = findContactByName(name);
	if (it == contacts_.end()) {
		cout << "未找到联系人" << endl;
		return false;
	}
	contacts_.erase(it);
	cout << "联系人删除成功！"<<endl;
	return true;
}

//显示所有联系人
void ContactManager:: displayAllContact()const {
	if (contacts_.empty()) {
		cout << "，没有联系人可以显示" << endl;
		return;
	}
	cout << "\n---所有联系人（" << contacts_.size() << ")---" << endl;
	for (const auto& contact : contacts_) {
		contact.display();
	}
	cout << "----------------" << endl;

}
//保存到文件
void ContactManager::saveToFile(const std::string& filename)const {
	ofstream outFile(filename);
	if (!outFile) {
		throw std::runtime_error("无法打开文件：" + filename);
	}
	for (const auto& contact : contacts_) {
		outFile << contact.getName() << ","
			<< contact.getPhone() << ","
			<< contact.getEmail() << ","
			<< contact.getAddress() << "\n";

	}
	outFile.close();
	cout << "联系人保存到文件" << filename <<endl;

}
//从文件加载

void ContactManager::loadFromFile(const std::string& filename) {
	ifstream inFile(filename);
	if (!inFile) {
		throw std::runtime_error("无法打开文件:" + filename);
	}
	contacts_.clear();

	std::string line;
	while (getline(inFile, line)) {
		if (line.empty())continue;

		std::istringstream ss(line);
		std::string name, phone, email, address;
		if (!getline(ss, name, ','))continue;
		if (!getline(ss, phone, ','))continue;
		if (!getline(ss, email, ','))continue;
		getline(ss, address);
		contacts_.emplace_back(name, phone, email, address);

	}
	inFile.close();
	cout << "从文件加载的联系人：" << filename << "(" << contacts_.size() << "联系人）"
		<<endl;


}