#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"

int main() {
	//测试默认构造函数
	//Contact text;
	//std::cout << "text:" << std::endl;
    //text.display();

	//测试带参数的构造函数
	Contact jojo("jojo", "111-222-333", "jojo123.com", "china");
	std::cout << "jojo的信息" << std::endl;
	jojo.display();


	//测试带参数的构造函数 (只提供部分信息 - 利用默认参数)
	Contact yoyo("yoyo", "11-33-55");
	std::cout << "yoyo的信息" << std::endl;
	yoyo.display();

	//测试测试Setter方法
	jojo.setPhone("13922116535");
	jojo.setEmail("jojo.com");
	std::cout << "jojo修改后的信息" << std::endl;
	jojo.display();

	// 5. 测试Getter方法
	std::cout << "jojo的名字" << jojo.getName() << std::endl;
	std::cout << "yoyo的电话" << yoyo.getPhone() << std::endl;


	return 0;
}