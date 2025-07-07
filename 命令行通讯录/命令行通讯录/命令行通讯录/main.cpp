#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <limits>
#include <cctype>
#include "ContactManager.h"
using namespace std;
    //������뻺����
void clearInputBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMainMenu() {
    cout << "\n===== ͨѶ¼������ =====\n"; 
    cout << "1. ���Add Contact\n";                
    cout << "2. ɾ��Delete Contact\n";             
    cout << "3. ��ʾ����Display All Contacts\n";       
    cout << "4. ����Search Contacts\n";            
    cout << "5. ���浽�ļ�Save Contacts to File\n";      
    cout << "6. ���ļ�����Load Contacts from File\n";    
    cout << "0. Exit\n";                       
    cout << "===========================\n";   
    cout << "ѡ��Enter your choice: ";             
}

//��ȡ�ǿ�����
string getNoEmptyInput(const string& prompt){
    string input;
    while (true) {
        cout <<prompt;
        getline(cin, input);
        // �Ƴ������ַ�����β�Ŀհ��ַ����ո��Ʊ�������з����س�����
        size_t start = input.find_first_not_of(" \t\n\r");
        size_t end = input.find_last_not_of(" \t\n\r");
        if (start != string::npos && end != string::npos) {
            input = input.substr(start, end - start + 1);
        }
        if (!input.empty()) {
            return input;
        }
        cout << "���벻��Ϊ�գ��������룡\n";

    }

}
//�����ϵ��
void addContactUI(ContactManager& manager) {
    cout << "\n---����µ���ϵ��---\n";
    // ��ȡ������Ϣ�������͵绰��
    string name = getNoEmptyInput("����");
    string phone = getNoEmptyInput("�绰");
    string email, address;
    cout << "email(��ѡ)";
    getline(cin, email);
    cout << "address(��ѡ)";
    getline(cin, address);
    Contact newContact(name, phone, email, address);
    manager.addContact(newContact);
}
//ɾ����ϵ��
void deleteContactUI(ContactManager& manager) {
    //�����ϵ���б��Ƿ�Ϊ��
    if (manager.isEmpty()) {
        cout << "ͨѶ¼Ϊ�գ�û�п�ɾ������ϵ��\n";
        return;
    }
    cout << "ɾ����ϵ��\n";
    string name = getNoEmptyInput("����Ҫɾ��������");
    manager.deleteContact(name);
}//������ϵ��
void searchContactsUI(ContactManager& manager) {
    if (manager.isEmpty()) {
        cout << "ͨѶ¼Ϊ�գ��޷�����\n";
        return;
    }
    cout << "������ϵ��\n";
    string keyword;
    cout << "����������Ϣ��Ҳ����Ϊ����ʾͨѶ�б�)";
    getline(cin, keyword);//��ȡ�ؼ��֣�Ҳ��Ϊ��
    //ִ������
    auto results = manager.findContacts(keyword);
    //��ʾ�������
    if (results.empty()) {
        cout << "δ�ҵ�ƥ�����ϵ��" << keyword << "\n";
    }
    else {
        cout << "�ҵ�" << results.size() << "ƥ�����ϵ��\n";
        for (const auto& contact : results) {
            contact.display();
        }
    }

}
//���浽�ļ�
void saveFileUI(ContactManager& manager) {
    cout << "������ϵ��\n";
    string filename = getNoEmptyInput("text1");
    try {
        manager.saveToFile(filename);
    }
    catch (const exception& e) {
        cerr << "Error:" << e.what() << endl;
    }
}
//���ļ�����
void loadFromFileUI(ContactManager& manager) {
    cout << "������ϵ��\n";
    string filename = getNoEmptyInput("text1");
    try {
        manager.saveToFile(filename);
    }
    catch (const exception& e) {
        cerr << "Error:" << e.what() << endl;
    }
}

int main() {
    ContactManager manager; //������ϵ�˴洢����������
    int choice;
    cout << "Welcome to Contact Manager!\n";
    cout << "=============================\n";
         
        //��ѭ��-����һֱ����ֱ���û�ѡ���˳�
    do {
        displayMainMenu();
        if (!(cin >> choice)) {
            cout << "��Ч���룬����������.\n";
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
                cout << "�˳�����\n";
                break;
            default:
                cout << "��Ч���룬���������0-6��������\n";

            }
        }
        catch (const exception& e) {
            cerr << "Error:" << e.what() << endl;
        }

    } while (choice != 0);
	


	return 0;
}