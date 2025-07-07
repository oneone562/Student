#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <limits>
#include <cctype>
#include "ContactManager.h"
using namespace std;
    //清除输入缓冲区
void clearInputBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMainMenu() {
    cout << "\n===== 通讯录管理器 =====\n"; 
    cout << "1. 添加Add Contact\n";                
    cout << "2. 删除Delete Contact\n";             
    cout << "3. 显示所有Display All Contacts\n";       
    cout << "4. 搜索Search Contacts\n";            
    cout << "5. 保存到文件Save Contacts to File\n";      
    cout << "6. 从文件加载Load Contacts from File\n";    
    cout << "0. Exit\n";                       
    cout << "===========================\n";   
    cout << "选择Enter your choice: ";             
}

//获取非空输入
string getNoEmptyInput(const string& prompt){
    string input;
    while (true) {
        cout <<prompt;
        getline(cin, input);
        // 移除输入字符串首尾的空白字符（空格、制表符、换行符、回车符）
        size_t start = input.find_first_not_of(" \t\n\r");
        size_t end = input.find_last_not_of(" \t\n\r");
        if (start != string::npos && end != string::npos) {
            input = input.substr(start, end - start + 1);
        }
        if (!input.empty()) {
            return input;
        }
        cout << "输入不能为空，请再输入！\n";

    }

}
//添加联系人
void addContactUI(ContactManager& manager) {
    cout << "\n---添加新的联系人---\n";
    // 获取必填信息（姓名和电话）
    string name = getNoEmptyInput("名字");
    string phone = getNoEmptyInput("电话");
    string email, address;
    cout << "email(可选)";
    getline(cin, email);
    cout << "address(可选)";
    getline(cin, address);
    Contact newContact(name, phone, email, address);
    manager.addContact(newContact);
}
//删除联系人
void deleteContactUI(ContactManager& manager) {
    //检查联系人列表是否为空
    if (manager.isEmpty()) {
        cout << "通讯录为空，没有可删除的联系人\n";
        return;
    }
    cout << "删除联系人\n";
    string name = getNoEmptyInput("输入要删除的名字");
    manager.deleteContact(name);
}//搜索联系人
void searchContactsUI(ContactManager& manager) {
    if (manager.isEmpty()) {
        cout << "通讯录为空，无法搜索\n";
        return;
    }
    cout << "搜索联系人\n";
    string keyword;
    cout << "输入搜索信息（也可以为空显示通讯列表)";
    getline(cin, keyword);//获取关键字，也可为空
    //执行搜索
    auto results = manager.findContacts(keyword);
    //显示搜索结果
    if (results.empty()) {
        cout << "未找到匹配的联系人" << keyword << "\n";
    }
    else {
        cout << "找到" << results.size() << "匹配的联系人\n";
        for (const auto& contact : results) {
            contact.display();
        }
    }

}
//保存到文件
void saveFileUI(ContactManager& manager) {
    cout << "保存联系人\n";
    string filename = getNoEmptyInput("text1");
    try {
        manager.saveToFile(filename);
    }
    catch (const exception& e) {
        cerr << "Error:" << e.what() << endl;
    }
}
//从文件加载
void loadFromFileUI(ContactManager& manager) {
    cout << "加载联系人\n";
    string filename = getNoEmptyInput("text1");
    try {
        manager.saveToFile(filename);
    }
    catch (const exception& e) {
        cerr << "Error:" << e.what() << endl;
    }
}

int main() {
    ContactManager manager; //创建联系人存储管理器对象
    int choice;
    cout << "Welcome to Contact Manager!\n";
    cout << "=============================\n";
         
        //主循环-程序一直运行直到用户选择退出
    do {
        displayMainMenu();
        if (!(cin >> choice)) {
            cout << "无效输入，请输入数字.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        try {
            switch (choice) {
            case 1:
                addContactUI(manager);
                break;
            case 2:deleteContactUI(manager);
                break;
            case 3:manager.displayAllContact();
                break;
            case 4:searchContactsUI(manager);
                break;
            case 5:saveFileUI(manager);
                break;
            case 6:loadFromFileUI(manager);
                break;
            case 0:
                cout << "退出程序。\n";
                break;
            default:
                cout << "无效输入，请输入介于0-6以下数字\n";

            }
        }
        catch (const exception& e) {
            cerr << "Error:" << e.what() << endl;
        }

    } while (choice != 0);
	


	return 0;
}