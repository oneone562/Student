#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"

int main() {
	//����Ĭ�Ϲ��캯��
	//Contact text;
	//std::cout << "text:" << std::endl;
    //text.display();

	//���Դ������Ĺ��캯��
	Contact jojo("jojo", "111-222-333", "jojo123.com", "china");
	std::cout << "jojo����Ϣ" << std::endl;
	jojo.display();


	//���Դ������Ĺ��캯�� (ֻ�ṩ������Ϣ - ����Ĭ�ϲ���)
	Contact yoyo("yoyo", "11-33-55");
	std::cout << "yoyo����Ϣ" << std::endl;
	yoyo.display();

	//���Բ���Setter����
	jojo.setPhone("13922116535");
	jojo.setEmail("jojo.com");
	std::cout << "jojo�޸ĺ����Ϣ" << std::endl;
	jojo.display();

	// 5. ����Getter����
	std::cout << "jojo������" << jojo.getName() << std::endl;
	std::cout << "yoyo�ĵ绰" << yoyo.getPhone() << std::endl;


	return 0;
}