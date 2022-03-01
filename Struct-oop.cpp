#include <iostream>
#include <string.h>
using namespace std;

struct Employee {
	char Id[8];
	char Full_Name[20];
	char Department[10];
	int salary;
	int bonus;
	int reward;
};
int main() {
	int n;
	cin >> n;
	Employee* arr;
	arr = new Employee[n];
	for (int i = 0; i < n; i++) {
		cin.ignore();
		cin >> arr[i].Id;
		cin >> arr[i].Full_Name;
		cin >> arr[i].Department;
		cin >> arr[i].salary >> arr[i].bonus;
		arr[i].reward = arr[i].salary + arr[i].bonus;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		// Xuat reward
		cout << arr[i].reward << endl;
	}
	cout << endl;
	// Minimum Salary
	int minimum;
	for (int i = 0; i < n; i++) {
		if (i == 0) minimum = arr[i].salary;
		if (arr[i].salary < minimum) minimum = arr[i].salary;
	}
	for (int i = 0; i < n; i++) {
		if (minimum == arr[i].salary) cout << arr[i].Full_Name << " ";
	}
	cout << endl;
	// Bonus >= 120000
	int bonus_number = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].bonus >= 120000) bonus_number++;
	}
	cout << bonus_number << endl;
	// Sap xep danh sach nhan vien phong ban tang dan va ma nhan vien giam dan
		// Sap xep phong ban tang dan
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(arr[i].Department, arr[j].Department) > 0) {
				Employee temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
		// Ma nhan vien giam dan
	char pos[20];
	strcpy_s(pos, arr[0].Department);
	int temp = 0;
	for (int i = 0; i < n; i++) {
		while (strcmp(arr[i].Department, pos) == 0) {
			i++;
		}
		for (int j = temp; j < i; j++) {
			for (int k = j + 1; k < i; k++) {
				if (arr[j].Id < arr[k].Id) {
					Employee temp = arr[j];
					arr[j] = arr[k];
					arr[k] = temp;
				}
			}
		}
		temp = i;
		continue;
	}
	
	for (int i = 0; i < n; i++) {
		cout << arr[i].Full_Name << " ";
	}
	delete []arr;
	return 0;
}
