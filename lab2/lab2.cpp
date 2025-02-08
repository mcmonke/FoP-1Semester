#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

	while(1){
		int hours, minutes, timeofday;
		char ch;
		cout << "Введите время";
		cout << " " << endl;
		cin >> hours >> minutes;

		//Определим неподходящие значения
		if (hours < 0 || hours >= 24 || minutes < 0 || minutes>59) {
			cout << "Недопустимое время!";
			cout << endl;
		}
		else {
			//Определим день и полночь
			if (hours == 12 && minutes == 0) {
				cout << "полдень";
				cout << endl;
			}
			else {
				if (hours == 0 && minutes == 0) {
					cout << "полночь";
					cout << endl;
				}
				else {
					//Определим падежи часов
					
					timeofday = hours;

					if (hours >= 13) {
						hours = hours - 12;
					}

					cout << hours << " ";
					if (hours == 1) {
						cout << "час ";
					}
					else {
						if (hours>= 2 && hours <= 4) {
							cout << "часа ";
						}
						else {
							if (hours > 4) {
								cout << "часов ";
							}
						}
					}
					
					//Определим падежи минут
					if (minutes != 0) {
						if (minutes % 10 == 1 && (minutes<10 || minutes>20)) {
							cout << minutes << " минута ";
						}
						else {
							if (minutes % 10 >= 2 && minutes % 10 <= 4 && (minutes<=10 || minutes>=20)) {
								cout << minutes << " минуты ";
							}
							else {
								if (minutes % 10 >= 5 && minutes % 10 < 10 || minutes % 10 == 0 || (minutes>10 && minutes<20)) {
									cout << minutes << " минут ";
								}
							}
						}
					}
					
					//Определим время суток
					if (timeofday > 0 && timeofday < 5) {
						cout << "ночи";
					}
					else {
						if (timeofday >= 5 && timeofday < 12) {
							cout << "утра";
						}
						else {
							if (timeofday >= 12 && timeofday < 18) {
								cout << "дня";
							}
							else {
								if (timeofday >= 18 && timeofday <= 23) {
									cout << "вечера";
								}
							}
						}
					}
					if (minutes == 0) {
						cout << " ровно";
					}
				}
			}
		}
		cout << " " << endl;

		cout << "Продолжить? 'y' if yes, and 'any other key' to break";
		cout << " " << endl;
		cin >> ch;
		if (ch != 'y'){
			break;
		}
	}
    return 0;
}



