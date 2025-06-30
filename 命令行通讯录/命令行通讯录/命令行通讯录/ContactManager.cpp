#define _CRT_SECURE_NO_WARNINGS 1
#include <algorithm>
#include <cctype>
#include "ContactManager.h"

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