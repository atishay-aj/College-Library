#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class book
{
	int bookno;
	char bookname[10],issue[3];
	public:
	void add()
	{
		printf("\nBook no ");
		scanf("%d",&bookno);
		printf("Book name ");
		scanf("%s",bookname);
		strcpy(issue,"no");
	
	}
	void show()
	{
		printf("\nbook no %d",bookno);
		printf("\nbookname %s",bookname);
		printf("\nissue : %s",issue);
		printf("\n---------------");
	}
	int getbook()
	{
		return bookno;
	}
	char* getissue()
	{
		return issue;
	}
};
class member
{
	int mno,no;
	char mname[10];
	public:
		void add()
		{
			printf("\nMember no ");
			scanf("%d",&mno);
			printf("Member name ");
			scanf("%s",&mname);
			no=0;
	
		}
		void show()
		{
			printf("\nmember no %d",mno);
			printf("\nmember name %s",mname);
			printf("\n book issued: %d",no);
			printf("\n------------------");
		}
		int getmem()
		{
			return mno;
		}
		int getno()
		{
			return no;
		}
		void increment()
		{
			no++;
		}
		void decrement()
		{
			no--;
		}
};
class issue
{
	int mno,bno;
	public:
		void add_issue()
		{
			printf("\nMember no ");
			scanf("%d",&mno);
		}
		void add_bno()
		{
			printf("Book no ");
			scanf("%d",&bno);
		}
		int getmem()
		{
			return mno;
		}
		int getbook()
		{
			return bno;
		}
};
void addbook()
{
	int a;
	do
	{
		cout<<"---------------------";
		cout<<"\n-------------------BOOK SECTION----------------------";
	cout<<"\n1.Add book";
	cout<<"\n---------------";
	cout<<"\n2.book data";
	cout<<"\n---------------";
	cout<<"\n3.Search book ";
	cout<<"\n---------------";
	cout<<"\n4.issue a book";
	cout<<"\n---------------";
	cout<<"\n5.Return a book";
	cout<<"\n---------------";
	cout<<"\n6.return to main menu";
	cout<<"\n---------------";
	cout<<"\nEnter your choice:";
		cin>>a;
	
	if(a==1)
	{
	 book b1;
	char ch;
	ofstream fp1("add_book",ios::app);
	do{
		b1.add();
	fp1.write((char *)&b1,sizeof(b1));
	printf("\nNew book added\n");
	fflush(stdin);
	printf("\nDo you want to add more(y/n)");
	printf("\n-------------------------------");
	scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
	fp1.close();
	}
	else if(a==2)
	{
	ifstream fp1("add_book");
	if(fp1==NULL)
	printf("No data found");
	else
	{ book b1;
	fp1.read((char *)&b1,sizeof(b1));
	while(fp1)
	{
		b1.show();
		fp1.read((char *)&b1,sizeof(b1));		
	}
	fp1.close();
	}
	}
	else if(a==3)
	{
		int no,count;
		book b1;
		ifstream fp1("add_book");
		printf("\nBook no ");
		scanf("%d",&no);
		fp1.read((char *)&b1,sizeof(b1));
		while(fp1)
		{
			if(b1.getbook()==no)
			{
				printf("\nBook found");
				b1.show();
				printf("\n---------------");
				count++;
			}
			fp1.read((char *)&b1,sizeof(b1));
		}
		if(count==0)
		printf("Book not found");
		fp1.close();
		
	}
	else if(a==4)
	{
		void issuebook();
		issuebook();
	}
	else if(a==5)
	{
		void recieve();
		recieve();
	}
	}while(a!=6);
}
void addmem()
{
	int a;
	do{
		cout<<"\n--------------------";
	cout<<"------------------------MEMBER SECTION------------------------";
	cout<<"\n1.Add Member";
	cout<<"\n---------------";
	cout<<"\n2.member data";
	cout<<"\n---------------";
	cout<<"\n3.Search member";
	cout<<"\n---------------";
	cout<<"\n4.Return to main menu";
	cout<<"\n---------------";
	cout<<"\nEnter your choice: ";
		cin>>a;
	
	if(a==1)
	{
	 member m1;
	 char ch;
	ofstream fp2("add_mem",ios::app);
	do
	{
		m1.add();
	fp2.write((char *)&m1,sizeof(m1));
	printf("\nNew member added\n");
	fflush(stdin);
	printf("\nDo you want to add more(y/n)");
	scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	fp2.close();
	}
	else if(a==2)
	{ member m1;	
	ifstream fp2("add_mem");
	if(fp2==NULL)
	printf("\nNo data found");
	else
	{
		fp2.read((char *)&m1,sizeof(m1));
	while(fp2)
	{
		m1.show();
		fp2.read((char *)&m1,sizeof(m1));
	}
	fp2.close();
	}
		
	}
	else if(a==3)
	{
		int no,count;
		member m1;
		ifstream fp2("add_mem");
		printf("\nmember no ");
		scanf("%d",&no);
		fp2.read((char *)&m1,sizeof(m1));
		while(fp2)
		{
			if(m1.getmem()==no)
			{
				m1.show();
				count++;
			}
			fp2.read((char *)&m1,sizeof(m1));
		}
		if(count==0)
		printf("\nMember not found");
		fp2.close();
	}
	}while(a!=4);
}
void issuebook()
{
	
	int count=0,cnt=0;
	ofstream fp3("issue_book",ios::app);
	fstream fp1("add_book",ios::in | ios::out);
	fstream fp2("add_mem",ios::in | ios::out);
	 issue i1;
	 book b1;
     member m1;
	i1.add_issue();
	fp2.read((char *)&m1,sizeof(m1));
	while(fp2)
	{ if(m1.getmem()==i1.getmem())
	{ if(m1.getno()<=4) 
	{
	i1.add_bno();
	fp1.read((char *)&b1,sizeof(b1));
	while(fp1)
	{
	  if(b1.getbook()==i1.getbook())
	  {
	  	if(strcmp(b1.getissue(),"no")==0)
	  	{
	  		fp1.seekp(-sizeof(b1),ios::cur);
		  	strcpy(b1.getissue(),"yes");
			fp1.write((char *)&b1,sizeof(b1));
		  	fp3.write((char *)&i1,sizeof(i1));
			printf("\n Book issued");
			printf("\n-----------------");
			 fp2.seekp(-sizeof(m1),ios::cur);
			 m1.increment();
			 fp2.write((char *)&m1,sizeof(m1));
			
		  }
		  else
		  printf("\nBook already issue");
		  cnt++;
	  }
	  fp1.read((char *)&b1,sizeof(b1));
	  
	}
	cnt++;
    }
    if(cnt==0)
    printf("\nOver limit");
	count++;
	if(cnt==1)
	printf("\nBook not found");
    }
    fp2.read((char *)&m1,sizeof(m1));
	}
	if(count==0)
	printf("\nMember not found");
	
	fp1.close();
	fp2.close();
	fp3.close();
}
void issuedata()
{
	
	 issue i1;
	ifstream fp3("issue_book");
	
	fp3.read((char *)&i1,sizeof(i1));
	while(fp3)
	{
		printf("\nMember no %d ",i1.getmem());
		printf("\nBook no %d ",i1.getbook());
		printf("\n-----------------");
		fp3.read((char *)&i1,sizeof(i1));
	}
}
void recieve()
{
	issue i1;
	book b1;
	member m1;
	ifstream fp3("issue_book");
	ofstream fp4("issue_temp");
	fstream fp1("add_book",ios::in | ios::out);
	fstream fp2("add_mem",ios::in | ios::out);
	int bno;
	cout<<"\nEnter book no to return:";
	cin>>bno;
	fp1.read((char *)&b1,sizeof(b1));
	while(fp1)
	{
		if(b1.getbook()==bno)
		{
		fp1.seekp(-sizeof(b1),ios::cur);
		strcpy(b1.getissue(),"no");
		fp1.write((char *)&b1,sizeof(b1));
	    }
		fp1.read((char *)&b1,sizeof(b1));
	}
	fp3.read((char *)&i1,sizeof(i1));
	while(fp3)
	{
		if(bno!=i1.getbook())
		{
			fp4.write((char *)&i1,sizeof(i1));
		}
		if(bno==i1.getbook())
		{
			fp2.read((char *)&m1,sizeof(m1));
			while(fp2)
			{
				if(i1.getmem()==m1.getmem())
				{
					fp2.seekp(-sizeof(m1),ios::cur);
					m1.decrement();
					fp2.write((char *)&m1,sizeof(m1));
				}
				fp2.read((char *)&m1,sizeof(m1));
			}
		}
		fp3.read((char *)&i1,sizeof(i1));
	}
	cout<<"\nBook Returned Successfully";
	fp3.close();
	fp4.close();
	fp1.close();
	fp2.close();
	remove("issue_book");
	rename("issue_temp","issue_book");
}
int main()
{
	printf("\t\t\tWELCOME TO LIBRARY MANAGEMENT");
	printf("\n________________________________________________________________________________");
	int a;
	do
	{
		cout<<"\n\n__________________MAIN MENU___________________";
		printf("\n\n\t1.Book portion");
		printf("   2.Member portion");
		cout<<"\n";
		printf("\n\t3.issue data");
		printf("     4.Exit");
		cout<<"\n___________________";
		printf("\nEnter your choice ");
		scanf("%d",&a);
		if(a==1)
		addbook();
		else if(a==2)
		addmem();
		else if(a==3)
		issuedata();
		else if(a<1||a>4)
		{printf("wrong choice");
		break;}
	}while(a!=4);
	if(a==4)
	printf("\n\n\t\tThank you");
}

