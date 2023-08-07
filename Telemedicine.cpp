#include<iostream>
#include<string>
#include<ctime>
using namespace std;
int i=0,j=0,hour=8;
class patient{
    string name;
    int id;
    int age;
    string email;
    string disease;
    friend class database;
public:
};
class doctor{
    string name;
    string speciality;
    friend class database;
public:
};
class database{
    doctor d[5];
    patient p[50];
    friend class patient;
public:
    void add_doctor(){
        cout<<"Enter name\n";
        cin>>d[i].name;
        cout<<"Enter speciality\n";
        cin>>d[i].speciality; i++;
    }
    void add_patient(){
        cout<<"Enter name: \n";
        cin>>p[j].name;
        cout<<"Enter id: \n";
        cin>>p[j].id;
        cout<<"Enter age: \n";
        cin>>p[j].age;
        cout<<"Enter email: \n";
        cin>>p[j].email; 
        cout<<"Enter disease: \n";
        cin>>p[j].disease;      
        j++;
        cout<<"\nPatient added successfully"<<endl;
    }
    void display_doctors(){
        for(int k=0;k<i;k++){
            cout<<"Name of the doctor: "<<d[k].name;
            cout<<"\nSpeciality of the doctor: "<<d[k].speciality<<endl;
        }
    }
    void display_patients(){
        for(int k=0;k<j;k++){
            cout<<"Name of the patient: "<<p[k].name;
            cout<<"\nID of the patient: "<<p[k].id<<endl;
            cout<<"\nAge of the patient: "<<p[k].age<<endl;
            cout<<"\nEmail of the patient: "<<p[k].email<<endl;
            cout<<"\nDisease of the patient: "<<p[k].disease<<endl;
        }
    }
    void search_patient(int id){
    for(int k=0;k<j;k++){
        if(id==p[k].id){
            cout<<"Name of the patient: "<<p[k].name;
            cout<<"\nID of the patient: "<<p[k].id<<endl;
            cout<<"Age of the patient: "<<p[k].age<<endl;
            cout<<"Email of the patient: "<<p[k].email<<endl;
            cout<<"Disease of the patient: "<<p[k].disease<<endl;
        }
    }
}
};
    void time(){
        time_t now=time(NULL);
        tm* localTime=localtime(&now);
        mktime(localTime);
        cout<<"\nTime of booking your appointment "<<asctime(localTime);
        localTime->tm_mday+=1;
        cout<<"\nYour appointment date: ";
        cout<<localTime->tm_mday<<"/"<<localTime->tm_mon+1;
        cout<<"/"<<localTime->tm_year+1900<<endl;
        cout<<"Time of your appointment: "<<hour<<":00"<<endl;
        hour++;
        if(hour==20) hour=8;
    }
    void appointment(database d){
        string name; int id;
        cout<<"Which doctor you want to consult with?\n\n";
            d.display_doctors();
        cout<<"\nEnter name and ID(with spaces)\n";
            cin>>name>>id;
        cout<<"\nAppointment successfully booked to DR. "<<name<<endl;
        time();
    }

int main(){
    database d; int op; char c;
    do{
        cout<<" Telemedicine Service \n\n";
        cout<<"1. Add a patient\n";
        cout<<"2. Sign in as a doctor\n";
        cout<<"3. See the list of doctors\n";
        cout<<"4. Book appointment \n";
        cout<<"5. See the list of patients \n";
        cout<<"6. Search patient \n";
        cout<<"\nChoose any of them\n";
        cin>>op;
    switch(op){
        case 1:d.add_patient();
                break;
        case 2:d.add_doctor();
                break;
        case 3:d.display_doctors();
                break;
        case 4: appointment(d);
                break;
        case 5:d.display_patients();
                break;
        case 6: cout<<"\n Enter patient id: \n";
                int Id;cin>>Id;
                d.search_patient(Id);
                break;
        default: cout<<"Invalid choice\n";
                break;
    }
    cout<<"Do you wanna continue?(y/n)\n";cin>>c;
    }while(c=='y');
    return 0;
}