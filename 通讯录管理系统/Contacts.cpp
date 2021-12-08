using namespace std;
#include <iostream>
#include<string>

#define MAX 1000


//联系人的结构体
struct user {
	string u_name;
	string u_gander;
	int u_age;
	string u_Phone;
	string u_address;
};
struct Addressbooks {
	user contacts[MAX];
	int u_Size=0;			//已存的联系人个数
	int u[MAX] = {0};
};


void show_Menu() {
	cout << endl;
	cout << "***************************"<< endl;
	cout << "*****  1、添加联系人  *****  " << endl;
	cout << "*****  2、显示联系人  *****  " << endl;
	cout << "*****  3、删除联系人  *****  " << endl;
	cout << "*****  4、修改联系人  *****  " << endl;
	cout << "*****  5、清空联系人  *****  " << endl;
	cout << "*****  6、退出联系人  *****  " << endl;
	cout << "*****  7、查询联系人  *****  " << endl;
	cout << "***************************" << endl;
}
void Add_contacts(Addressbooks * Book) {
	cout << endl << "---------------------------" << endl;
	int new_num=0;
	if (Book->u_Size > MAX) {
		cout<<"通讯录已满😅"<<endl;
	}
	else {
		for (int i = 0; i < MAX; i++) {
			if (Book->u[i] == 0) {
				Book->u[i] = 1;
				new_num = i;
				break;
			}
		}


		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;

		Book->contacts[new_num].u_name = name;

		cout << "请输入性别：" << endl;
		string gander;
		cin >> gander;
		Book->contacts[new_num].u_gander = gander;

		cout << "请输入年纪：" << endl;
		int age;
		cin >> age;
		Book->contacts[new_num].u_age = age;

		cout << "请输入地址：" << endl;
		string adress;
		cin >> adress;
		Book->contacts[new_num].u_address = adress;

		cout << "请输入电话：" << endl;
		string iphone;
		cin >> iphone;
		Book->contacts[new_num].u_Phone = iphone;

		Book->u_Size++;
		cout << "******新建联系人成功！！***" << endl << endl;

		
	}

	cout << endl << "---------------------------" << endl;
}

void Printf_contacts(const Addressbooks* Book) {

	cout << endl << "---------------------------" << endl;
	for (int i = 0; i < Book->u_Size; i++) {
		if (Book->u[i] != 0) {
			cout << "-" << Book->contacts[i].u_name << "-";
			if (i == 4) { cout << endl; }
		}
	}

	cout << endl << "---------------------------" << endl;
}

void Modify_contacts(Addressbooks* Book) {
	cout << "输入修改联系人的姓名" << endl;
	string n_name;
	cin >> n_name;
	for (int i = 0; i < Book->u_Size; i++) {
		if (Book->contacts[i].u_name == n_name) {
			
			cout << "请输入新的姓名：" << endl;
			string name;
			cin >> name;
			Book->contacts[i].u_name = name;

			cout << "请输入新的性别：" << endl;
			string gander;
			cin >> gander;
			Book->contacts[i].u_gander = gander;

			cout << "请输入新的年纪：" << endl;
			int age;
			cin >> age;
			Book->contacts[i].u_age = age;

			cout << "请输入新的地址：" << endl;
			string adress;
			cin >> adress;
			Book->contacts[i].u_address = adress;

			cout << "请输入新的电话：" << endl;
			string iphone;
			cin >> iphone;
			Book->contacts[i].u_Phone = iphone;



		}
		else {	
			cout << "没有找到这个联系人" << endl;
		}
	
	}
}

void Dele_contacts(Addressbooks* Book) {
	int i;
	cout << "请输入你要删除的联系人"<<endl;
	string n_name;
	cin >> n_name;
	for ( i = 0; i < Book->u_Size; i++) {
		if (Book->contacts[i].u_name == n_name) {
			Book->u[i] = 0;
			Book->contacts[i].u_name = "0";
			Book->contacts[i].u_gander = "0";


			Book->contacts[i].u_age = 0;

	
			Book->contacts[i].u_address = "0";

			Book->contacts[i].u_Phone = "0";


		}
	}
	if (i == Book->u_Size - 1) {
		cout<<"没有找到该联系人"<<endl;
	}
}
void Clear_contacts(Addressbooks* Book) {
	
	for (int i = 0; i < Book->u_Size; i++) {
		
			Book->contacts[i].u_name = "0";
			Book->contacts[i].u_gander = "0";
			Book->contacts[i].u_age = 0;
			Book->contacts[i].u_address = "0";
			Book->contacts[i].u_Phone = "0";
		}
		Book->u_Size = 0;
}

void Printf_one(const Addressbooks* Book) {
	int i;
	cout << "---------------------------" << endl;
	cout << "---------------------------" << endl;
	cout << "请输入要查询的联系人姓名" << endl;
	string n_name;
	cin >> n_name;
	for (i = 0; i < Book->u_Size; i++) {
		if (Book->contacts[i].u_name == n_name) {
			
			cout << "性别:" << Book->contacts[i].u_gander << endl;
			cout << "年龄:" << Book->contacts[i].u_age << endl;
			cout << "电话:" << Book->contacts[i].u_Phone << endl;
			cout << "地址:" << Book->contacts[i].u_address << endl;
		}
	}
	if (i == Book->u_Size - 1) {
		cout << "没有找到该联系人" << endl;
	}
	cout << "---------------------------" << endl;
	cout << "---------------------------" << endl;
}

int main()
{	
	Addressbooks Lbook;
	//初始话通讯录
	Lbook.u_Size = 0;



	//保存用户输入的值
	int select;
	while (1) {
	//调用菜单
	show_Menu();
	cin >> select;
	switch (select) {
	case 1:			//添加联系人
		Add_contacts(&Lbook);
		break;
	case 2:			//显示联系人 
		Printf_contacts(&Lbook);
		break;
	case 3:			//删除联系人 
		Dele_contacts(&Lbook);
		break;
	case 4:			//修改联系人
		Modify_contacts(&Lbook);
		break;
	case 5:			//清空联系人
		Clear_contacts(&Lbook);
		break;
	case 6:			//退出联系人
		cout << "欢迎下次使用" << endl;
		system("pause");
		return 0;
		break;
	case 7:			//显示具体练习人信息
		Printf_one(&Lbook);
		break;

	}
}
}
