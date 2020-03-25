#include <iostream>
#include <stdlib.h>	//Для очистки экрана консоли
#include <Windows.h>
#include "FamilyMember.h"

using namespace std;

int main() {
	SetConsoleCP(1251);			//Задаем кодировку для вывода символов в консоли
	SetConsoleOutputCP(1251);	//Задаем кодировку для ввода символов в консоли

	int menueMode = 1;
	string buffer;

	FamilyMember familyFounder;
	FamilyMember::currentFamilyMember = &familyFounder;
	cout << "Введите имя ослнователя рода: ";
	cin >> buffer;
	familyFounder.setName(buffer);

	
	
	
	while (menueMode != 0) {

		system("cls");	//Очистка экрана консоли
		FamilyMember::currentFamilyMember->showCurrentFamilyMember();

		cout << endl;
		cout << "Выберете действие:" << endl;
		cout << "\tВвести или изменить имя текущего члена семьи\t1" << endl;
		cout << "\tДобавить ребенка для текущего члена семьи\t2" << endl;
		cout << "\tПерейти к родителю\t3" << endl;
		cout << "\tПерейти к ребенку\t4" << endl;
		cout << "\tПолучить информацию о типе родства нажмите\t5" << endl;
		cout << "\tПолучить полную информацию о члене семьи\t6" << endl;
		cout << "\tДля выхода из приложения нажмите\t0" << endl;
		cout << endl << "Ваш выбор: ";

		cin >> menueMode;

		switch (menueMode) {
		case 0: 
			break;
		case 1:
			system("cls");
			cout << "Введите имя: ";
			cin >> buffer;
			FamilyMember::currentFamilyMember->setName(buffer);
			system("pause");
			break;
		case 2: {
			system("cls");
			cout << "Введите имя ребенка: ";
			cin >> buffer;
			FamilyMember tempFamilyMember(buffer);
			FamilyMember::currentFamilyMember->addChild(tempFamilyMember);
		}
			break;
		case 3:
			FamilyMember::currentFamilyMember->goToParent();
			break;
		case 4:
		{
			FamilyMember::currentFamilyMember->showCurrentFamilyMenberFullInfo();
			cout << "Введите индекс ребенка, к которому хотите пререйти: ";
			int childIndex;
			cin >> childIndex;
			FamilyMember::currentFamilyMember->goToChild(childIndex);
		}
			break;
		case 5:
			break;
		case 6:
			system("cls");
			FamilyMember::currentFamilyMember->showCurrentFamilyMenberFullInfo();
			system("pause");
			break;
		default:
			cout << "Ошибка при вводе" << endl;
			system("pause");
		}
	}

	return 0;
}