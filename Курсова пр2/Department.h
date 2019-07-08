#pragma once
#include "Hospital.h"

struct Medicine
{
	string name;
	int num;
	double price;
};

class CDepartment : public CHospital
{
private:
	short int m_nDepartmentNumber;
	int m_nDepartmentDrugTypes;
	string m_sDepartmentName;
	vector <Medicine> m_pMedicine;
public:
	CDepartment();
	~CDepartment();
	void setDepartmentNumber(int);
	void setDepartmentName(string);
	void setDepartmentDrugTypeCount(int);
	void setEmployeesAmount(int);
	void setPatientsAmount(int);
	string getDepartmentName();
	int getDepartmentDrugTypeCount();
	int getEmployeesAmount();
	int getPatientAmount();
	void readPatients();
	void readEmployees();
	void readMedicine();
	void writePatients();
	void writeEmployees();
	void writeMedicine();
	void buyMedicine(int,int);
	void deleteDrug(int);
	void writeDepartmentInfo();
	void readDepartmentInfo();
	void startRead();
	void startWrite();
	void showInfo();
};
