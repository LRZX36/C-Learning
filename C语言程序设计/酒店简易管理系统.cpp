#include<bits/stdc++.h>
using namespace std;

#define ll long long

void star() {
	cout << "************************************\n";
}

struct Guest {
	ll IDcard, Phone;
	string name;
};

struct Room {
	ll room_number;
	bool IsOccupied;
	ll guestID;
};

map<ll, Guest> guests;
map<ll, Room> rooms;

void addRoom(ll RoomNumber) {
	if (rooms.find(RoomNumber) == rooms.end()) {
		Room newRoom = {RoomNumber, false, -1};
		rooms[RoomNumber] = newRoom;
	}
}

void addGuest(ll IDcard, ll Phone, string name) {
	if (guests.find(IDcard) == guests.end()) {
		Guest newGuest = {IDcard, Phone, name};
		guests[IDcard] = newGuest;
		star();
		cout << "客人" << name << "添加成功！\n";
	} else {
		star();
		cout << "客人" << name << "已存在！\n";
	}
}

void checkIn(ll RoomNumber, ll IDcard) {
	if (rooms.find(RoomNumber) == rooms.end()) {
		cout << "房间" << RoomNumber << "不存在！\n";
	} else if (rooms[RoomNumber].IsOccupied) {
		cout << "房间" << RoomNumber << "已被占用！\n";
	} else if (guests.find(IDcard) == guests.end()) {
		cout << "客人不存在！\n";
	} else {
		rooms[RoomNumber].IsOccupied = true;
		rooms[RoomNumber].guestID = IDcard;
		cout << "入住成功！\n";
		star();
	}
}

void checkOut(ll RoomNumber) {
	if (rooms.find(RoomNumber) == rooms.end()) {
		cout << "房间" << RoomNumber << "不存在！\n";
	} else if (!rooms[RoomNumber].IsOccupied) {
		cout << "房间" << RoomNumber << "未被占用！\n";
	} else {
		rooms[RoomNumber].IsOccupied = false;
		rooms[RoomNumber].guestID = -1;
		cout << "退宿成功！\n";
		star();
	}
}

void checkRoomStatus(ll RoomNumber) {
	star();
	if (rooms.find(RoomNumber) == rooms.end()) {
		cout << "房间号 " << RoomNumber << " 未找到\n";
	} else {
		cout << "房间" << RoomNumber << ":";
		if (rooms[RoomNumber].IsOccupied) {
			cout << "入住中\n";
			ll guestID = rooms[RoomNumber].guestID;
			cout << "入住人姓名：" << guests[guestID].name << '\n';
			cout << "入住人身份证：" << guests[guestID].IDcard << '\n';
			cout << "入住人手机号：" << guests[guestID].Phone << '\n';
		} else {
			cout << "空闲中\n";
		}
	}
	star();
}

void displayRoomInformation() {
	cout << "\n房间信息：\n";
	star();
	int count = 0;
	for (auto& room : rooms) {
		cout << "房间" << setw(3) << room.second.room_number << ":";
		if (room.second.IsOccupied) {
			ll guestID = room.second.guestID;
			cout << "入住中(" << guests[guestID].name << ")";
		} else {
			cout << "空闲中";
		}
		count++;
		if (count % 4 == 0) {
			cout << '\n';
		} else {
			cout << '\t';
		}
	}
	if (count % 4 != 0) {
		cout << '\n';
	}
	star();
}

void displayGuestInformation() {
	cout << "\n客人信息：\n";
	star();
	for (auto& guest : guests) {
		cout << "姓名: " << guest.second.name << "\n";
		cout << "身份证: " << guest.second.IDcard << "\n";
		cout << "手机号: " << guest.second.Phone << "\n";
		cout << '\n';
	}
	star();
}

int main() {
	ll choice;
	cout << "欢迎使用酒店简易管理系统！\n";
	star();
	// 初始化房间
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			addRoom(i * 100 + j);
		}
	}
	while (true) {
		cout << "选择您的操作：\n1.添加客人\n2.办理入住\n3.办理退宿\n4.查询房间状态\n5.显示房间信息\n6.显示客人信息\n7.退出\n请输入数字：";
		cin >> choice;
		switch (choice) {
			case 1: {
				ll IDcard, Phone;
				string name;
				star();
				cout << "请输入客人姓名：";
				cin >> name;
				cout << "请输入客人身份证号码：";
				cin >> IDcard;
				cout << "请输入客人手机号码：";
				cin >> Phone;
				addGuest(IDcard, Phone, name);
				star();
				break;
			}
			case 2: {
				ll RoomNumber, IDcard;
				cout << "请输入房间号：";
				cin >> RoomNumber;
				cout << "请输入客人身份证号码：";
				cin >> IDcard;
				star();
				checkIn(RoomNumber, IDcard);
				break;
			}
			case 3: {
				ll RoomNumber;
				cout << "请输入房间号：";
				cin >> RoomNumber;
				star();
				checkOut(RoomNumber);
				break;
			}
			case 4: {
				ll RoomNumber;
				cout << "请输入房间号：";
				cin >> RoomNumber;
				checkRoomStatus(RoomNumber);
				break;
			}
			case 5: {
				displayRoomInformation();
				break;
			}
			case 6: {
				displayGuestInformation();
				break;
			}
			case 7: {
				star();
				cout << "退出程序！\n";
				star();
				return 0;
			}
			default:
				star();
				cout << "输入错误！\n";
				star();
				break;
		}
	}
}
