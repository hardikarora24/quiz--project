#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
#include<string.h>
using namespace std;
void spc(int x, int y)
{
    for(int i=0; i<x; i++)
	cout<<"\n";
    for(int i=0; i<y; i++)
	cout<<"\t";
}
void FrPG()
{
    system("cls");
    void StPG();
    void TePG();
    ifstream samosa;
    samosa.open("dth");
    while(!samosa.eof())
        {
        char a;
        samosa.get(a);
        cout << a;
        }
    samosa.close();
    Sleep(4000);
    system("cls");
    cout<<"LOGIN AS :\n";
    cout<<"1.STUDENT\n";
    cout<<"2.TEACHER\n";
  A:
    cout<<"Enter choice(1/2):";
    int x;
    cin>>x;
    if(x==1)
        StPG();
    else if(x==2)
        TePG();
    else
    {
	    cout<<"Wrong Choice";
	    goto A;
    }
}
void TePG()
{
    int r;
    system("cls");
    int TSI();
    void TSU();
    void showst1(int);
    void entQ();
    cout<<"1.Existing Member\n";
    cout<<"2.New Member\n";
    cout<<"3.GO BACK!!\n";
    cout<<"Enter Your Choice(1/2/3):";
    int x;
    cin>>x;
    if(x==1)
        r=TSI();
    else if(x==2)
    {
		TSU();
		cout<<"REDIRECTING TO LOGIN PAGE.....\n";
		Sleep(1000);
		system("cls");
		r=TSI();
    }
    else
	FrPG();
	char ans='n';
  B:
    cout<<"1.Add Question Paper\n";
    cout<<"2.Check Class report\n";
    cout<<"3.Exit Program\n\n";
    cout<<"Enter Choice(1/2/3):";
    cin>>x;
    switch(x)
    {
        case 1: entQ();
                getch();
                goto B;
                break;
        case 2: showst1(r);
                getch();
                goto B;
                break;
        case 3: system("cls");
                cout<<"Are you sure you want to quit?(y/n)";
                cin>>ans;
                if(ans=='y')
                    exit(0);
                else
                    goto B;
                break;
        default:cout<<"Wrong Choice!!";
                goto B;
    }
}
void StPG()
{
    system("cls");
    void Stulinkertta();
    Stulinkertta();
    int SSI();
    void SSU();
    void showst2(int);
    int SlctPpr();
    void modrk(int, int);
    int putQ(int);
    cout<<"1.Existing Student\n";
    cout<<"2.New Student\n";
    cout<<"3.GO BACK!!\n";
    cout<<"Enter Your Choice(1/2/3):\n";
    int x;
    cin>>x;
    int r;
    if(x==1)
     {
         r=SSI();
         Sleep(1000);
     }
    else if(x==2)
    {
         SSU();
         cout<<"Redirecting You to Login Page.......";
         Sleep(1000);
         r=SSI();
         Sleep(1000);
    }
    else
	FrPG();
  C:
	cout<<"1.Attempt Papers\n";
	cout<<"2.Check your Progress\n";
	cout<<"3.Exit\n\n";
	cout<<"Enter your Choice(1/2/3):";
	cin>>x;
	char ans='n';
	int t, s;
	switch(x)
	{
        case 1: system("cls");
                t=SlctPpr();
                s=putQ(t);
                modrk(s, r);
                getch();
                goto C;
                break;
        case 2: system("cls");
                showst2(r);
                getch();
                goto C;
                break;
        case 3: system("cls");
                cout<<"Are you sure you want to Quit?(y/n):";
                cin>>ans;
                if(ans=='y')
                    exit(0);
                else
                    goto C;
                break;
        default:cout<<"Wrong Choice!!";
                goto C;
	}


}
int stucount = 0;
void Stulinkeratt();
char studentid[10][20] ;
void idlink();
class Stu
{
	private:
		int rno;
		char name[20];
		int cls, com;
		char sec, tsec;
        int marks[10];
        int flmr[10];
	public:
	    Stu()
	    {
	        for(int i=0; i<10; i++)
            {
                marks[i]=0;
                flmr[i]=0;
            }
	    }
	    int mrrt(int x)
	    {
	        return (flmr[x-1]);
	    }
		char stuid[20];
		char stupass[20];
		int gtcom()
		{
		    return(com);
		}
		void show()
		{
		    puts(name);
		}
		void GETS()
		{
			fflush(stdin);
			cout<<"Enter Name: ";
			gets(name);
			cout<<"Enter Roll No.: ";
			cin>>rno;
			cout<<"Enter Class: ";
			cin>>cls;
			cout<<"Enter Section: ";
			cin>>tsec;
			sec=toupper(tsec);
			com=(rno*10000)+(cls*100)+sec-65;
		}
		void PUTS()
		{
		    cout<<"\n";
			cout<<"Roll no: "<<rno;
			cout<<"\nName: ";
			puts(name);
			cout<<"Marks:\n";
			int flg=0;
			for(int i=0; i<10; i++)
            {
                if(flmr[i]==1)
                 {
                     cout<<"Paper "<<i+1<<":"<<marks[i]<<"/40\n";
                     flg=1;
                 }
            }
            if(flg==0)
                cout<<"No Paper Attempted!";
        }
		void mrkmod(int x, int y)
		{
		    marks[y-1]=x;
		    flmr[y-1]=1;
		}
		int getcls(){ return(cls); }
		char getsec(){ return(sec); }


}stud[10];
Stu s ;
void idlink()
{
	  for(int k = 0; k <= stucount ;k++)
	  strcpy(studentid[k],stud[k].stuid);
}
void SSU()
{
            system("cls");
			stud[stucount].GETS() ;
			int fl=0; int k = 0 ; int n ;
			do
			{
			    n = 0 ;
                fflush(stdin);
				cout<<"Create User id(atleast one of @,#): ";
				gets(stud[stucount].stuid);
				int x=0;
				for(int i=0; i<25; i++)
				{

					if(stud[stucount].stuid[i]=='@' ||stud[stucount].stuid[i]=='#')
                        x++;
				}
				fl=x;
				for( int i = 0; i < stucount ; i++)
				{
					if(strcmp(stud[i].stuid,stud[stucount].stuid) == 0)
					{
						cout << "Sorry username already taken, please choose another" << endl ;
						fl = 0 ;
						n = -1;
					}
				}
				if(fl==0 && n==0)
					cout<<"Wrong Input Type!\n";

			}while(fl==0);

			do
			{
			    fl = 0 ;
				cout<<"Create Password(no special character allowed): ";
				gets(stud[stucount].stupass);
				while(stud[stucount].stupass[k] != '\0')
                {	if(!isalnum(stud[stucount].stupass[k]))
                        fl++;
                    k++ ;
                }
                if (k ==0) {fl = -1;}
                if (fl!=0)
                    cout<<"Wrong Input Type!\n";
			}while(fl!=0);
			stucount++ ;
			idlink() ;
			Stulinkeratt();
		}
