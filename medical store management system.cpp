#include <iostream>
 #include <string>
 #include <fstream>
 #include <cstdlib>
 #include<iomanip>
 #include <cstring>
 using namespace std;
 class MedStore { 

  string name;  
 string exdate;
 int price;
 
 public:
 	 MedStore(string n, string d, int p );
   
    void Add();
 	void Insert();
 	void Update();
 	void Display();
 	void Delete();
 	
 		void WriteToFile()
	{
		ofstream f1("MedStore.txt",ios::app); 
		f1<<name<<setw(20)<<exdate<<setw(18)<<price<<setw(20)<< endl;
		f1.close();	
	}
 	
 };
 
   MedStore:: MedStore(string n, string d, int p){
    name=n;
    exdate=d;
    price=p;
    
    
    
}

void MedStore::Add(){
	cout<< "\t Enter the name of the medicine :"<<endl;
	cin>>name;
    cout<< "\t Enter the expiry date of the medicine :"<<endl;
    cin>>exdate;
    cout<< "\t Enter the price of the medicine in (Rs) :"<<endl;
    cin>>price;
	
	WriteToFile();
}

void MedStore::Update()
{
	cout << endl << endl << endl;
             	cout << "\t\t\t\t****************************************" << endl;
				cout << "\t\t\t\t       Update the Price          "     << endl;
				cout << "\t\t\t\t****************************************" << endl;
	
	
	string name;
	int price;
	cout<<"\tEnter the name of the medicine to be updated :"<<endl;
	cin>>name;
	cout<<"\tEnter the new price of the medicine :"<<endl;
	cin>>price;
     cout << "\t\t\t Successfully updated !!!!"<<endl;
    
	ifstream f1("MedStore.txt");
	ofstream f2("temp.txt");
	string line;
	while(getline(f1,line))
	{
		if(line.find(name)==string::npos)
		{
			f2<<line<<endl;
		}
		else
		{
			f2<<name<<setw(20)<<exdate<<setw(18)<<price<<setw(20)<< endl;
		}
	}
	f1.close();
	f2.close();
	remove("MedStore.txt");
	rename("temp.txt","MedStore.txt");
}
	

void MedStore::Insert(){
	    	
    cout << endl << endl << endl;
	            cout << "\n\n\t\t\t\t\t*************************************************************" << endl;
	            cout << "\t\t\t\t\t\t       Insert the AmountPaid and Change         " << endl;
	            cout << "\t\t\t\t\t*****************************************************************" << endl;	
    string name, exdate;
	int amt, price, change;
	
	cout<<"\tEnter the Name of the medicine in :"<<endl;
	cin>>name;
	cout<<"\tEnter the Expiry date of the medicine in (Rs) :"<<endl;
	cin>>exdate;
	cout<<"\tEnter the Price of the medicine in (Rs) :"<<endl;
	cin>>price;
	cout<<"\tEnter the Amount Paid by the customer in (Rs) :"<<endl;
	cin>>amt;
	change=amt-price;
	cout<<"The change to be returned of the medicine in (Rs) :"<<change<<endl;
	cout << " \t\t\t\t\t The AmountPaid and Change is successfully Inserded in the  Display bill!!!! \t\t\t\\t  "<<endl;
	

	ifstream f1("MedStore.txt");
	ofstream f2("temp.txt");
	string line;
	while(getline(f1,line))
	{
		if(line.find(name)==string::npos)
		{
			f2<<line<<endl;
		}
		else
		{
			f2<<name<<setw(20)<<exdate<<setw(18)<<price<<setw(20)<<amt<<setw(20)<<change<<setw(20)<< endl;
		}
	}
	f1.close();
	f2.close();
	remove("MedStore.txt");
	rename("temp.txt","MedStore.txt");
	
    	
}


void MedStore::Display(){
	            cout << endl << endl << endl;
             	cout << "\t\t\t\t****************************************" << endl;
				cout << "\t\t\t\t       Display          "     << endl;
				cout << "\t\t\t\t****************************************" << endl;
		string line;
		fstream f1 ("MedStore.txt");
		if (f1.is_open()){    
			cout<<"\n\n\t\t\t\t\t Medicine list \n\n";
			cout<<"============================================================================================\n";
			cout<<" Name          Expiry date              Price            AmountInserted       Change       \n";   
			cout<<"============================================================================================\n";
			while ( getline (f1,line) ){
				  cout<< line << '\n'   ;	}
			f1.close();}
		else{
			cout << "Error!!!!! Unable to open file"; } 	
	}

void MedStore::Delete(){
	
	cout << endl << endl << endl;
	cout << "\n\n\t\t\t\t\t*********************************" << endl;
	cout << "\t\t\t\t\t\t       Delete all records         " << endl;
	cout << "\t\t\t\t\t*************************************" << endl;
	int g;
		cout<<"\n\tAre you sure you want to proceed? \n\tIf yes, then press 1 to delete all records, if no, press 1: ";
		
			cin >> g;
			
		if (g == 1){
			cout<<"\n\tAll records successfully deleted!";
			ofstream f1("MedStore.txt",ios::trunc);
	    	f1.close();	}
		else {
			int main();}
    
}

int main()
{
	string n;
	string d;
	int p;

	class MedStore M1("n", "d", p);


char choice;
	do{
		system("cls");
		cout << endl << endl << endl;
		cout << "\t\t\t\t\t   Pharmacutical store    " << endl;
		cout << endl << endl << endl;
		cout << "\t\t\t\t\t******************************" << endl;
		cout << "\t\t\t\t\t         MAIN MENU         " << endl;
		cout << "\t\t\t\t\t******************************" << endl;
		cout << "\t\t\t\t\t     1 -- Add	" << endl;
		cout << "\t\t\t\t\t     2 -- Insert" << endl;
		cout << "\t\t\t\t\t     3 -- Update" << endl;
		cout << "\t\t\t\t\t     4 -- Display" << endl;
		cout << "\t\t\t\t\t     5 -- Delete" << endl;
		cout << "\t\t\t\t\t     6 -- Exit" << endl;
		cout << endl << "\t\t\t\t\tEnter your selection(1-5): ";
	    cin>> choice;		
		system("cls");
		switch(choice)
		{
			case '1':
				cout << endl << endl << endl;
				cout << "\n\n\t\t\t\t\t*********************************" << endl;
	            cout << "\t\t\t\t\t\t       Add medicine details         " << endl;
	            cout << "\t\t\t\t\t*************************************" << endl;
				int n1;
				cout<<"\n\tHow many medicine do you want to add? ";
					cin>>n1;
					for(int i; i<n1 ; i++){
					cout<<"Enter medicine  "<<i+1<<" details"<<endl;
					Add();}
				break;
			case '2':
			        M1.Insert();
			    break;
			case '3':
			M1.Update();
				break;
			case '4':
			   M1.Display();
			   break;
			case '5':
				M1.Delete();
				break;
		
			case '6':
				cout<<"\n\n\n\n\n\n\n\n\t\t\t\t You have successfully completed the task";
				break;
			default :cout<<"\a";	
		}
		cin.ignore();
		cin.get();
	}
	while(choice!='6');
	return 0;
}

 

