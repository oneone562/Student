#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"



//默认构造函数实现   成员初始化列表
Contact::Contact():name_(""),phone_(""),email_(""),address_(""){}

//带参数的额构造函数实现
Contact::Contact(const std::string& name,const std::string& phone,
				  const std::string& email,const std::string& address):
	name_(name),phone_(phone),email_(email),address_(address){}

//getter 方法实现
std::string Contact::getName()const { return name_; }//返回副本
std::string Contact::getPhone()const { return phone_; }//返回副本
std::string Contact::getEmail()const { return email_; }//返回副本
std::string Contact::getAddress()const { return address_; }//返回副本

//settr方法实现 将参数赋值给成员变量
void Contact::setName(const std::string& name) { name_ = name; }
void Contact::setPhone(const std::string& phone) { phone_ = phone; }
void Contact::setEmail(const std::string& email) { email_ = email; }
void Contact::setAddress(const std::string& address) { address_ = address; }

//display()方法实现
void Contact::display()const {
	std::cout << "name:" << name_ << std::endl;
	std::cout << "phone:" << phone_ << std::endl;
	if (!email_.empty()) { std::cout << "email:" << email_ << std::endl; }
	if (!address_.empty()) { std::cout << "address:" << address_ << std::endl; }
	std::cout << "----------------------------" << std::endl;
}




