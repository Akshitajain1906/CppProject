#include<iostream>
#include<fstream>
using namespace std;
class Student{
	char Name[20],grade;
	int rollno,ID,check;
	float eng,math,phys,chem,eco,ip,percent;	
	public:
	void calculate()
    {
        percent=(eng+math+phys+chem+eco+ip+eco)/5.0;
        if(percent>=90)
            grade='A';
        else if(percent>=80 && percent<70)
            grade='B';
        else if(percent>=60 && percent<50)
            grade='C';
        else
            grade='F';
    }
    void get()
    {
        cout<<"\nEnter The roll number of student ";
        cin>>rollno;
        cout<<"\n\nEnter The Name of student ";
        cin>>Name;
        cout<<"\nEnter The marks in physics out of 100 : ";
        cin>>phys;
        cout<<"\nEnter The marks in chemistry out of 100 : ";
        cin>>chem;
        cout<<"\nEnter The marks in maths out of 100 : ";
        cin>>math;
        cout<<"\nEnter The marks in english out of 100 : ";
        cin>>eng;
        cout<<"\nSelect your extra subject \t1:Informatics Practices \t2:Economics: ";
        cin>>check;
        if(check==1)
		{
        	cout<<"\nEnter The marks in Informatics Practice out of 100 : ";
        	cin>>ip;
        	eco=0;
		}
        else
        {
        	cout<<"\nEnter The marks in Economics out of 100 : ";
        	cin>>eco;
        	ip=0;
		}
        calculate();
    }
    void show()
    {
    	cout<<"\nRoll number of student : "<<rollno;
        cout<<"\nName of student : "<<Name;
        cout<<"\nMarks in Physics : "<<phys;
        cout<<"\nMarks in Chemistry : "<<chem;
        cout<<"\nMarks in Maths : "<<math;
        cout<<"\nMarks in English : "<<eng;
        if(check==1)
        cout<<"\nMarks in Informatics Practices : "<<ip;
        else
        cout<<"\nMarks in Economics : "<<eco;
        cout<<"\nPercentage of student is  :"<<percent;
        cout<<"\nGrade of student is :"<<grade;
	}
	int roll()
	{
		return rollno;
	}
};
fstream fp;
Student s;
void write()
{
	fp.open("C://Users//HP//Desktop//student.data",ios::out);
	if (fp.is_open())
    {
		s.get();
    	fp.write((char*)&s,sizeof(Student));
    }
    else
    {
        std::cerr << "didn't write" << std::endl;
    }

    fp.close();
    cout<<"\n\nStudent record Has Been Created ";
}
void read()
{
	fp.open("C://Users//HP//Desktop//student.data",ios::in|ios::binary);
	if(!fp)
	{
		cout<<"file not found";
	}
	else
	{
		fp.read((char*)&s,sizeof(s));
		while(!fp.eof())
		{
			fp.read((char*)&s,sizeof(s));
			s.show();
			cout<<"\n\n====================================\n";
		}
	}
//    while(fp.read((char*)&s,sizeof(Student)))
//    {
//
//        //fp.read((char*)&s,sizeof(s));
//        s.show();
//        cout<<"\n\n====================================\n";
//    }
//    cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
//    cout<<"====================================================\n";
//    cout<<"Roll No. Name          P  C  M  E  CS  %age Grade\n";
//    cout<<"====================================================\n";

    fp.close();
}
void display_sp(int n)
{
    int flag=0;
    fp.open("C://Users//HP//Desktop//student.data",ios::in);
    while(fp.read((char*)&s,sizeof(Student)))
    {
        if(s.roll()==n)
        {
            s.show();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
        cout<<"\n\nRecord does not exist";
}
int main()
{
	int flag,n;
	do{
	cout<<"\n\n\tSelect from following:-\n";
    cout<<"\n\n\t1:CREATE STUDENT RECORD";
    cout<<"\n\n\t2:DISPLAY RECORDS";
    cout<<"\n\n\t3:DISPLAY SPECIFIC STUDENT RECORD";
    cout<<"\n\n\t0:EXIT \n\n\t";
    cin>>flag;
    switch(flag)
    {
    	case 1:write();
    			break;
    	case 2:read();
    			break;
    	case 3:cout<<"\nEnter roll num of student: ";
    		cin>>n;
			display_sp(n);
			
	}
	cout<<"\n\n\tThanks";
} while(flag!=0);
	return 0;
}