int SSI()
{
    system("cls");
	char Sid[20] , Spass[20] ;
	int t ; int p = -1;
	do
    {
        fflush(stdin);
        cout<<"Enter User-Id:";
	    gets(Sid);
	    cout<<"Enter Password:";
	    gets(Spass);
        for( t = 0 ; t <= stucount ; t++)
	    {
            if(strcmp(stud[t].stuid,Sid)==0)
		    {
		        p=0;
                break;
		    }
	    }
	    if(p == 0)
	    {
            if(strcmp(stud[t].stupass, Spass)==0)
                p = 0;
            else
                p = -1;
	    }
        if (p == -1 )
            cout << "Invalid username or password"<< endl  ;
    } while( p != 0);
    cout<<"LoginSuccessful";
    Sleep(1000);
    system("cls");
    cout<<"Welcome ";stud[t].show();
	return stud[t].gtcom() ;
 }
void Stulinkeratt()
{
	ofstream fin ;
	fin.open("temp.txt", ios::app);
	for(int b = 0 ; b < stucount ; b++)
		fin.write((char*)&stud[b],sizeof(s));
	fin.close();
	remove("stud.txt");
	rename("temp.txt","stud.txt");
}
void Stulinkertta()
{
	fstream fo("stud.txt",ios::in |ios::app);
	while(!fo.eof() && stucount<10)
	{
	    fo.read((char*)&stud[stucount],sizeof(s));
		stucount++;
	}
	stucount--;
	fo.close();
}
void showst1(int x)
{
    Stu s1;
    int i=0, flg=0;
    fstream f;
    f.open("stud.txt", ios::in);
    while(i<=stucount )
    {
        f.read((char*)&s1, sizeof(s1));
        if(x==(s1.gtcom()%10000))
        {
                flg=1;
                s1.PUTS();
        }
        i++;
    }
    if(flg==0)
        cout<<"No Students of your class present";
}
void showst2(int x)
{
    Stu s1;
    int i=0;
    fstream f;
    f.open("stud.txt", ios::in);
    while(i<=stucount )
    {
        f.read((char*)&s1, sizeof(s1));
        if(x==(s1.gtcom()))
        {   s1.PUTS();break;}
        i++;
    }
}
class ClsT
{
		char cTid[25], Tid[25];
		char cTpass[25], Tpass[25];
		char namet[45];
		int cls, com;
		char sec, tsec;
public:
    int gtcom()
    {
        return com;
    }
	char* gtctid()
	{
	    char *pt;
	    pt=cTid;
	    return pt;
	}
	char* gtctpass()
	{

	    char *pt;
	    pt=cTpass;
	    return pt;
	}
	char* gttpass()
	{
	    char *pt;
	    pt=Tpass;
	    return pt;
	}
	char* gttid()
	{
	    char *pt;
	    pt=Tid;
	    return pt;
	}
	void SignUp()
		{
		    fflush(stdin);
			cout<<"Enter name:";
			gets(namet);
            cout<<"Create User id: ";
            gets(cTid);
            cout<<"Create Password: ";
            gets(cTpass);
            cout<<"Enter Class: ";
            cin>>cls;
            cout<<"Enter Section: ";
            cin>>tsec;
            sec=toupper(tsec);
            com=(cls*100)+sec-65;

		}
		int SignIn()
		{
		    fflush(stdin);
			cout<<"Enter User-Id:";
            gets(Tid);
			cout<<"Enter Password:";
			gets(Tpass);

		}
	    void show()
	    {
            puts(namet);
	    }
};

