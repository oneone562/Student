#pragma once
#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H
#include <vector>
#include <string>
#include "Contact.h"

class ContactManager {

public:
	//Ĭ�Ϲ��캯������������
	ContactManager() = default;
	~ContactManager() = default;
	//��Ӷ�����ɾ��
	void addContact(const Contact& contact);
	bool deleteContact(const std::string& name);
	//��ӡ���ж���
	void displayAllContact()const;
	//ͨ���ؼ����ҵ�������Ķ���
	std::vector<Contact> findContacts(const std::string& keyword)const;
	//�ļ����� ��д
	void saveToFile(const std::string& filename)const;
	void loadFromFile(const std::string& filename);

	bool isEmpty()const { return contacts_.empty(); }
	size_t count()const { return contacts_.size(); }

	
private:
	//�洢��ϵ�˵�����
	std::vector<Contact> contacts_;
	// ����������ͨ������������ϵ�ˣ����ص�������
	std::vector<Contact>::iterator findContactByName(const std::string& name);
	std::vector<Contact>::const_iterator findContactByName(const std::string& name)
		const;


};











#endif