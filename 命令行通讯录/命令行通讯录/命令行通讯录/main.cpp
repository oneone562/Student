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
    cout << "\n===== 联系人管理器 =====\n"; 
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
string getNoEmptyInput(const string& prompt){}

int main() {
	


	return 0;
}