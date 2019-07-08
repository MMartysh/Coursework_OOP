#include "stdafx.h"
#include "Hospital.h"
#include "Department.h"
#include "Room.h"
#pragma warning(disable : 4018 )
int main()
{
	CHospital hospital;
	hospital.startRead();
	char e;
	while(true)
	{
		system("cls");
		cout<<"Welcome to our hospital database!"<<endl;
		cout<<"Press s to show information"<<endl;
		cout<<"Press i to input some information"<<endl;
		cout<<"Press h to hire employee"<<endl;
		cout<<"Press d to dismiss employee"<<endl;
		cout<<"Press c to cure patient"<<endl;
		cout<<"Press t to take patient on treatment"<<endl;
		cout<<"Press a to send an ambulance"<<endl;
		cout<<"Press r if ambulance arrived"<<endl;
		cout<<"Press p to promote employee"<<endl;
		cout<<"Press g to assign patient to a chamber"<<endl;
		cout<<"Press o to diagnose patient"<<endl;
		cout<<"Press f if funding was received"<<endl;
		cout<<"Press l to pay salary"<<endl;
		cout<<"Press e to exit"<<endl;
		cin>>e;
		if(e=='e'){break;}
		switch(e)
	{
		case's':
		{
			system("cls");
			cout<<"Information about: "<<endl;
			cout<<"1.Department"<<endl;
			cout<<"2.Hospital"<<endl;
			cout<<"3.Employee"<<endl;
			cout<<"4.Patient"<<endl;
			
			cin>>e;
			switch(e)
			{
			case '1':
				{
					cout<<"Which department?"<<endl;
					for(int i=0;i<hospital.getDepartmentsNumber();i++)
					{
						cout<<i+1<<"."<<hospital.getDepartmentName(i)<<endl;
					}
					cin>>e;
					system("cls");
					hospital.showDepartmentInfo(e);
					_getch();
					break;
				}

			case '2':
				{
					system("cls");
					hospital.showInfo();
					_getch();
					break;
				}
			case '3':
				{
					system("cls");
					cout<<"Enter first name or second name of employee: ";
					string el;
					cin>>el;
					hospital.search(el,1);
					_getch();
					break;
				}
			case '4':
				{
					system("cls");
					cout<<"Enter first name or second name or diagnosis of patient: ";
					string el;
					cin>>el;
					hospital.search(el,2);
					_getch();
					break;
				}
			case '5':
				{
					system("cls");
					cout<<"Enter room number: ";
					int el;
					cin>>el;
					hospital.search(el,1);
					_getch();
					break;
				}
			}
			break;
		}
		case 'i':
			{
				system("cls");
				cout<<"Information about: "<<endl;
				cout<<"1.Departments"<<endl;
				cout<<"2.Hospital"<<endl;
				cout<<"3.Employee"<<endl;
				cout<<"4.Patient"<<endl;
				cout<<"5.Room"<<endl;
				cin>>e;
				switch(e)
				{
				case '1':
					{
						system("cls");
						cout<<"Choose how to input information: "<<endl;
						cout<<"1.Information about all departments"<<endl;
						cout<<"2.Information about one department"<<endl;
						cout<<"3.Change something"<<endl;
						cin>>e;
						switch(e)
						{
						case '1':
							{
								system("cls");
								hospital.inputDepartments();
								break;
							}
						case '2':
							{
								system("cls");
								hospital.changeDepartment(1);
								break;
							}
						case '3':
							{
								system("cls");
								hospital.changeDepartment(2);
								break;
							}
						}
						break;
					}
				case '2':
					{
						int a;
						double r;
						system("cls");
						cout<<"Enter departments amount: ";
						cin>>a;
						cout<<endl;
						hospital.setDepartmentsNumber(a);
						cout<<"Enter patients amount: ";
						cin>>a;
						cout<<endl;
						hospital.setPatientsAmount(a);
						cout<<"Enter employees amount: ";
						cin>>a;
						cout<<endl;
						hospital.setEmployeesAmount(a);
						cout<<"Enter chambers amount: ";
						cin>>a;
						cout<<endl;
						hospital.setChambersCount(a);
						cout<<"Enter funds: ";
						cin>>r;
						cout<<endl;
						hospital.setFund(r);
						cout<<"Enter ambulance amount: ";
						cin>>a;
						cout<<endl;
						hospital.setAmbulanceNumber(a);
						cout<<"Enter rooms amount: ";
						cin>>a;
						cout<<endl;
						hospital.setRoomsAmount(a);
						break;
					}
				case '3':
					{
						int a;
						system("cls");
						cout<<"Choose how to input information: "<<endl;
						cout<<"1.Information about one employee"<<endl;
						cout<<"2.Information about all employees"<<endl;
						cin>>a;
						switch(a)
						{
						case 1:
							{
								system("cls");
								string name;
								cout<<"Enter name or second name of employee: ";
								cin>>name;
								hospital.search(name,1);
								hospital.search(name,3);
								break;
							}
						case 2:
							{
								system("cls");
								hospital.inputEmployees();
								break;
							}
						}
						break;

					}
				case '4':
					{	int a;
						system("cls");
						cout<<"Choose how to input information: "<<endl;
						cout<<"1.Information about one patient"<<endl;
						cout<<"2.Information about all patients"<<endl;
						cin>>a;
						switch (a)
						{
						case 1:
							{
								system("cls");
								string name;
								cout<<"Enter name or second name of patient: ";
								cin>>name;
								hospital.search(name,2);
								hospital.search(name,4);
								break;
							}
						case 2:
							{
								system("cls");
								hospital.inputPatients();
								break;
							}
						}
						break;
					}
				case '5':
					{
						system("cls");
						int a;
						cout<<"Choose how to input information:"<<endl;
						cout<<"1.About one room"<<endl;
						cout<<"2.About all rooms"<<endl;
						//cout<<"3.Change something"<<endl;
						cin>>a;
						switch(a)
						{
						case 1:
							{
								int k;
								system("cls");
								cout<<"Enter room number: ";
								cin>>k;
								hospital.search(k,2);
								break;
							}
						case 2:
							{
								system("cls");
								hospital.inputRooms();
								break;
							}
						case 3:
							{
								system("cls");
								break;
							}
						}
						break;
					}
				}
				break;
			}
			case 'h':
				{
					system("cls");
					hospital.hireEmployee();
					break;
				}
				case 'd':
				{
					system("cls");
					string name;
					cout<<"Enter name or second name of employee: ";
					cin>>name;
					cout<<endl;
					hospital.dismissEmployee(hospital.search(name,true));
					break;
				}
				case 't':
				{
					system("cls");
					hospital.takePatientOnTreatment();
					break;
				}
				case 'c':
				{
					system("cls");
					string name;
					int r;
					cout<<"Enter name or second name of patient: ";
					cin>>name;
					cout<<endl;
					r=hospital.search(name,false);
					hospital.curePatient(r);
					break;
				}
				case 'a':
				{
					system("cls");
					hospital.sendAmbulance();
					break;
				}
				case 'r':
				{
					system("cls");
					int a;
					cout<<"If call was fake or aid was provided on spot press 1 else press 2"<<endl;
					cin>>a;
					hospital.ambulanceArrived(a);
					break;
				}
				case 'p':
				{
					system("cls");
					string name,occupancy;
					double sal;
					cout<<"Enter name or second name of employee: ";
					cin>>name;
					cout<<endl;
					cout<<"Enter new employee occupancy: ";
					cin>>occupancy;
					cout<<endl;
					cout<<"Enter employee salary: ";
					cin>>sal;
					cout<<endl;
					hospital.promoteEmployee(hospital.search(name,true),occupancy,sal);
					break;
				}
				case 'g':
				{
					string name;
					system("cls");
					cout<<"Enter name or second name of patient: ";
					cin>>name;
					cout<<endl;
					hospital.assignPatientToChamber(hospital.search(name,false),hospital.m_nChambers);
					hospital.m_nChambers++;
					break;
				}
				case 'o':
					{
						system("cls");
						string name,illness;
						cout<<"Enter patient name or surname: ";
						cin>>name;
						cout<<endl;
						cout<<"Diagnose patient: ";
						cin>>illness;
						cout<<endl;
						hospital.diagnosePatient(illness,hospital.search(name,false));
						break;
					}
					case 'f':
					{
						system("cls");
						double sum;
						cout<<"Enter received sum: ";
						cin>>sum;
						cout<<endl;
						hospital.receiveFunding(sum);
						break;
					}
					case 'l':
					{
						system("cls");
						hospital.paySalary();
						cout<<"You have paid salary"<<endl;
						_getch();
						break;
					}
	}

	}
	hospital.startWrite();
	return 0;
}