class Q
{
	private:
		int crans, ans;
		char Opt[4][50];
		char ques[100];


	public:
	    char Qpnm[25];
	    Q()
	    {
	        strcpy(Qpnm,"<Empty>");
	    }
	    void pQnm()
	    {
	        fflush(stdin);
	        cout<<"Paper name: ";
	        gets(Qpnm);
	    }
		void GETQ()
		{
		    fflush(stdin);
			cout<<"\n";
			cout<<"Enter Ques: ";
			gets(ques);
			for(int i=0; i<4; i++)
			{
				cout<<"\nEnter Opt "<<i+1<<" :";
				gets(Opt[i]);
			}
			cout<<"\nEnter the correct Option(1/2/3/4):";
			cin>>crans;
		}
		int PUTQ()
		{
			int m2=0;
			cout<<"\n";
			puts(ques);
			cout<<"\n";
			for(int i=0; i<4; i++)
			{
				cout<<i+1<<". ";
				puts(Opt[i]);
				cout<<"\n";
			}
			cout<<"\n Enter Your Answer:(1/2/3/4)(0 for Skipping)";
			cin>>ans;
			if(ans==1||ans==2||ans==3||ans==4)
			{
				if(ans==crans)
					m2=4;
				else
					m2=-1;
			}
			return(m2);
		}

};
Q Qt[10];
int SlctPpr()
{
    ifstream f;
    f.open("Qbank.txt", ios::in);
    Q q;
    int j=0, x=0, p;
    while(j<100)
    {
        f.read((char*)&q, sizeof(q));
       if(strcmp(q.Qpnm,"<Empty>")!=0)
        {
            x++;
            cout<<x<<". ";puts(q.Qpnm);
        }
        j++;
    }
    cout<<"\nEnter your Choice:(1-10)";
    cin>>p;
    f.close();
    return p;
}
void modrk(int x,int y)
{
    int m, p, j,i=0;
    m=(x/100);
    p=(x%100);
    j=(p*100)-m;
    Stu s1;
    fstream f, ft;

    f.open("stud.txt",ios::in);
    ft.open("temp.txt", ios::app);
    while(!f.eof() && i<25)
    {
        f.read((char*)&s1, sizeof(s1));
        if(y==s1.gtcom())
            s1.mrkmod(j, p);
        ft.write((char*)&s1, sizeof(s1));
        i++;
    }
    ft.close();
    f.close();
    remove("stud.txt");
    rename("temp.txt", "stud.txt");
}
void TSU()
{
    system("cls");
	ClsT T;
	char *pT, *pt, Tc[25], tc[25];
	int flg=0, x=0;
	fstream f;
	f.open("Teacher.txt", ios::in);
	do
	{
	    flg=0;x=0;
	    cout<<"\n";
	    T.SignUp();
	    pT=T.gtctid();
	    for(int i=0; i<25;i++)
		Tc[i]=*(pT+i);
	    f.seekg(0);
	    while(!f.eof() && x<14600)
	    {
		   ClsT t;
		   f.close();
		   f.open("Teacher.txt", ios::in);
		   f.seekg(x);
		   f.read((char*)&t, sizeof(t));
		   if(f.tellg()<0)
			break;
		   f.close();
		   f.open("Teacher.txt", ios::in);
		   x+=sizeof(t);
		   f.seekg(x);
		   pt=t.gtctid();
		   for(int i=0; i<25;i++)
			tc[i]=*(pt+i);
		   if(strcmp(Tc,tc)==0)
		   {
			flg=1;
			cout<<"Already taken!!";
			break;
		   }
		}
	}while(flg==1);
	f.close();
	f.open("Teacher.txt", ios::app);
	fflush(stdin);
	f.write((char*)&T, sizeof(T));
	cout<<"\n\tAccount added!\n";
	f.close();
}
int TSI()
{
    system("cls");
    ClsT T;
    int flg=0, x=0;
    char *pfi, *pfp, *pep, *pei;
    char fp[25], fi[25], ei[25], ep[25];
    fstream f;
    do
    {
	x=0;
	T.SignIn();
	pfi=T.gttid();
	pfp=T.gttpass();
	f.open("Teacher.txt", ios::in);
	for(int i=0; i<25; i++)
	{
	    fp[i]=*(pfp+i);
	    fi[i]=*(pfi+i);
	}
	while(!f.eof() && x<1480)
	{
	    ClsT t;
	    f.close();
	    f.open("Teacher.txt", ios::in);
	    f.seekg(x);
	    f.read((char*)&t, sizeof(t));
	    if(f.tellg()<0)
		break;
	    f.close();
	    f.open("Teacher.txt", ios::in);
	    x+=sizeof(t);
	    f.seekg(x);
	    pei=t.gtctid();
	    pep=t.gtctpass();
	    for(int i=0; i<25;i++)
	    {
            ei[i]=*(pei+i);
            ep[i]=*(pep+i);
	    }
        if(strcmp(ep,fp)==0)
		flg=1;
	    if(strcmp(ei,fi)==0 && flg==1)
	    {
	        cout<<"\nLoginSuccessful";
	        Sleep(1000);
	        system("cls");
            cout<<"Welcome ";t.show();
            Sleep(1000);
            return (t.gtcom());
	    }
	    else
            flg=0;

	}
	cout<<"Entered Username or/and Password are wrong!!\n";
	f.close();
    }while(flg==0);

}
void entQ()
{
	ofstream f;
	f.open("Qbank.txt", ios::app);
	for(int i=0;i<10;i++)
	{
          system("cls");
          if(i==0)
                Qt[i].pQnm();
		  cout<<"Qno."<<i+1<<":\n";
		  Qt[i].GETQ();
          f.write((char*)&Qt[i], sizeof(Qt[i]));

	}

	cout<<"\nInput Successful!!\n";
	f.close();
}
int putQ(int x)
{
	int m1=0, pl, i=0, j=0;
	Q q;
	ifstream f;
	f.open("Qbank.txt", ios::in);
	while(!f.eof() && j<100)
    {
        pl=f.tellg();
        f.read((char*)&q, sizeof(q));
        if(strcmp(q.Qpnm,"<Empty>")!=0)
            i++;
        if(i==x)
            break;
        j++;
    }
    f.seekg(pl);
	for( int i=0;i<10;i++)
	{
	    cout<<"Qno."<<i+1<<":\n";

        f.read((char*)&Qt[i],sizeof(Qt[i]));
		m1+=Qt[i].PUTQ();
		system("cls");
	}
    cout<<"We hope your paper went well!!!";
    Sleep(1000);
	f.close();
	int o, g;
	g=(x*100)-m1;
	o=(g*100)+x;
	getch();
	return(o);
}
int main()
{
    system("cls");
    cout<<"WELCOME TO <NAME>\n";
    cout<<"Loading....";
    Sleep(1);
    FrPG();
    getch();
    return 0;
}
