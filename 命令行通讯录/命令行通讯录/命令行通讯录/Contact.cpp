#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"



//Ĭ�Ϲ��캯��ʵ��   ��Ա��ʼ���б�
Contact::Contact():name_(""),phone_(""),email_(""),address_(""){}

//�������Ķ�캯��ʵ��
Contact::Contact(const std::string& name,const std::string& phone,
				  const std::string& email,const std::string& address):
	name_(name),phone_(phone),email_(email),address_(address){}

//getter ����ʵ��
std::string Contact::getName()const { return name_; }//���ظ���
std::string Contact::getPhone()const { return phone_; }//���ظ���
std::string Contact::getEmail()const { return email_; }//���ظ���
std::string Contact::getAddress()const { return address_; }//���ظ���

//settr����ʵ�� ��������ֵ����Ա����
void Contact::setName(const std::string& name) { name_ = name; }
void Contact::setPhone(const std::string& phone) { phone_ = phone; }
void Contact::setEmail(const std::string& email) { email_ = email; }
void Contact::setAddress(const std::string& address) { address_ = address; }

//display()����ʵ��
void Contact::display()const {
	std::cout << "name:" << name_ << std::endl;
	std::cout << "phone:" << phone_ << std::endl;
	if (!email_.empty()) { std::cout << "email:" << email_ << std::endl; }
	if (!address_.empty()) { std::cout << "address:" << address_ << std::endl; }
	std::cout << "----------------------------" << std::endl;
}




