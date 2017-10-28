#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string reskeywords[24]={"CONST" , "FLOAT" , "INT" , 
		"BREAK" , "CONTINUE" , "ELSE" , "FOR" , "SWITCH" , "VOID" , "CASE" , "ENUM" , "SIZEOF" , "TYPEDEF" ,"CHAR" ,"DO" , "IF" , "RETURN" 
		, "UNION" , "WHILE", "UCP", "DEAN", "HOD", "and", "or"};
struct TokenA{
	char *typeof;
	char *name;
	int idfromSymbolTable;

};
struct symb{
	int id;
	char *name;
	char *type;

};
class symbolList
{
public:
	struct node{
		symb a;
		node *next;
	};
	node *head;
	int num;
	symbolList(){
	head=NULL;
	num=0;
	}
	

	void insertIntoHASH(symb a){
	num++;
	bool no=true;
	if(head==NULL){
		head=new node;
		head->a=a;
		head->next=NULL;
	}
	else
	{
		node *p=head;
		while(p->next!=NULL)
		{
			if(p->a.name=a.name){
				no=false;
			}
			p=p->next;
			
		}
		if(no)
		{
		p->next=new node;
		p->next->a=a;
		p->next->next=NULL;
		}
	}
}
};

int returnkey(char *nameofv){
	int k=0;
	for(int i=0;nameofv[i]!='\0';i++){
	k=k+nameofv[i];
	}
	cout<<k<<endl;
	k=k%(sizeof(nameofv));
	return k;
}

symbolList ss[10];
class TokenListA
{
public:
		struct Listnode{
	TokenA node;
	Listnode *next;
	
	};
		Listnode *head;
	TokenListA();
	~TokenListA();
	void printInFileToke();
	void insertIntoToken(TokenA a);
	void print();

};
TokenListA saveToken;
void writeErrorIntoFile(string s){
std::ofstream writeerrors;
writeerrors.open ("errors.txt", std::ofstream::out | std::ofstream::app);
	writeerrors<<s<<endl;
	writeerrors.close();
  }
void TokenListA::printInFileToke(){
	std::ofstream writeToken;
	writeToken.open ("outputToken.txt", std::ofstream::out);
  
	Listnode *a=head;
		while(a!=NULL)
		{
			if(a->node.name!=NULL)
			{
				writeToken<<"<"<<a->node.typeof<<","<<a->node.name<<">"<<endl;
			}
			else if (a->node.idfromSymbolTable==-1&&a->node.name==NULL)
			{
				writeToken<<"<"<<a->node.typeof/*<<","<<a->node.idfromSymbolTable*/<<">"<<endl;
			}
			else 
			{
				writeToken<<"<"<<a->node.typeof<<","<<a->node.idfromSymbolTable<<">"<<endl;
			
			}
			a=a->next;
		}
		
		writeToken.close();
}
TokenListA::TokenListA()
{
	head=NULL;
}
TokenListA::~TokenListA()
{
}
void TokenListA::insertIntoToken(TokenA a){
	if(head==NULL){
		head=new Listnode;
		head->node=a;
		head->next=NULL;
	}
	else
	{
		Listnode *p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=new Listnode;
		p->next->node=a;
		p->next->next=NULL;
	}
}
void TokenListA::print(){
		Listnode *a=head;
		while(a!=NULL)
		{
			if(a->node.name!=NULL)
			{
				cout<<"<"<<a->node.typeof<<","<<a->node.name<<">"<<endl;
			}
			else if (a->node.idfromSymbolTable==-1&&a->node.name==NULL){
				cout<<"<"<<a->node.typeof/*<<","<<a->node.idfromSymbolTable*/<<">"<<endl;
			}
			else 
			{
					cout<<"<"<<a->node.typeof<<","<<a->node.idfromSymbolTable<<">"<<endl;
			
			}
			a=a->next;
		}
		
	}
