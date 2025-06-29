#pragma once
#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>

class Contact {
public:
	//默认构造函数（创建空的联系人）
	Contact();
	//带参数的构造函数（初始化所有信息）
	Contact(const std::string& name, const std::string& phone,
		const std::string& email = "",const std::string& address = "");
	
	//获取信息，声明为const，表示不修改对象状态
	std::string getName()const;
	std::string getPhone()const;
	std::string getEmail()const;
	std::string getAddress()const;

	//设置信息，使用const 引用传参避免拷贝
	void setName(const std::string& name);
	void setPhone(const std::string& phone);
	void setEmail(const std::string& email);
	void setAddress(const std::string& address);

	//显示联系人（可选方便调试和输出）
	void display() const;



private:
	std::string name_;
	std::string phone_;
	std::string email_;
	std::string address_;
 };
#endif // !CONTACT_H