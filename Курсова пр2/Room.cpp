#include "stdafx.h"
#include "Room.h"
#include "Hospital.h"

	CRoom::CRoom()
	{
		m_nRoomNumber=-1;
		m_sRoomType="Default";
		m_dblArea=-1.0;
	}
	CRoom::~CRoom()
	{
		m_sEquipment.clear();
	}
	void CRoom::setRoomNumber(int num)
	{
		m_nRoomNumber=num;
	}
	void CRoom::setRoomType(string type)
	{
		m_sRoomType=type;
	}
	void CRoom::setRoomArea(double area)
	{
		m_dblArea=area;
	}
	void CRoom::setRoomEquipment(int eqnum, string equip)
	{
		m_sEquipment[eqnum]=equip;
	}
	string CRoom::getRoomType()
	{
		return m_sRoomType;
	}

	void CRoom::getRoomEquipment()
	{
		int k=m_sEquipment.size();
		for(int i=0;i<k;i++)
		{
			cout<<m_sEquipment[i]<<" ";
		}
	}

	double CRoom::getRoomArea()
	{
		return m_dblArea;
	}

	int CRoom::getRoomNumber()
	{
		return m_nRoomNumber;
	}

	void CRoom::write()
	{
		string s;
		s=m_nRoomNumber+"R.txt";
		ofstream room;
		room.open(s,ios::out|ios::trunc);
		room<<getRoomNumber()<<" ";
		room<<getRoomType()<<" ";
		getRoomEquipment();
		room<<getRoomArea()<<endl;
	}
	void CRoom::read()
	{
		string s;
		s=m_nRoomNumber+"R.txt";
		ifstream room;
		room.open(s);
	}