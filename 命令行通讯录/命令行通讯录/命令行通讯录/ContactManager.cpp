#define _CRT_SECURE_NO_WARNINGS 1
#include <algorithm>
#include <cctype>
#include "ContactManager.h"
#include <fstream>
#include <sstream>

using namespace std;

std::vector<Contact>::iterator ContactManager::findContactByName(const std::
	string& name) {
	// ʹ��STL��find_if�㷨����ƥ�����ϵ��
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



//�����ϵ��
void ContactManager::addContact(const Contact& contact) {
	auto it = findContactByName(contact.getName());
	if (it != contacts_.end()) {
		cout << "��ϵ������" << contact.getName() << "�Ѿ�����" << endl;
		return;
	}
	contacts_.push_back(contact);
	cout << "��ϵ����ӳɹ�" << endl;
}
//ɾ����ϵ��
bool ContactManager::deleteContact(const std::string& name) {
	auto it = findContactByName(name);
	if (it == contacts_.end()) {
		cout << "δ�ҵ���ϵ��" << endl;
		return false;
	}
	contacts_.erase(it);
	cout << "��ϵ��ɾ���ɹ���"<<endl;
	return true;
}

//��ʾ������ϵ��
void ContactManager:: displayAllContact()const {
	if (contacts_.empty()) {
		cout << "��û����ϵ�˿�����ʾ" << endl;
		return;
	}
	cout << "\n---������ϵ�ˣ�" << contacts_.size() << ")---" << endl;
	for (const auto& contact : contacts_) {
		contact.display();
	}
	cout << "----------------" << endl;

}
//���浽�ļ�
void ContactManager::saveToFile(const std::string& filename)const {
	ofstream outFile(filename);
	if (!outFile) {
		throw std::runtime_error("�޷����ļ���" + filename);
	}
	for (const auto& contact : contacts_) {
		outFile << contact.getName() << ","
			<< contact.getPhone() << ","
			<< contact.getEmail() << ","
			<< contact.getAddress() << "\n";

	}
	outFile.close();
	cout << "��ϵ�˱��浽�ļ�" << filename <<endl;

}
//���ļ�����

void ContactManager::loadFromFile(const std::string& filename) {
	ifstream inFile(filename);
	if (!inFile) {
		throw std::runtime_error("�޷����ļ�:" + filename);
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
	cout << "���ļ����ص���ϵ�ˣ�" << filename << "(" << contacts_.size() << "��ϵ�ˣ�"
		<<endl;


}