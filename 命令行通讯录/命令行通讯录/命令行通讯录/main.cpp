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
    cout << "\n===== ��ϵ�˹����� =====\n"; 
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
string getNoEmptyInput(const string& prompt){}

int main() {
	


	return 0;
}