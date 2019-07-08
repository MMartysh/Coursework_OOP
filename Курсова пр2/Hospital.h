#pragma once
struct Patient
{
	string FName;
	string LName;
	string MName;
	short int Age;
	string Ilness;
	short int ChamberNumber;
	string Department;
};

struct Employee
{
	string FName;
	string LName;
	string MName;
	short int Age;
	string Occupancy;
	string Department;
	double Salary;
};

class CHospital
{
protected:
vector <Patient> m_pPatient;
vector <Employee> m_pEmployee;
short int m_nEmployeesAmount;
short int m_nPatientsAmount;
Employee m_structEmpty;
Patient m_structEmpty1;
private:
double m_dblFunds;
int m_nAmbulanceNumber;
int m_nRoomsAmount;
int m_nAmbulanceOnWay;
short int m_nChambersCount;
short int m_nDepartmentsNumber;
friend class CDepartment;
friend class CRoom;
vector <CDepartment> m_pDepart;
vector <CRoom> m_pRoom;
public:
	int m_nChambers;
	CHospital();
	virtual ~CHospital();
	void changeDepartment(int);
	void setDepartmentsNumber(int);
	virtual void setPatientsAmount(int);
	virtual void setEmployeesAmount(int);
	void setChambersCount(int);
	void setFund(double);
	void setAmbulanceNumber(int);
	void setRoomsAmount(int);
	virtual int getEmployeesAmount();
	void getDepartmentEmployeesAmount(int);
	int getPatientsAmount();
	int getChambersCount();
	int getDepartmentsNumber();
	int getRoomsAmount();
	int getAmbulanceNumber();
	double getFund();
	string getDepartmentName(int);
	virtual void readPatients();
	virtual void readEmployees();
	void readDepartmentNames();
	void writeDepartmentNames();
	virtual void writePatients();
	virtual void writeEmployees();
	void promoteEmployee(int, string, double);
	void assignPatientToChamber(int, int);
	void diagnosePatient(string, int);
	void dismissEmployee(int);
	void hireEmployee();
	void curePatient(int);
	void takePatientOnTreatment();
	void paySalary();
	void receiveFunding(double);
	void costs(double);
	void writeHospitalInfo();
	void readHospitalInfo();
	virtual void startRead();
	virtual void startWrite();
	virtual void showInfo();
	void showDepartmentInfo(int);
	void search(string, int);
	void search(int, int);
	int search(string,bool);
	void inputDepartments();
	void inputEmployees();
	void inputPatients();
	void inputRooms();
	void sendAmbulance();
	void ambulanceArrived(int);
	void writeRooms();
	void readRooms();
};