string filebuffer;
/*void makebufferempty(char bluh[]){
	for(int i=0;i<100;i++)
	{
		bluh[i]=' ';
	}
}*/
void createKittyToken(int *ph,int*pt,char *type){
	int l=*ph;
	int m=*pt;
	int toksize=m-l;
	//cout<<toksize<<" "<<*ph<<" "<<*pt<<endl;
	TokenA a;
	
	char *arrToken=new char[toksize];
	int i;
	int j=0;
	for(i=l;i<m;i++)
	{
		arrToken[j]=filebuffer[i];
		j++;
	
	}
	
	arrToken[j]='\0';
//cout<<arrToken;
	a.name=arrToken;
	a.typeof=type;
	a.idfromSymbolTable=-1;
	//arrToken=NULL;
	saveToken.insertIntoToken(a);
}
void append0atend(char arr[]){
	int i =0;
	while(arr[i]!='\0'){
	i++;
	}
	arr[i]='0';
	arr[i+1]='\0';
}
void append0atstart(char *arr){
int i=0;
string s=arr;
std::string d=std::string(1,'0').append(s);
while(d[i]!='\0')
{
	arr[i]=d[i];
	i++;
}
arr[i]='\0';
//cout<<endl<<arr<<endl;
//system("pause");
}
void checkKittyNumber(int *phead,int *ptail){
	int numberstate=0;
	int nstates[150];
	int j=0;
	for(int i=0;i<150;i++)
	{
		nstates[i]=-2;
	}
	bool con=true;
	int nda[4][2];
	nda[0][0]=0;
	nda[0][1]=1;
	nda[1][0]=2;
	nda[1][1]=3;
	nda[2][0]=2;
	nda[2][1]=3;
	nda[3][0]=3;
	nda[3][1]=3;
	int help;
	while (con)
	{
		
		if(filebuffer[*ptail]>='0'&&filebuffer[*ptail]<='9')
		{
			help=0;
			numberstate=nda[numberstate][help];
			nstates[j]=numberstate;
			j++;
			*ptail=*ptail+1;
		}
		else if(filebuffer[*ptail]=='.')
		{
			
				 help=1;
			numberstate=nda[numberstate][help];
			nstates[j]=numberstate;
			j++;
			*ptail=*ptail+1;
		}
		else
		{
			if(numberstate>=0&&numberstate<3)
			{
				cout<<"token created number is valid";
				/*for(int i=*phead;i<*ptail;i++)
				{
				cout<<filebuffer[i];
				}*/
				cout<<endl;
			int l=*phead;
			int m=*ptail;
			
			int toksize=m-l;
			//cout<<toksize<<" "<<*ph<<" "<<*pt<<endl;
			TokenA a;
			char *arrToken=new char[toksize];
			int i;
			int j=0;
			for(i=l;i<m;i++)
			{
				arrToken[j]=filebuffer[i];
				j++;
			}
	
			arrToken[j]='\0';
		//cout<<arrToken;
			
			if(arrToken[toksize-1]=='.')
			{
				append0atend(arrToken);
			}
			if(arrToken[0]=='.')
			{
				append0atstart(arrToken);
			}
			
			a.name=arrToken;
			a.typeof="number";
			a.idfromSymbolTable=-1;
			//arrToken=NULL;
			saveToken.insertIntoToken(a);			
			cout<<a.name<<endl;
		//	system("pause");
			*phead=*ptail;				
	
			}
			else
			{
				writeErrorIntoFile("error in numbers");
		//		system("pause");
				con=false;
				int partalstatepointer=-1;
				bool creat=true;
				for(int i=0;i<150;i++)
				{
					
					if(nstates[i]>=0&&nstates[i]<3){
						partalstatepointer=0;
						partalstatepointer=*phead+i+1;
					}
					 if(nstates[i]==-2)
					{
						//cout<<"errror token"<<endl;
						//partalstatepointer=*ptail;
						i=155;
						//creat=false;
					 }
				}
				if(partalstatepointer==-1){
					creat=false;
				}
		//		cout<<*phead<<" "<<partalstatepointer<<endl;
			//	system("pause");
				if(creat){
				*ptail=partalstatepointer;
				TokenA a;
				int toksize=*ptail-*phead;
				char *creatarr=new char[toksize];
				int j=0;
				for(int i=*phead;i<*ptail;i++)
				{
					creatarr[j]=filebuffer[i];
					cout<<creatarr[j];
					j++;
				}
				creatarr[j]='\0';
				if(creatarr[toksize-1]=='.')
			{
				append0atend(creatarr);
			}
				if(creatarr[0]=='.')
			{
				append0atstart(creatarr);
			}
			
				cout<<endl;
				a.typeof="number";
				//a.idfromSymbolTable=1;
				a.name=creatarr;
				saveToken.insertIntoToken(a);
				}
				*phead=*ptail;				
			
				//system("pause");
			
			}
			con=false;
			*phead=*ptail;
		}
	}
}
void readfromfile(){
	string ss="";
	ifstream inpFile ("inputCC.txt");
	if(inpFile.is_open())
		{
			while(getline(inpFile,ss)){
				for(int i=0;ss[i]!='\0';i++)
	  {
		  if(ss[i]=='/'&&ss[i+1]=='/'){
		  for(int j=i;ss[j]!='\0';j++)
			  ss[j]='\0';
		  }
	  }
//	  
				filebuffer=filebuffer+ss;
			}
		
	}
	else
	{
		cout<<"cant open file "<<endl;
	}
}
int checkKittyoperator(int *phead,int *ptail)
{
	TokenA a;
	a.typeof="operator";
	a.idfromSymbolTable=-1;
	if (filebuffer[*ptail]=='<')
	{//cout<<"<<<<<<<<<<<<<<<<<<<"<<endl;
		if (filebuffer[*ptail+1]=='<')
		{
			if (filebuffer[*ptail+2]=='<')
			{
				a.name="output";
				*ptail=*ptail+3;
				*phead=*ptail;
saveToken.insertIntoToken(a);
				return 0;
			}
			writeErrorIntoFile("error unrecognized symbol '<' ");
		}
		else if(filebuffer[*ptail+1]=='>')
		{
			a.name="LesGreat";
			*ptail=*ptail+2;
			*phead=*ptail;
saveToken.insertIntoToken(a);
			return 0;
			
		}
		a.name="Lesthen";
		*ptail=*ptail+1;
		*phead=*ptail;
saveToken.insertIntoToken(a);
		return 0;	
	}
	
	else if (filebuffer[*ptail]=='>')
	{
		if (filebuffer[*ptail+1]=='>')
		{
			if (filebuffer[*ptail+2]=='>')
			{
				a.name="input";
				*ptail=*ptail+3;
				*phead=*ptail;
saveToken.insertIntoToken(a);
				return 0;
			}
			writeErrorIntoFile("error unrecognized symbol '<' ");
		}
		
		a.name="greaterthen";
		*ptail=*ptail+1;
		*phead=*ptail;
saveToken.insertIntoToken(a);
		return 0;	
	}
	else if (filebuffer[*ptail]==':')
	{
		if(filebuffer[*ptail+1]=='='){
			a.name="assign";
			*ptail=*ptail+2;
			*phead=*ptail;
			system("pause");
			saveToken.insertIntoToken(a);
			return 0;
			}
		else{
		writeErrorIntoFile("error unrecognized ':' ");
		*ptail=*ptail+1;
		*phead=*ptail;
		}
//saveToken.insertIntoToken(a);
		return 0;
			
	}
	else if (filebuffer[*ptail]=='=')
	{
		if(filebuffer[*ptail+1]=='='){
			a.name="compareEqual";
			*ptail=*ptail+2;
			*phead=*ptail;
saveToken.insertIntoToken(a);
			return 0;
			}
		writeErrorIntoFile("error unrecognized '=' ");
		*ptail=*ptail+1;
		*phead=*ptail;
//saveToken.insertIntoToken(a);
		return 0;
	}
	else if(filebuffer[*ptail]=='!')
	{
		if(filebuffer[*ptail+1]=='='){
			a.name="notEqual";
			*ptail=*ptail+2;
			*phead=*ptail;
saveToken.insertIntoToken(a);
			return 0;
			}
		writeErrorIntoFile("error unrecognized '!' ");
		*ptail=*ptail+1;
		*phead=*ptail;
//saveToken.insertIntoToken(a);
		return 0;
	}
	else if (filebuffer[*ptail]=='+')
	{
		if(filebuffer[*ptail+1]=='+')
		{a.name="incriment";
		*ptail=*ptail+2;
		*phead=*ptail;
saveToken.insertIntoToken(a);
		return 0;

		}
		else if(filebuffer[*ptail+1]=='=')
		{a.name="increaseIntoVariable";
		*ptail=*ptail+2;
		*phead=*ptail;
saveToken.insertIntoToken(a);
		return 0;

		}
		a.name="plus";
		*ptail=*ptail+1;
		*phead=*ptail;
saveToken.insertIntoToken(a);
		return 0;	
	}
	else if (filebuffer[*ptail]=='-')
	{
		if(filebuffer[*ptail+1]=='-')
		{
		a.name="dicrement";
		*ptail=*ptail+2;
		*phead=*ptail;
saveToken.insertIntoToken(a);
		return 0;
		}
		else if(filebuffer[*ptail+1]=='=')
		{
			a.name="decIntoVariable";
		*ptail=*ptail+2;
		*phead=*ptail;
saveToken.insertIntoToken(a);
		return 0;
		}

		a.name="minus";
		*ptail=*ptail+1;
		*phead=*ptail;
saveToken.insertIntoToken(a);
		return 0;	
	}
	else if(filebuffer[*ptail]=='&')
	{
		if(filebuffer[*ptail+1]=='&'){
			a.name="ANDOperator";
			*ptail=*ptail+2;
			*phead=*ptail;
saveToken.insertIntoToken(a);
			return 0;
			}
		else if(filebuffer[*ptail+1]=='|'){
			a.name="NOROperator";
			*ptail=*ptail+2;
			*phead=*ptail;
saveToken.insertIntoToken(a);
			return 0;
			}

		writeErrorIntoFile("error unrecognized '&' ");
		*ptail++;
		*phead=*ptail;
//saveToken.insertIntoToken(a);
		return 0;
	}
	else if(filebuffer[*ptail]=='|')
	{
		if(filebuffer[*ptail+1]=='|'){
			a.name="OROperator";
			*ptail=*ptail+2;
			*phead=*ptail;
saveToken.insertIntoToken(a);
			return 0;
			}
		else if(filebuffer[*ptail+1]=='&'){
			a.name="XOROperator";
			*ptail=*ptail+2;
			*phead=*ptail;
saveToken.insertIntoToken(a);
			return 0;
			}

		writeErrorIntoFile("error unrecognized '|' ");
		*ptail++;
		*phead=*ptail;
	//saveToken.insertIntoToken(a);
	return 0;
	}
	else if (filebuffer[*ptail]=='*')
	{
			a.name="Mul";
			*ptail=*ptail+1;
			*phead=*ptail;
	saveToken.insertIntoToken(a);
	return 0;
		
	}
	else if (filebuffer[*ptail]=='/')
	{
			a.name="Dev";
			*ptail=*ptail+1;
			*phead=*ptail;
		saveToken.insertIntoToken(a);

			return 0;
		
	}
	
	
	return 0;
}
void checkKittyIdentifierUn(int *phead,int *ptail){
int sstate=0;
int sstates[100];
for(int i=0;i<100;i++)
{
	sstates[i]=-2;
}
bool con=true;
int help=0;
char transissionTable[10][3];
transissionTable[0][0]=-1;
transissionTable[0][1]=-1;
transissionTable[0][2]=1;

transissionTable[1][0]=3;
transissionTable[1][1]=2;
transissionTable[1][2]=2;
transissionTable[2][0]=2;
transissionTable[2][1]=2;
transissionTable[2][2]=2;
transissionTable[3][0]=3;
transissionTable[3][1]=6;
transissionTable[3][2]=4;
transissionTable[4][0]=3;
transissionTable[4][1]=2;
transissionTable[4][2]=5;
transissionTable[5][0]=3;
transissionTable[5][1]=2;
transissionTable[5][2]=2;
transissionTable[6][0]=7;
transissionTable[6][1]=6;
transissionTable[6][2]=2;
transissionTable[7][0]=7;
transissionTable[7][1]=6;
transissionTable[7][2]=8;
transissionTable[8][0]=7;
transissionTable[8][1]=2;
transissionTable[8][2]=9;
transissionTable[9][0]=7;
transissionTable[9][1]=2;
transissionTable[9][2]=2;
int s=0;	
while (con)
	{
		if(filebuffer[*ptail]>='a'&&filebuffer[*ptail]<='z' ||filebuffer[*ptail]>='A'&&filebuffer[*ptail]<='Z' )
			{
				help=0;
				sstate=transissionTable[sstate][help];
				sstates[s]=sstate;
				s++;
			*ptail=*ptail+1;

		}
		else if(filebuffer[*ptail]>='0'&&filebuffer[*ptail]<='9')
			{
				help=1;
				sstate=transissionTable[sstate][help];
			*ptail=*ptail+1;
			sstates[s]=sstate;
				s++;
			}	
		else if(filebuffer[*ptail]=='_')
			{
				help=2;
				sstate=transissionTable[sstate][help];
				*ptail=*ptail+1;
				sstates[s]=sstate;
				s++;
			}
		else
		{con=false;
			if(sstate==6||sstate==7)
			{
				cout<<"variable is true token is creted"<<endl;
				TokenA a;
				int toksize=*ptail-*phead;
				char *creatarr=new char[toksize];
				int j=0;
				for(int i=*phead;i<*ptail;i++)
				{
					creatarr[j]=filebuffer[i];
					j++;
				}
				creatarr[j]='\0';
				a.typeof="id";
		//		a.idfromSymbolTable=1;
				a.name=creatarr;
				saveToken.insertIntoToken(a);
	//			system("pause");
				symb s;
				s.name=creatarr;
				s.type="identfier";
				ss[returnkey(creatarr)].insertIntoHASH(s);
				con=false;
				*phead=*ptail;				
			
			}
			else
			{
				writeErrorIntoFile("error variable token");
		//		system("pause");
				con=false;
				int partalstatepointer=-1;
				bool creat=true;
				for(int i=0;i<100;i++)
				{
					if(sstates[i]==7||sstates[i]==6){
						//cout<<"good token"<<endl;
						partalstatepointer=0;
						partalstatepointer=*phead+i+1;
						i=122;
					}
					 if(sstates[i]==-2)
					{
						//cout<<"errror token"<<endl;
						//partalstatepointer=*ptail;
						i=122;
						//creat=false;
					 }
				}
		//		cout<<*phead<<" "<<partalstatepointer<<endl;
			//	system("pause");
				if(partalstatepointer==-1)
					creat=false;
				if(creat){
				*ptail=partalstatepointer;
				TokenA a;
				int toksize=*ptail-*phead;
				char *creatarr=new char[toksize];
				int j=0;
				for(int i=*phead;i<*ptail;i++)
				{
					creatarr[j]=filebuffer[i];
					cout<<creatarr[j];
					j++;
				}
				creatarr[j]='\0';
				cout<<endl;
				a.typeof="id";
				//a.idfromSymbolTable=1;
				a.name=creatarr;
				saveToken.insertIntoToken(a);
				symb s;
				s.name=creatarr;
				s.type="identfier";
				ss[returnkey(creatarr)].insertIntoHASH(s);
				}
				*phead=*ptail;				
			
				//system("pause");
			
			}
							*phead=*ptail;				

		}
		
	}

}
void 	checkKittyIdentifierA(int *phead,int *ptail){
int sstate=0;
int sstates[100];
for(int i=0;i<100;i++)
{
	sstates[i]=-2;
}
bool con=true;
int help=0;
char transissionTable[11][3];
transissionTable[0][0]=1;
transissionTable[0][1]=-1;
transissionTable[0][2]=-1;
transissionTable[1][0]=1;
transissionTable[1][1]=5;
transissionTable[1][2]=2;
transissionTable[2][0]=4;
transissionTable[2][1]=6;
transissionTable[2][2]=3;
transissionTable[3][0]=4;
transissionTable[3][1]=6;
transissionTable[3][2]=6;
transissionTable[4][0]=4;
transissionTable[4][1]=7;
transissionTable[4][2]=2;
transissionTable[5][0]=1;
transissionTable[5][1]=5;
transissionTable[5][2]=6;
transissionTable[6][0]=6;
transissionTable[6][1]=6;
transissionTable[6][2]=6;
transissionTable[7][0]=8;
transissionTable[7][1]=7;
transissionTable[7][2]=6;
transissionTable[8][0]=8;
transissionTable[8][1]=7;
transissionTable[8][2]=9;
transissionTable[9][0]=8;
transissionTable[9][1]=10;
transissionTable[9][2]=6;
transissionTable[10][0]=8;
transissionTable[10][1]=6;
transissionTable[10][2]=6;
	
int s=0;	
while (con)
	{
		if(filebuffer[*ptail]>='a'&&filebuffer[*ptail]<='z' ||filebuffer[*ptail]>='A'&&filebuffer[*ptail]<='Z' )
			{
				help=0;
				sstate=transissionTable[sstate][help];
				sstates[s]=sstate;
				s++;
			*ptail=*ptail+1;

		}
		else if(filebuffer[*ptail]>='0'&&filebuffer[*ptail]<='9')
			{
				help=1;
				sstate=transissionTable[sstate][help];
			*ptail=*ptail+1;
			sstates[s]=sstate;
				s++;
			}	
		else if(filebuffer[*ptail]=='_')
			{
				help=2;
				sstate=transissionTable[sstate][help];
				*ptail=*ptail+1;
				sstates[s]=sstate;
				s++;
			}
		else
		{
			con=false;
			
		 if(sstate==7||sstate==8)
			{
				cout<<"variable is true token is creted"<<endl;
				TokenA a;
				int toksize=*ptail-*phead;
				char *creatarr=new char[toksize];
				int j=0;
				for(int i=*phead;i<*ptail;i++)
				{
					creatarr[j]=filebuffer[i];
					j++;
				}
				creatarr[j]='\0';
				a.typeof="id";
		//		a.idfromSymbolTable=1;
				a.name=creatarr;
				saveToken.insertIntoToken(a);
	//			system("pause");
				symb s;
				s.name=creatarr;
				s.type="identfier";
				ss[returnkey(creatarr)].insertIntoHASH(s);
				
				con=false;
				*phead=*ptail;				
			
			}
		 
		else
			{ bool haha=true;
				for(int i=0;i<24;i++)
				{
					//cout<<reskeywords[i][0]<<endl;
					if(filebuffer[*phead]==reskeywords[i][0])
					{
						bool ha=true;
						int l=*phead;
						int j=0;
						while(reskeywords[i][j]!='\0')
						{
							if(filebuffer[l]==reskeywords[i][j]){
							ha=true;
							}else
							{
								ha=false;
								break;
							}
							j++;
							l++;
						}
						if(ha){
							haha=false;
							*ptail=l;
							TokenA a;
							a.name=NULL;
							char *arr=new char[10];
							int m=0;
							for(m=0;reskeywords[i][m]!='\0';m++)
							{
								arr[m]=reskeywords[i][m];
							}
							arr[m]='\0';
							a.typeof=arr;
							a.idfromSymbolTable=-1;
							saveToken.insertIntoToken(a);

						}
					}
							
			}
					*phead=*ptail;				
			
				if(haha){
					writeErrorIntoFile("error  variable token");
		//		system("pause");
				con=false;
				int partalstatepointer=-1;
				bool creat=true;
				for(int i=0;i<100;i++)
				{
					if(sstates[i]==7||sstates[i]==6){
						//cout<<"good token"<<endl;
						partalstatepointer=0;
						partalstatepointer=*phead+i+1;
						i=122;
					}
					 if(sstates[i]==-2)
					{
						//cout<<"errror token"<<endl;
						//partalstatepointer=*ptail;
						i=122;
						//creat =false;
					 }
				}
		//		cout<<*phead<<" "<<partalstatepointer<<endl;
			//	system("pause");
				if(partalstatepointer==-1)
					creat=false;
				if(creat){
				*ptail=partalstatepointer;
				TokenA a;
				int toksize=*ptail-*phead;
				char *creatarr=new char[toksize];
				int j=0;
				for(int i=*phead;i<*ptail;i++)
				{
					creatarr[j]=filebuffer[i];
					cout<<creatarr[j];
					j++;
				}
				creatarr[j]='\0';
				cout<<endl;
				a.typeof="id";
				//a.idfromSymbolTable=1;
				a.name=creatarr;
				saveToken.insertIntoToken(a);
				symb s;
				s.name=creatarr;
				s.type="identfier";
				ss[returnkey(creatarr)].insertIntoHASH(s);
				}
				*phead=*ptail;				
			
				//system("pause");
				}			
				}
				
						*phead=*ptail;				
		
		}
		
	
	}
}	
void main (){
	int phead=0;
	int ptail=0;
	readfromfile();
	int it=0;
	for(it=0;filebuffer[it]!='$';it++)
	{
		cout<<filebuffer[it];
	}
	//system("pause");
	//cout<<endl<<filebuffer;
//	bool mainwhile=true;
	
	while (filebuffer[ptail]!='$')
	{	TokenA a;

		if(filebuffer[ptail]>='0'&&filebuffer[ptail]<='9'||filebuffer[ptail]=='.'){
			//cout<<filebuffer[phead]<<endl;
			
			checkKittyNumber(&phead,&ptail);
			//system("pause");
	
		}

		 
		else if(filebuffer[ptail]>='a'&&filebuffer[ptail]<='z'||filebuffer[ptail]>='A'&&filebuffer[ptail]<='Z'){
			//DFA of identifier starting with alphabet
			//cout<<"alphabet called"<<endl;
		//	system("pause");
	
			checkKittyIdentifierA(&phead,&ptail);
		}
				/*
		else if (filebuffer[ptail]=='<'){
			checkoperator(&phead,&ptail);

		}*/

		else if(filebuffer[ptail]=='_'){
		//DFA of identifier starting with underscore 
		//	cout<<filebuffer[phead]<<endl;
			//system("pause");
			checkKittyIdentifierUn(&phead,&ptail);
			
		}
		else if (filebuffer[ptail]=='#')
		{
			if(filebuffer[ptail+1]=='d'&&filebuffer[ptail+2]=='e'&&filebuffer[ptail+3]=='f'&&filebuffer[ptail+4]=='i'&&filebuffer[ptail+5]=='n'&&filebuffer[ptail+6]=='e')
			{
				TokenA a;
				a.typeof="#define";
				a.idfromSymbolTable=-1;
				a.name=NULL;
				saveToken.insertIntoToken(a);
				ptail=ptail+6;
			}
			if(filebuffer[ptail+1]=='i'&&filebuffer[ptail+2]=='n'&&filebuffer[ptail+3]=='c'&&filebuffer[ptail+4]=='l'&&filebuffer[ptail+5]=='u'&&filebuffer[ptail+6]=='d'&&filebuffer[ptail+7]=='e')
			{
				TokenA a;
				a.typeof="#include";
				a.idfromSymbolTable=-1;
				a.name=NULL;
				saveToken.insertIntoToken(a);
				ptail=ptail+7;
			}
			else
			{
				//system("pause");
				writeErrorIntoFile("error un recognized symol #");
				ptail=ptail++;
			}
			phead=ptail;
		}
		else if (filebuffer[ptail]=='<'||filebuffer[ptail]=='>'||filebuffer[ptail]==':'||filebuffer[ptail]=='!'||filebuffer[ptail]=='+'||filebuffer[ptail]=='-'||filebuffer[ptail]=='='
			||filebuffer[ptail]=='/'||filebuffer[ptail]=='&'||filebuffer[ptail]=='|')
		{
			//cout<<"kitty operator"<<endl;
			//cout<<filebuffer[ptail]<<endl;	
		//	system("pause");
			checkKittyoperator(&phead,&ptail);
		}
	else
	{
	if(filebuffer[ptail]=='{'){		
				a.typeof="opencurlBR";
				a.name=NULL;
				a.idfromSymbolTable=-1;
				saveToken.insertIntoToken(a);
			}
	if(filebuffer[ptail]=='}'){		
				a.typeof="closecurlBR";
				a.name=NULL;
				
				a.idfromSymbolTable=-1;
				saveToken.insertIntoToken(a);
			}	
	if(filebuffer[ptail]=='('){		
				a.typeof="openRBR";
				a.name=NULL;
				a.idfromSymbolTable=-1;
				saveToken.insertIntoToken(a);
			}	 
	if(filebuffer[ptail]==')'){		
				a.typeof="closeRBR";
				a.name=NULL;
				a.idfromSymbolTable=-1;
				saveToken.insertIntoToken(a);
			}	 
	if(filebuffer[ptail]=='['){		
				a.typeof="openstandBR";
				a.name=NULL;
				a.idfromSymbolTable=-1;
				saveToken.insertIntoToken(a);
			}	 
	if(filebuffer[ptail]==']'){		
				a.typeof="closestandBR";
				a.name=NULL;
				a.idfromSymbolTable=-1;
				saveToken.insertIntoToken(a);
			//	cout<<filebuffer[ptail+1]<<endl;
			//	system("pause");
	}	 
	if(filebuffer[ptail]==','){		
				a.typeof="coma";
				a.name=NULL;
				a.idfromSymbolTable=-1;
				saveToken.insertIntoToken(a);
			}
	if(filebuffer[ptail]==';'){		
				a.typeof="semi-colen";
				a.name=NULL;
				a.idfromSymbolTable=-1;
				saveToken.insertIntoToken(a);
			}
	else
	{
		writeErrorIntoFile("unrecognized symbol");
	}
		
	ptail=ptail++;
	phead=ptail;
	}

	//<<"into main again "<<phead<<ptail<<endl;
	//system("pause");
	}
	
	saveToken.print();
	saveToken.printInFileToke();
	system("pause");
}