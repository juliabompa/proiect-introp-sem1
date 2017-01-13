#include<iostream>
#include<stdlib.h>
#include<string>
#include<deque>

using namespace std;

void construireMatrici(int a, int b);
void coada();
void random(int numarBombe, int a, int b);
void Mine(int a, int b);
void afisare(int a, int b);
int desfasurareJoc(int x, int y, int numarBombe);


struct Mutare
{
	int primaCoordonata;
	char aDouaCoordonata;
	char actiune;
};

deque<pair<int, int> >q;

unsigned char mine[20][34], numere[20][34], joc[20][34];

int main()
{
	char pas;
	int final;
	cout<<endl;
	cout<<"		INSTRUCTIUNI JOC	";
	cout<<endl<<endl;
	cout<<" ";

	cin>>pas;
	while(pas!= 'b' && pas!= 'i' && pas!= 'e')
		cin>>pas;

	switch(pas)
	{
		case 'b':
			construireMatrici(12, 13);
			random(10, 9, 9);
			Mine(12, 13);
			afisare(12, 13);
			final= desfasurareJoc(12, 13, 10);
			if(final)
				cout<<"		CONGRATULATIONS!!!	";
			
			break;
		case 'i':
			construireMatrici(19, 20);
			random(40, 16, 16);
			Mine(19, 20);
			afisare(19, 20);
			final=desfasurareJoc(19, 20, 40);
			if(final)
				cout<<"		CONGRATULATIONS!!!	";
			
			break;
		case 'e':
			construireMatrici(19, 34);
			random(99, 16, 30);
			Mine(19, 34);
			afisare(19, 34);
			final=desfasurareJoc(19, 34, 99);
			if(final)
				cout<<"		CONGRATULATIONS!!!	";
			
			break;
		default:
			cout<<"blabla";
	}
	system("pause");
	return 0;
}


void coada()
{
	int x, y, k, l;
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		for(k=x-1;k<=x+1;k++)
			for(l=y-1;l<=y+1;l++)
				if(numere[k][l]=='0' && joc[k][l] == 254)
				{
					joc[k][l]=' ';
					q.push_back(make_pair(k,l));
				}
				else
					if(numere[k][l]>'0' && numere[k][l]<='9')
						joc[k][l]=numere[k][l];
		q.pop_front();
	}
}

void construireMatrici(int a, int b)
{
	int i, j;

	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
		{
			mine[i][j]='0';
			joc[i][j]=254;
		}
	mine[0][0]=mine[0][1]=mine[1][0]=mine[1][1]=' ';
	mine[a-1][0]=mine[a-1][1]=' ';
	mine[0][b-1]=mine[0][2]=' ';
	joc[0][0]=joc[0][1]=joc[1][0]=joc[1][1]=' ';
	joc[a-1][0]=joc[a-1][1]=' ';
	joc[0][b-1]=joc[0][2]=' ';

	mine[1][2]=218;
	mine[a-1][b-1]=217;
	mine[a-1][2]=192;
	mine[1][b-1]=191;
	joc[1][2]=218;
	joc[a-1][b-1]=217;
	joc[a-1][2]=192;
	joc[1][b-1]=191;
			
	for(i=3;i<b-1;i++)
	{
		if(i<29)
			mine[0][i]=joc[0][i]='a' - 3 +i;
		else 
			mine[0][i]=joc[0][i]='A' + (i-29);
		mine[1][i]=joc[1][i]='-';
		mine[a-1][i]=joc[a-1][i]='-';
	}
	for(i=2;i<a-1;i++)
	{
		if(i<11)
		{
			mine[i][0]=joc[i][0]=' ';
			mine[i][1]=joc[i][1]='1' - 2 + i;
		}
		else
		{
			mine[i][0]=joc[i][0]='1';
			mine[i][1]=joc[i][1]='0' - 11 + i;
		}
		mine[i][2]=joc[i][2]='|';
		mine[i][b-1]=joc[i][b-1]='|';
	}
}

void random(int numarBombe, int a, int b)
{
	int i, k;
	for(i=0;i<numarBombe;i++)
	{
		k = rand() % (a*b) + 1;
		if(mine[k%a+2][k/a+3]=='0')
			mine[k%a+2][k/a+3]='1';
		else
			i--;
	}
}

