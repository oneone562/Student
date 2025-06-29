#pragma once
#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>

class Contact {
public:
	//Ĭ�Ϲ��캯���������յ���ϵ�ˣ�
	Contact();
	//�������Ĺ��캯������ʼ��������Ϣ��
	Contact(const std::string& name, const std::string& phone,
		const std::string& email = "",const std::string& address = "");
	
	//��ȡ��Ϣ������Ϊconst����ʾ���޸Ķ���״̬
	std::string getName()const;
	std::string getPhone()const;
	std::string getEmail()const;
	std::string getAddress()const;

	//������Ϣ��ʹ��const ���ô��α��⿽��
	void setName(const std::string& name);
	void setPhone(const std::string& phone);
	void setEmail(const std::string& email);
	void setAddress(const std::string& address);

	//��ʾ��ϵ�ˣ���ѡ������Ժ������
	void display() const;



private:
	std::string name_;
	std::string phone_;
	std::string email_;
	std::string address_;
 };
#endif // !CONTACT_H