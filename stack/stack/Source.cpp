#include <iostream>
#define MAX 50
using namespace std;

int main() {
 
	cout << " ______     ______   ______     ______     __  __    \n";
	cout << "/\\  ___\\   /\\__  _\\ /\\  __ \\   /\\  ___\\   /\\ \\/ /\n";
	cout << "\\ \\___  \\  \\/_/\\ \\/ \\ \\  __ \\  \\ \\ \\____  \\ \\  _\"-.\n";
	cout << " \\/\\_____\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\\n";
	cout << "  \\/_____/     \\/_/   \\/_/\\/_/   \\/_____/   \\/_/\\/_/\n";
	cout << "\n\n\n";

	int stack[MAX] = { 0 };
	int num = 0;
	int temp = 0;
	string cmd;

	cout << "==========How To Use?==========\n\n";
	cout << "  push  : 將數字放入堆疊\n";
	cout << "  pop   : 將數字移出堆疊\n";
	cout << "  list  : 列出堆疊中現有資料\n";
	cout << "  clear : 清空堆疊\n";
	cout << "  exit  : 結束\n";
	cout << "\n";
	cout << "======================Ver. 1.0=\n\n";


	while (1) {
		cout << "[+] Enter Command: ";
		cin >> cmd;
		cout << "\n";
		if (cmd == "push") {
			if (num == MAX) {
				cout << "Stack Is Full! \n";
			}
			else {
				cout << "[+] Enter Number: ";
				cin >> temp;
				stack[num] = temp;
				num += 1;
			}
			cout << "---------------------------------\n";

		}
		if (cmd == "pop") {
			if ((num-1) < 0) {
				cout << "Stack Is Entpy! \n";
			}
			else {
				num -= 1;
				cout << stack[num] << '\n';
				stack[num] = 0;
			}
			cout << "---------------------------------\n";

		}
		if (cmd == "list") {
			if (num == 0) {
				cout << "Stack Is Entpy! \n";
			}
			else {
				cout << "Now in stack...\n\n >Index: Number\n\n";
				for (int i = num-1; i >= 0; i--) {
					printf(" >%d: %d\n", i, stack[i]);
				}
				cout << "\n";
			}
			
			cout << "---------------------------------\n";
		}
		if (cmd == "clear") {
			cout << "Clear All Stack!\n";
			for (int i = 0; i < num; i++) {
				stack[i] = 0;
			}
			num = 0;
			cout << "---------------------------------\n";
		}
		if (cmd == "exit") {
			return 0;
		}
	}
	


	return 0;
}