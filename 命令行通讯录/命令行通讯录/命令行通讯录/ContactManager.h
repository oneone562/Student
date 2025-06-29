#pragma once
#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H
#include <vector>
#include <string>
#include "Contact.h"

class ContactManager {

public:
	//默认构造函数和析构函数
	ContactManager() = default;
	~ContactManager() = default;
	//添加对象与删除
	void addContact(const Contact& contact);
	bool deleteContact(const std::string& name);
	//打印所有对象
	void displayAllContact()const;
	//通过关键字找到容器里的对象
	std::vector<Contact> findContacts(const std::string& keyword)const;
	//文件操作 读写
	void saveToFile(const std::string& filename)const;
	void loadFromFile(const std::string& filename);

	bool isEmpty()const { return contacts_.empty(); }
	size_t count()const { return contacts_.size(); }

	
private:
	//存储联系人的容器
	std::vector<Contact> contacts_;
	// 辅助函数：通过姓名查找联系人（返回迭代器）
	std::vector<Contact>::iterator findContactByName(const std::string& name);
	std::vector<Contact>::const_iterator findContactByName(const std::string& name)
		const;


};











#endif