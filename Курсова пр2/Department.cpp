#include "stdafx.h"
#include "Department.h"

  CDepartment::CDepartment()
	{	
	}

	CDepartment::~CDepartment()
	{
		m_pMedicine.clear();
	}

	void CDepartment::setDepartmentNumber(int num)
	{
		m_nDepartmentNumber=num;
	}

	void CDepartment::setDepartmentName(string n)
	{
		m_sDepartmentName=n;
	}

	string CDepartment::getDepartmentName()
	{
		return m_sDepartmentName;
	}

	void CDepartment::setDepartmentDrugTypeCount(int a)
	{
		m_nDepartmentDrugTypes=a;
		m_pMedicine.resize(a);
		for(int i=0;i<a;i++)
		{
			cout<<"Enter drug name: ";
			cin>>m_pMedicine[i].name;
			cout<<endl<<"Enter drug count: ";
			cin>>m_pMedicine[i].num;
			cout<<endl<<"Enter drug price: ";
			cin>>m_pMedicine[i].price;
		}
	}

	int CDepartment::getDepartmentDrugTypeCount()
	{
		return m_nDepartmentDrugTypes;
	}

	int CDepartment::getEmployeesAmount()
	{
		return m_pEmployee.size();
	}

	void CDepartment::setEmployeesAmount(int amount)
	{
		m_nEmployeesAmount=amount;
		for(int i=0;i<CHospital::getEmployeesAmount();i++)
		{
			if(CHospital::m_pEmployee[i].Department==m_sDepartmentName)
			{
			m_pEmployee.push_back(CHospital::m_pEmployee[i]);
			}
		}

	}

	void CDepartment::setPatientsAmount(int amount)
	{
		m_nPatientsAmount=amount;
		for(int i=0;i<CHospital::getPatientsAmount();i++)
		{
			if(CHospital::m_pPatient[i].Department==m_sDepartmentName)
			{
			m_pPatient.push_back(CHospital::m_pPatient[i]);
			}
		}
	}

	int CDepartment::getPatientAmount()
	{
	return m_pPatient.size();
	}

	void CDepartment::readPatients()
	{
		Patient pat;
		string s=m_sDepartmentName+"Patients.txt";
		ifstream patients;
		patients.open(s);
		if(patients.is_open())
		{
		while(!patients.eof())
		{
			patients>>pat.FName>>pat.LName>>pat.MName>>pat.Age>>pat.Ilness>>pat.Department>>pat.ChamberNumber;
			if(pat.Department==m_sDepartmentName)
			{
				m_pPatient.push_back(pat);
			}
		}
		}
	patients.close();
	}

	void CDepartment::readEmployees()
	{
		Employee emp;
		string s=m_sDepartmentName+"Employees.txt";
		ifstream employees;
		employees.open(s);
		if(employees.is_open())
		{
		while(!employees.eof())
		{
			employees>>emp.Department>>emp.FName>>emp.LName>>emp.MName>>emp.Age>>emp.Occupancy>>emp.Salary;
			if(emp.Department==m_sDepartmentName)
			{
				m_pEmployee.push_back(emp);
			}
		}
		}
	employees.close();
	}

	void CDepartment::readMedicine()
	{
		Medicine med;
		ifstream medicine;
		string s=m_sDepartmentName+"Medicine.txt";
		medicine.open(s);
		if(medicine.is_open())
		{
		while(!medicine.eof())
		{
			medicine>>med.name>>med.num>>med.price;
			m_pMedicine.push_back(med);
		}
		}
		medicine.close();
	}

	void CDepartment::writePatients()
	{
		ofstream patients;
		string s=m_sDepartmentName+"Patients.txt";
		patients.open(s);
		for(int i=0;i<m_pPatient.size();i++)
		{
			if(m_pPatient[i].Department==m_sDepartmentName)
			{
			patients<<m_pPatient[i].FName<<" ";
			patients<<m_pPatient[i].LName<<" ";
			patients<<m_pPatient[i].MName<<" ";
			patients<<m_pPatient[i].Age<<" ";
			patients<<m_pPatient[i].Ilness<<" ";
			patients<<m_pPatient[i].Department<<" ";
			patients<<m_pPatient[i].ChamberNumber<<endl;
			}
		}
		patients.close();
	}

	void CDepartment::writeEmployees()
	{
		ofstream employees;
		string s=m_sDepartmentName+"Employees.txt";
		employees.open(s);
		for(int i=0;i<m_pEmployee.size();i++)
		{
			if(m_pEmployee[i].Department==m_sDepartmentName)
			{
			employees<<m_pEmployee[i].Department<<" ";
			employees<<m_pEmployee[i].FName<<" ";
			employees<<m_pEmployee[i].LName<<" ";
			employees<<m_pEmployee[i].MName<<" ";
			employees<<m_pEmployee[i].Age<<" ";
			employees<<m_pEmployee[i].Occupancy<<" ";
			employees<<m_pEmployee[i].Salary;
			}
		}
		employees.close();
	}

	void CDepartment::writeMedicine()
	{
		string me=m_sDepartmentName+"Medicine.txt";
		ofstream medicine;
		medicine.open(me);
		for(int i=0;i<m_pMedicine.size();i++)
		{
			medicine<<m_pMedicine[i].name<<" "<<m_pMedicine[i].num<<" "<<m_pMedicine[i].price<<endl;
		}
		medicine.close();
	}

	void CDepartment::buyMedicine(int count, int DrugNumber)
	{
		CHospital::m_dblFunds-=(count*m_pMedicine[DrugNumber].price);
	}

	void CDepartment::deleteDrug(int DrugNumber)
	{
		m_pMedicine.erase(m_pMedicine.begin()+DrugNumber);
	}

	void CDepartment::writeDepartmentInfo()
	{
		ofstream department;
		department.open((m_sDepartmentName+".txt"));
		department<<m_nEmployeesAmount<<" ";
		department<<m_nPatientsAmount<<" ";
		department<<m_nDepartmentDrugTypes<<" ";
		department.close();
	}

	void CDepartment::readDepartmentInfo()
	{
		ifstream department;
		department.open((m_sDepartmentName+".txt"));
		if(department.is_open())
		{
		department>>m_nEmployeesAmount;
		department>>m_nPatientsAmount;
		department>>m_nDepartmentDrugTypes;
		}
		department.close();
	}

	void CDepartment::startRead()
	{
		readDepartmentInfo();
		readMedicine();
		readEmployees();
		readPatients();
	}

	void CDepartment::startWrite()
	{
		writeDepartmentInfo();
		writeMedicine();
		writeEmployees();
		writePatients();
	}

	void CDepartment::showInfo()
	{
		cout<<"Department: "<<this->getDepartmentName()<<endl;
		cout<<"Employees amount: "<<this->getEmployeesAmount()<<endl;
		cout<<"Patients amount: "<<this->getPatientAmount()<<endl;
		cout<<"Medicine: "<<endl;
		for(int i=0;i<m_nDepartmentDrugTypes;i++)
		{
			cout<<"Name: "<<m_pMedicine[i].name<<" Amount: "<<m_pMedicine[i].num<<endl;
		}
	}
