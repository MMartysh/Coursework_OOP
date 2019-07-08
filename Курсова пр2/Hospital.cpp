#include "stdafx.h"
#include "Department.h"
#include "Room.h"
#include "Hospital.h"

	CHospital::CHospital()
	{
	m_nEmployeesAmount=3;
	m_nPatientsAmount=9;
	m_nDepartmentsNumber=3;
	m_dblFunds=15000;
	m_nAmbulanceNumber=2;
	m_nRoomsAmount=10;
	m_nChambersCount=4;
	m_nAmbulanceOnWay=0;
	m_nChambers=1;
	}

	CHospital::~CHospital()
	{
		m_pDepart.clear();
		m_pPatient.clear();
		m_pEmployee.clear();
	}

	void CHospital::curePatient(int number)
	{
		m_pPatient.erase(m_pPatient.begin()+number);
		m_nPatientsAmount--;
	}

	string CHospital::getDepartmentName(int n)
	{
		return m_pDepart[n].getDepartmentName();
	}

	void CHospital::getDepartmentEmployeesAmount(int DepartNumber)
	{
		m_pDepart[DepartNumber].getEmployeesAmount();
	}

	void CHospital::setPatientsAmount(int amount)
	{
		m_nPatientsAmount=amount;
	}

	void CHospital::inputPatients()
	{
		Patient p;
		for(int i=0;i>m_nPatientsAmount;i++)
		{
		cout<<"Enter patient name: ";
		cin>>p.FName;
		cout<<endl<<"Enter patient last name: ";
		cin>>p.LName;
		cout<<endl<<"Enter patient middle name: ";
		cin>>p.MName;
		cout<<endl<<"Enter patient age: ";
		cin>>p.Age;
		cout<<endl<<"Enter patient ilness: ";
		cin>>p.Ilness;
		cout<<endl<<"Enter department: ";
		cin>>p.Department;
		cout<<endl<<"Enter patient chamber(if patient is not assigned enter -1): ";
		cin>>p.ChamberNumber;
		m_pPatient.push_back(p);
		}
	}

	int CHospital::getPatientsAmount()
	{
		return m_nPatientsAmount;
	}

	void CHospital::setEmployeesAmount(int amount)
	{
		m_nEmployeesAmount=amount;
	}

	void CHospital::inputEmployees()
	{
		Employee e;
		for(int i=0;i<m_nEmployeesAmount;i++)
		{
		cout<<"Enter employee name: ";
			cin>>e.FName;
			cout<<endl<<"Enter employee last name: ";
			cin>>e.LName;
			cout<<endl<<"Enter employee middle name: ";
			cin>>e.MName;
			cout<<endl<<"Enter employee age: ";
			cin>>e.Age;
			cout<<endl<<"Enter employee occupancy: ";
			cin>>e.Occupancy;
			cout<<endl<<"Enter department: ";
			cin>>e.Department;
			m_pEmployee.push_back(e);
		}
	}

	int CHospital::getEmployeesAmount()
	{
		return m_nEmployeesAmount;
	}

	void CHospital::setDepartmentsNumber(int num)
	{
		m_nDepartmentsNumber=num;
	}

	void CHospital::inputDepartments()
	{
		string name;
		int amount;
		CDepartment d;
		for(int i=0;i<m_nDepartmentsNumber;i++)
		{
			cout<<"Enter department name: ";
			cin>>name;
			cout<<endl;
			d.setDepartmentNumber(i+1);
			d.setDepartmentName(name);
			cout<<"Enter department drug types: ";
			cin>>amount;
			d.setDepartmentDrugTypeCount(amount);
			cout<<"Enter employees amount: ";
			cin>>amount;
			d.setEmployeesAmount(amount);
			cout<<endl;
			cout<<"Enter patients amount: ";
			cin>>amount;
			d.setPatientsAmount(amount);
			cout<<endl;
			m_pDepart.push_back(d);
		}
	}

	int CHospital::getDepartmentsNumber()
	{
		return m_nDepartmentsNumber;
	}

	void CHospital::dismissEmployee(int number)
	{
		m_pEmployee.erase(m_pEmployee.begin()+number);
		m_nEmployeesAmount--;
	}

	void CHospital::hireEmployee()
	{
		m_nEmployeesAmount++;
		cout<<"Enter employee name: ";
			cin>>m_structEmpty.FName;
			cout<<endl<<"Enter employee last name: ";
			cin>>m_structEmpty.LName;
			cout<<endl<<"Enter employee middle name: ";
			cin>>m_structEmpty.MName;
			cout<<endl<<"Enter employee age: ";
			cin>>m_structEmpty.Age;
			cout<<endl<<"Enter employee occupancy: ";
			cin>>m_structEmpty.Occupancy;
			cout<<endl<<"Enter department: ";
			cin>>m_structEmpty.Department;
			cout<<endl<<"Enter salary: ";
			cin>>m_structEmpty.Salary;
			m_pEmployee.push_back(m_structEmpty);
	}

	void CHospital::setChambersCount(int ch)
	{
		m_nChambersCount=ch;
	}

	int CHospital::getChambersCount()
	{
		return m_nChambersCount;
	}

	void CHospital::setFund(double sum)
	{
		m_dblFunds=sum;
	}

	double CHospital::getFund()
	{
		return m_dblFunds;
	}

	void CHospital::readDepartmentNames()
	{
	string a;
	int i=0;
	CDepartment d;
	ifstream departnames;
	departnames.open("depname.txt");
	if(departnames.is_open())
		{
	while(!departnames.eof())
	{
		departnames>>a;
		m_pDepart.push_back(d);
		m_pDepart[i].setDepartmentName(a);
		m_pDepart[i].setDepartmentNumber(i+1);
		i++;
	}
		}
	departnames.close();
	}

	void CHospital::writeDepartmentNames()
	{
		ofstream departnames;
		departnames.open("depname.txt",ios_base::out | ios_base::trunc);
		for(int i=0;i<m_pDepart.size();i++)
		{
			departnames<<m_pDepart[i].getDepartmentName()<<endl;
		}
		departnames.close();
	}

	void CHospital::writeEmployees()
	{
		ofstream employees;
		employees.open("Employees.txt",ios_base::out | ios_base::trunc);
		for(int i=0;i<m_pEmployee.size();i++)
		{
			employees<<m_pEmployee[i].FName<<" ";
			employees<<m_pEmployee[i].LName<<" ";
			employees<<m_pEmployee[i].MName<<" ";
			employees<<m_pEmployee[i].Age<<" ";
			employees<<m_pEmployee[i].Department<<" ";
			employees<<m_pEmployee[i].Salary<<" ";
			employees<<m_pEmployee[i].Occupancy;
			employees<<endl;
		}
		employees.close();
	}

	void CHospital::readEmployees()
	{
		Employee emp;
		ifstream employees;
		employees.open("Employees.txt");
		if(employees.is_open())
		{
		while(!employees.eof())
		{
			employees>>emp.FName;
			employees>>emp.LName;
			employees>>emp.MName;
			employees>>emp.Age;
			employees>>emp.Department;
			employees>>emp.Salary;
			employees>>emp.Occupancy;
			m_pEmployee.push_back(emp);
		}
		}
		employees.close();
	}

	void CHospital::writePatients()
	{
		ofstream patients;
		patients.open("Patients.txt",ios_base::out | ios_base::trunc);
		for(int i=0;i<m_pPatient.size();i++)
		{
			patients<<m_pPatient[i].FName<<" ";
			patients<<m_pPatient[i].LName<<" ";
			patients<<m_pPatient[i].MName<<" ";
			patients<<m_pPatient[i].Age<<" ";
			patients<<m_pPatient[i].Ilness<<" ";
			patients<<m_pPatient[i].Department<<" ";
			patients<<m_pPatient[i].ChamberNumber<<endl;
			
		}
		patients.close();
	}

	void CHospital::readPatients()
	{
		Patient pat;
		ifstream patients;
		patients.open("Patients.txt");
		if(patients.is_open())
		{
		while(!patients.eof())
		{
			patients>>pat.FName;
			patients>>pat.LName;
			patients>>pat.MName;
			patients>>pat.Age;
			patients>>pat.Ilness;
			patients>>pat.Department;
			patients>>pat.ChamberNumber;
			m_pPatient.push_back(pat);
		}
		}
		patients.close();
	}

	void CHospital::takePatientOnTreatment()
	{
		m_nPatientsAmount++;
		Patient p;
		cout<<"Enter patient name: ";
			cin>>p.FName;
			cout<<endl<<"Enter patient last name: ";
			cin>>p.LName;
			cout<<endl<<"Enter patient middle name: ";
			cin>>p.MName;
			cout<<endl<<"Enter patient age: ";
			cin>>p.Age;
			cout<<endl<<"Enter patient Ilness: ";
			cin>>p.Ilness;
			cout<<endl<<"Enter patient chamber(if not assigned enter -1): ";
			cin>>p.ChamberNumber;
			cout<<endl<<"Enter department: ";
			cin>>p.Department;
			m_pPatient.push_back(p);
	}
	
	void CHospital::promoteEmployee(int empnum, string occ, double sal)
	{
		m_pEmployee[empnum].Occupancy=occ;
		m_pEmployee[empnum].Salary=sal;
	}

	void CHospital::assignPatientToChamber(int patnum, int chnum)
	{
		m_pPatient[patnum].ChamberNumber=chnum;
	}

	void CHospital::diagnosePatient(string illness, int patnum)
	{
		m_pPatient[patnum].Ilness=illness;
	}

	void CHospital::paySalary()
	{
		for(int i=0;i<m_pEmployee.size();i++)
		{
			m_dblFunds-=m_pEmployee[i].Salary;
		}
	}

	void CHospital::receiveFunding(double funding)
	{
		m_dblFunds+=funding;
	}

	void CHospital::costs(double costs)
	{
		m_dblFunds-=costs;
	}

	void CHospital::writeHospitalInfo()
	{
		ofstream hospital;
		hospital.open("Hospital.txt",ios_base::out | ios_base::trunc);
		hospital<<m_nEmployeesAmount<<" ";
		hospital<<m_nPatientsAmount<<" ";
		hospital<<m_nChambersCount<<" ";
		hospital<<m_nDepartmentsNumber<<" ";
		hospital<<m_dblFunds<<" ";
		hospital.close();
	}

	void CHospital::readHospitalInfo()
	{
		ifstream hospital;
		hospital.open("Hospital.txt");
		if(hospital.is_open())
		{
		hospital>>m_nEmployeesAmount;
		hospital>>m_nPatientsAmount;
		hospital>>m_nChambersCount;
		hospital>>m_nDepartmentsNumber;
		hospital>>m_dblFunds;
		}
		hospital.close();
	}

	void CHospital::startRead()
	{
		readDepartmentNames();
		readHospitalInfo();
		readPatients();
		readEmployees();
		for(int i=0;i<m_pDepart.size();i++)
		{
			m_pDepart[i].startRead();
		}

	}

	void CHospital::startWrite()
	{
		writeDepartmentNames();
		writeHospitalInfo();
		writePatients();
		writeEmployees();
		for(int i=0;i<m_pDepart.size();i++)
		{
			m_pDepart[i].startWrite();
		}
	}

	void CHospital::showInfo()
	{
	cout<<"Employees amount: "<<getEmployeesAmount()<<endl;
	cout<<"Patients amount: "<<getPatientsAmount()<<endl;
	cout<<"Number of chambers: "<<getChambersCount()<<endl;
	cout<<"Number of departments: "<<getDepartmentsNumber()<<endl;
	cout<<"Number of emergency brigades: "<<getAmbulanceNumber()<<endl;
	}

	void CHospital::showDepartmentInfo(int num)
	{
		m_pDepart[num].showInfo();
	}

	void CHospital::setAmbulanceNumber(int number)
	{
		m_nAmbulanceNumber=number;
	}

	void CHospital::setRoomsAmount(int number)
	{
		m_nRoomsAmount=number;
	}

	int CHospital::getRoomsAmount()
	{
		return m_nRoomsAmount;
	}

	int CHospital::getAmbulanceNumber()
	{
		return m_nAmbulanceNumber;
	}

	void CHospital::search(string s, int k)
	{
		switch(k)
		{
		case 1:
		{
		for(int i=0;i<m_pEmployee.size();i++)
			{
		if(s==m_pEmployee[i].FName || s==m_pEmployee[i].LName)
				{
				cout<<"Department: "<<m_pEmployee[i].Department<<endl;
				cout<<"Name: "<<m_pEmployee[i].FName<<endl;
				cout<<"Last name: "<<m_pEmployee[i].LName<<endl;
				cout<<"Middle name: "<<m_pEmployee[i].MName<<endl;
				cout<<"Age: "<<m_pEmployee[i].Age<<endl;
				cout<<"Occupancy: "<<m_pEmployee[i].Occupancy<<endl;
				}
			}
		break;
		}
		case 2:
		{
			for(int i=0;i<m_pPatient.size();i++)
			{
			if(s==m_pPatient[i].FName || s==m_pPatient[i].LName || s==m_pPatient[i].Ilness)
					{
			cout<<"Department: "<<m_pPatient[i].Department<<endl;
			cout<<"Name: "<<m_pPatient[i].FName<<endl;
			cout<<"Last name: "<<m_pPatient[i].LName<<endl;
			cout<<"Middle name: "<<m_pPatient[i].MName<<endl;
			cout<<"Age: "<<m_pPatient[i].Age<<endl;
			cout<<"Diagnosis: "<<m_pPatient[i].Ilness<<endl;
			cout<<"Chamber: "<<m_pPatient[i].ChamberNumber<<endl;
					}
			}
			break;
		}
		case 3:
		{
			for(int i=0;i<m_pEmployee.size();i++)
			{
		if(s==m_pEmployee[i].FName || s==m_pEmployee[i].LName)
				{
				cin>>m_pEmployee[i].Department;
				cin>>m_pEmployee[i].FName;
				cin>>m_pEmployee[i].LName;
				cin>>m_pEmployee[i].MName;
				cin>>m_pEmployee[i].Age;
				cin>>m_pEmployee[i].Occupancy;
				}
			}
		
			break;
		}
		case 4:
			{
			for(int i=0;i<m_pPatient.size();i++)
			{
			if(s==m_pPatient[i].FName || s==m_pPatient[i].LName || s==m_pPatient[i].Ilness)
					{
			cin>>m_pPatient[i].Department;
			cin>>m_pPatient[i].FName;
			cin>>m_pPatient[i].LName;
			cin>>m_pPatient[i].MName;
			cin>>m_pPatient[i].Age;
			cin>>m_pPatient[i].Ilness;
			cin>>m_pPatient[i].ChamberNumber;
					}
			}
				break;
			}
		}
	}

	void CHospital::search(int s, int k)
	{
		double e;
		string r;
		int t=0;
		if(k==1)
		{
			for(int i=0;i<m_pRoom.size();i++)
			{
				if(s==m_pRoom[i].getRoomNumber())
				{
					cout<<"Area: "<<m_pRoom[i].getRoomArea()<<endl;
					cout<<"Room type: "<<m_pRoom[i].getRoomType()<<endl;
					cout<<"Room equipment: ";
					m_pRoom[i].getRoomEquipment();
				}
			}
		}
		else
		{
			for(int i=0;i<m_pRoom.size();i++)
			{
				if(s==m_pRoom[i].getRoomNumber())
				{
					cout<<"Enter area: ";
					cin>>e;
					m_pRoom[i].setRoomArea(e);
					cout<<endl;
					cout<<"Enter room type: ";
					cin>>r;
					m_pRoom[i].setRoomType(r);
					cout<<endl;
					cout<<"Enter number of room equipment: ";
					cin>>t;
					cout<<endl<<"Enter room equipment: "<<endl;
					for(int h=0;h<t;h++)
					{
					cin>>r;
					m_pRoom[i].setRoomEquipment(h,r);
					}
				}
			}
		}
	}

	void CHospital::changeDepartment(int number)
	{
		string name;
		int amount;
		int t;
		for(int i=0;i<m_pDepart.size();i++)
		{
			cout<<i+1<<"."<<m_pDepart[i].getDepartmentName()<<endl;
		}
		if(number==1)
		{
		cout<<"Which department?"<<endl;
		cin>>t;
		system("cls");
			cout<<"Enter department name: ";
			cin>>name;
			cout<<endl;
			m_pDepart[t-1].setDepartmentName(name);
			cout<<"Enter department drug types: ";
			cin>>amount;
			cout<<endl;
			m_pDepart[t-1].setDepartmentDrugTypeCount(amount);
			cout<<"Enter employees amount: ";
			cin>>amount;
			m_pDepart[t-1].setEmployeesAmount(amount);
			cout<<endl;
			cout<<"Enter patients amount: ";
			cin>>amount;
			m_pDepart[t-1].setPatientsAmount(amount);
			cout<<endl;
		}
		else if(number==2)
		{
			cout<<"What do you want to change?"<<endl;
			cout<<"1.Department name"<<endl;
			cout<<"2.Department medicine number"<<endl;
			cout<<"3.Patients amount"<<endl;
			cout<<"4.Employees amount"<<endl;
			cin>>t;
			system("cls");
			switch(t)
			{
			case 1:
				{
			cout<<"Enter department name: ";
			cin>>name;
			cout<<endl;
			m_pDepart[t-1].setDepartmentName(name);
			break;
				}
			case 2:
				{
			cout<<"Enter department drug types: ";
			cin>>amount;
			cout<<endl;
			m_pDepart[t-1].setDepartmentDrugTypeCount(amount);
			break;
				}
			case 3:
				{
			cout<<"Enter employees amount: ";
			cin>>amount;
			m_pDepart[t-1].setEmployeesAmount(amount);
			cout<<endl;
			break;
				}
			case 4:
				{
			cout<<"Enter patients amount: ";
			cin>>amount;
			m_pDepart[t-1].setPatientsAmount(amount);
			cout<<endl;
			break;
				}
			}
		}
	}

	int CHospital::search(string name,bool t)
	{
		string s;
		s=name;
		if(t)
		{
			for(int i=0;i<m_pEmployee.size();i++)
			{
		if(s==m_pEmployee[i].FName || s==m_pEmployee[i].LName)
				{
					return i;
				}
			}
		}
		else
		{
			for(int i=0;i<m_pPatient.size();i++)
			{
			if(s==m_pPatient[i].FName || s==m_pPatient[i].LName || s==m_pPatient[i].Ilness)
					{
						return i;
					}
			}
		}
		return 0;
	}

	void CHospital::sendAmbulance()
	{
		if(m_nAmbulanceOnWay<m_nAmbulanceNumber)
		{
			cout<<"Ambulance sent"<<endl;
		m_nAmbulanceOnWay++;
		_getch();
		}
		else
		{
			cout<<"Sorry, all ambulance was sent"<<endl;
			_getch();
		}
	}

	void CHospital::ambulanceArrived(int c)
	{
		if(c==1)
		{
		m_nAmbulanceOnWay--;
		}
		if(c==2)
		{
			m_nAmbulanceOnWay--;
			takePatientOnTreatment();

		}
		if(c!=1 && c!=2)
		{
			cout<<"You choosed wrong number"<<endl;
		}
	}

	void CHospital::inputRooms()
	{
		double e;
		string r;
		int t=0;
		CRoom R;
		for(int i=0;i<getRoomsAmount();i++)
		{
			cout<<"Enter area: ";
					cin>>e;
					R.setRoomArea(e);
					cout<<endl;
					cout<<"Enter room type: ";
					cin>>r;
					R.setRoomType(r);
					cout<<endl;
					cout<<"Enter number of room equipment: ";
					cin>>t;
					cout<<endl<<"Enter room equipment: "<<endl;
					for(int h=0;h<t;h++)
					{
					cin>>r;
					R.setRoomEquipment(h,r);
					}
					m_pRoom.push_back(R);
		}	
	}