void Mine(int a, int b)
{
	int i, j, k, l;
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			numere[i][j]=mine[i][j];
	for(i=2;i<a-1;i++)
		for(j=3;j<b-1;j++)
			if(mine[i][j]=='1')
				numere[i][j]='*';
			else
				if(mine[i][j]=='0')
					for(k=i-1;k<=i+1;k++)
						for(l=j-1;l<=j+1;l++)
							if(mine[k][l]=='1')
								numere[i][j]++;
}

int desfasurareJoc(int x, int y, int numarBombe)
{
	
	int i, j, a, b, ok=1, flags, contor=0;

	Mutare mutare;

	do
	{
		do
		{
			cin>>mutare.primaCoordonata>>mutare.aDouaCoordonata>>mutare.actiune;
			a=mutare.primaCoordonata+1; 
			if(mutare.aDouaCoordonata>='a')
				b=(int)mutare.aDouaCoordonata-'a'+3;
			else
				b=(int)mutare.aDouaCoordonata-'A' + 3 + 26;
		}while(a<2||a>x-1||b<2||b>y-1 || (mutare.actiune!='s'&&mutare.actiune!='d'&&mutare.actiune!='f') 
			|| mutare.actiune=='s' && joc[a][b] != 254 
			|| mutare.actiune=='f' && (joc[a][b] != 254 && joc[a][b]!='+') 
			|| mutare.actiune=='d' && joc[a][b] == 254);

		if(mutare.actiune=='s')
		{
			if(numere[a][b]=='*')
			{
				for(i=2;i<x-1;i++)
					for(j=2;j<y-1;j++)
					{	
						if(numere[i][j]=='*' && joc[i][j]!='+')
							joc[i][j]='*';
						if(joc[i][j]=='+' && numere[i][j]!='*')
							joc[i][j]='x';
					}
				afisare(x,y);
				cout<<endl<<"	"<<"BANG BANG YOU'RE DEAD"<<endl<<endl;
				
				ok=0;
			}
			else
				if(numere[a][b]>'0' && numere[a][b]<='9')
				{
					joc[a][b]=numere[a][b];

					afisare(x,y);
				}
				else
				{
					joc[a][b]=' ';
					q.push_back(make_pair(a,b));
					coada();
					afisare(x,y);
				}
		}
		else
			if(mutare.actiune=='f')
			{
				if(joc[a][b]==254)
					joc[a][b]='+';
				else
					joc[a][b]=254;
				afisare(x,y);
			}
			else
			{
				flags=0;
				ok=1;
				if(joc[a][b]>'0'&&joc[a][b]<='9')
				{
					for(i=a-1;i<=a+1;i++)
						for(j=b-1;j<=b+1;j++)
							if(joc[i][j]=='+')
								flags++;
					if(flags==(int)joc[a][b]-'0')
					{
						for(i=a-1;i<=a+1;i++)
							for(j=b-1;j<=b+1;j++)
							{
								if(joc[i][j]=='+' && numere[i][j]!='*')
								{
									ok=0;
									joc[i][j]='x';
								}
								else
									if(joc[i][j]==254)
									{
										if(numere[i][j]=='0')
										{
											joc[i][j]=' ';
											q.push_back(make_pair(i,j));
											coada();
										}
										else
											if(numere[i][j]<='9' && numere[i][j]>'0')
												joc[i][j]=numere[i][j];
									}
							}
					}
					if(ok==0)
					{
						for(i=2;i<x-1;i++)
							for(j=2;j<y-1;j++)
								if(numere[i][j]=='*' && joc[i][j]!='+')
									joc[i][j]='*';
					}
					afisare(x, y);
					if(ok==0)
						cout<<endl<<"	BANG BANG YOU'RE DEAD	"<<endl<<endl;
				}
			}
			contor=0;
			for(i=2;i<x-1;i++)
			{
				for(j=3;j<y-1;j++)
				{
					if(joc[i][j]=='+'||joc[i][j]==254)
						contor++;
				}
			}
			if(contor==numarBombe)
				break;
	}while(ok);
	if(ok)
		return 1;
	else
		return 0;
}

void afisare(int a, int b)
{
	int i, j;
	if (system("CLS")) 
		system("clear");
	cout<<endl;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
			cout<<joc[i][j]<<" ";
		cout<<endl;
	}
}