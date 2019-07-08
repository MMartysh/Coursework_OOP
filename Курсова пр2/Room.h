#pragma once


class CRoom
{
private:
short int m_nRoomNumber;
string m_sRoomType;
vector <string> m_sEquipment;
double m_dblArea;
public:
	CRoom();
	~CRoom();
	void setRoomNumber(int);
	void setRoomType(string);
	void setRoomArea(double);
	void setRoomEquipment(int,string);
	string getRoomType();
	void getRoomEquipment();
	double getRoomArea();
	int getRoomNumber();
	void write();
	void read();
};