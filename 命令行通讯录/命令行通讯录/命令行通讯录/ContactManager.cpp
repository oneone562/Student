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

std::vector<Contact> ContactManager::findContacts(const std::string& keyword)
const {
	//创建结果容器
	std::vector<Contact> results;

	//如果关键字为空，返回所有联系人
	if (keyword.empty()) {
		results = contacts_;
	}

	//准备不区分大小写的关键字
	std::string lowerKeyword = keyword;

	//将关键字转换为小写，用于不区分大小写搜索
	std::transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(),
		[](unsigned char c) {return std::tolower(c); });


	//使用STL算法筛选匹配的联系人
	std::copy_if(contacts_.begin(), contacts_.end(), std::back_inserter(results),
		//Lambda表达式定义匹配条件
		//检查名字
		[&](const Contact& c) {
			std::string name = c.getName();
			//将名字转换为小写
			std::transform(name.begin(), name.end(), name.begin(),
				[](unsigned char c) {return std::tolower(c); });
			//在小写名字中搜索关键字
			if (name.find(lowerKeyword) != std::string::npos) { return true; }
			//检查电话，电话通常为数字不区分大小写，直接使用原始关键字
			std::string phone = c.getPhone();
			if (phone.find(keyword) != std::string::npos) { return true; }
			//检查邮箱
			std::string email = c.getEmail();
			//将邮箱转换为小写
			std::transform(email.begin(), email.end(), email.begin(),
				[](unsigned char c) {return std::tolower(c); });
			//在小写邮箱里搜索小写关键字
			if (email.find(lowerKeyword) != std::string::npos) { return true; }

			//如果以上都不匹配，返回false
			return false;
		});
	return results;
}