#define _CRT_SECURE_NO_WARNINGS 1
#include <algorithm>
#include <cctype>
#include "ContactManager.h"

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