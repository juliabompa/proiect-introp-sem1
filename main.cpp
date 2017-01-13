#include<iostream>
#include<stdlib.h>
#include<string>
#include<deque>

using namespace std;

struct Mutare
{
	int primaCoordonata;
	char aDouaCoordonata;
	char actiune;
};
unsigned char mine[20][34], numere[20][34], joc[20][34];

int main()
{
	int i, j, k, l, a, b, x, y, ok=1, flags;

	char pas;

	Mutare mutare;

	deque<pair<int, int> >q;

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
			for(i=0;i<12;i++)
				for(j=0;j<12;j++)
				{
					mine[i][j]='0';
					joc[i][j]=254;
				}
			mine[0][0]=mine[11][0]=mine[0][11]=mine[0][1]=mine[1][0]=' ';
			joc[0][0]=joc[11][0]=joc[0][11]=joc[0][1]=joc[1][0]=' ';
			mine[1][1]=218;
			mine[11][11]=217;
			mine[1][11]=191;
			mine[11][1]=192;
			joc[1][1]=218;
			joc[11][11]=217;
			joc[1][11]=191;
			joc[11][1]=192;
			for(i=2;i<11;i++)
			{
				mine[0][i]=joc[0][i]='a' - 2 +i;
				mine[1][i]=joc[1][i]='-';
				mine[i][0]=joc[i][0]='1' - 2 + i ;
				mine[i][1]=joc[i][1]='|';
				mine[11][i]=joc[11][i]='-';
				mine[i][11]=joc[i][11]='|';
			}
			for(i=1;i<=10;)
			{
				k = rand() % 81 + 1;
				if(mine[k/9+2][k%9+2]== '0')
				{
					mine[k/9+2][k%9+2]='1';
					i++;
				}
				
			}
			for(i=0;i<12;i++)
				for(j=0;j<12;j++)
					numere[i][j]=mine[i][j];
			for(i=2;i<11;i++)
				for(j=2;j<11;j++)
					if(mine[i][j]=='1')
						numere[i][j]='*';
					else
						for(k=i-1;k<=i+1;k++)
							for(l=j-1;l<=j+1;l++)
								if(mine[k][l]=='1')
									numere[i][j]++;
			for(i=0;i<12;i++)
			{
				for(j=0;j<12;j++)
					cout<<mine[i][j]<<" ";
				cout<<endl;
			}

			cout<<endl;
			for(i=0;i<12;i++)
			{
				for(j=0;j<12;j++)
					cout<<numere[i][j]<<" ";
				cout<<endl;
			}

			do
			{
				cin>>mutare.primaCoordonata>>mutare.aDouaCoordonata>>mutare.actiune;
				a=mutare.primaCoordonata+1, b=(int)mutare.aDouaCoordonata-'a'+2;
				while(a<2||a>11||b<2||b>11||(mutare.actiune!='s'&&mutare.actiune!='d'&&mutare.actiune!='f'))
				{
					cin>>mutare.primaCoordonata>>mutare.aDouaCoordonata>>mutare.actiune;
					a=mutare.primaCoordonata+1, b=(int)mutare.aDouaCoordonata-'a'+2;
				}

				if(mutare.actiune=='s')
				{
					if(numere[a][b]=='*')
					{
						for(i=2;i<11;i++)
							for(j=2;j<11;j++)
								if(numere[i][j]=='*')
									joc[i][j]='*';
						cout<<endl<<"	"<<"BANG BANG YOU'RE DEAD"<<endl<<endl;
						for(i=0;i<12;i++)
						{
							for(j=0;j<12;j++)
								cout<<joc[i][j]<<" ";
							cout<<endl;
						}
						ok=0;
					}
					else
						if(numere[a][b]>'0' && numere[a][b]<='9')
						{
							joc[a][b]=numere[a][b];
							for(i=0;i<12;i++)
							{
								for(j=0;j<12;j++)
									cout<<joc[i][j]<<" ";
								cout<<endl;
							}
						}
						else
						{
							joc[a][b]=' ';
							q.push_back(make_pair(a,b));
							while(!q.empty())
							{
								x=q.front().first;
								y=q.front().second;
								for(i=x-1;i<=x+1;i++)
									for(j=y-1;j<=y+1;j++)
										if(numere[i][j]=='0' && joc[i][j] == 254)
										{
											joc[i][j]=' ';
											q.push_back(make_pair(i,j));
										}
										else
											if(numere[i][j]>'0' && numere[i][j]<='9')
												joc[i][j]=numere[i][j];
								q.pop_front();
							}
							for(i=0;i<12;i++)
							{
								for(j=0;j<12;j++)
									cout<<joc[i][j]<<" ";
								cout<<endl;
							}
						}
				}
				else
					if(mutare.actiune=='f')
					{
						joc[a][b]='+';
						for(i=0;i<12;i++)
						{
							for(j=0;j<12;j++)
								cout<<joc[i][j]<<" ";
							cout<<endl;
						}
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
												else
													if(numere[i][j]<='9' && numere[i][j]>'0')
														joc[i][j]=numere[i][j];
											}
									}
							}
							if(ok==0)
							{
								for(i=2;i<11;i++)
									for(j=2;j<11;j++)
										if(numere[i][j]=='*')
											joc[i][j]='*';
								cout<<endl<<"	BANG BANG YOU'RE DEAD	"<<endl<<endl;
							}
							for(i=0;i<12;i++)
							{
								for(j=0;j<12;j++)
									cout<<joc[i][j]<<" ";
								cout<<endl;
							}
						}
					}
			}while(ok);
			break;
		case 'i':
			for(i=0;i<20;i++)
				for(j=0;j<20;j++)
				{
					mine[i][j]='0';
					joc[i][j]=254;
				}

			mine[0][0]=mine[0][2]=mine[1][1]=mine[19][1]=mine[0][19]=mine[19][0]=mine[0][1]=mine[1][0]=' ';
			joc[0][0]=joc[0][2]=joc[1][1]=joc[19][1]=joc[0][19]=joc[19][0]=joc[0][1]=joc[1][0]=' ';
			mine[1][2]=218;
			mine[19][19]=217;
			mine[19][2]=192;
			mine[1][19]=191;
			joc[1][2]=218;
			joc[19][19]=217;
			joc[19][2]=192;
			joc[1][19]=191;
			
			for(i=3;i<19;i++)
			{
				mine[0][i]=joc[0][i]='a' - 3 +i;
				mine[1][i]=joc[1][i]='-';
				mine[19][i]=joc[19][i]='-';
			}
			for(i=2;i<19;i++)
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
				mine[i][19]=joc[i][19]='|';
			}
			for(i=1;i<=40;i++)
			{
				k = rand() % (16*16) + 1;
				if(mine[k/16+2][k%16+3]=='0')
					mine[k/16+2][k%16+3]='1';
				else
					i--;
			}
			for(i=0;i<20;i++)
				for(j=0;j<20;j++)
					numere[i][j]=mine[i][j];
			for(i=2;i<19;i++)
				for(j=3;j<19;j++)
					if(mine[i][j]=='1')
						numere[i][j]='*';
					else
						for(k=i-1;k<=i+1;k++)
							for(l=j-1;l<=j+1;l++)
								if(mine[k][l]=='1')
									numere[i][j]++;
			/*for(i=0;i<20;i++)
			{
				for(j=0;j<20;j++)
					cout<<mine[i][j]<<" ";
				cout<<endl;
			}

			cout<<endl;
			for(i=0;i<20;i++)
			{
				for(j=0;j<20;j++)
					cout<<numere[i][j]<<" ";
				cout<<endl;
			}*/
			break;
		case 'e':
			for(i=0;i<20;i++)
				for(j=0;j<34;j++)
				{
					mine[i][j]='0';
					joc[i][j]=254;
				}

			mine[0][0]=mine[1][1]=mine[0][2]=mine[19][0]=mine[0][33]=mine[19][1]=mine[0][1]=mine[1][0]=' ';
			joc[0][0]=joc[1][1]=joc[0][2]=joc[19][0]=joc[0][33]=joc[19][1]=joc[0][1]=joc[1][0]=' ';
			mine[1][2]=218;
			mine[1][33]=191;
			mine[19][33]=217;
			mine[19][2]=192;
			joc[1][2]=218;
			joc[1][33]=191;
			joc[19][33]=217;
			joc[19][2]=192;

			for(i=3;i<29;i++)
			{
				mine[0][i]=joc[0][i]='a' - 3 +i;
				mine[1][i]=joc[1][i]='-';
				mine[19][i]=joc[19][i]='-';
			}
			for(i=29;i<33;i++)
			{
				mine[0][i]=joc[0][i]='A' - 29 +i;
				mine[1][i]=joc[1][i]='-';
				mine[19][i]=joc[19][i]='-';
			}
			for(i=2;i<19;i++)
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
				mine[i][33]=joc[i][33]='|';
			}
			for(i=1;i<99;i++)
			{
				k = rand() % (16*30) + 1;
				if(mine[k%16+2][k/16+3]=='0')
					mine[k%16+2][k/16+3]='1';
				else
					i--;
			}
			for(i=0;i<20;i++)
				for(j=0;j<34;j++)
					numere[i][j]=mine[i][j];
			for(i=2;i<19;i++)
				for(j=3;j<33;j++)
					if(mine[i][j]=='1')
						numere[i][j]='*';
					else
						for(k=i-1;k<=i+1;k++)
							for(l=j-1;l<=j+1;l++)
								if(mine[k][l]=='1')
									numere[i][j]++;
			/*for(i=0;i<20;i++)
			{
				for(j=0;j<34;j++)
					cout<<mine[i][j]<<" ";
				cout<<endl;
			}

			cout<<endl;
			for(i=0;i<20;i++)
			{
				for(j=0;j<34;j++)
					cout<<numere[i][j]<<" ";
				cout<<endl;
			}*/
			break;
		default:
			cout<<"blabla";
	}

	/*do
	{
		cin>>mutare.primaCoordonata>>mutare.aDouaCoordonata>>mutare.actiune;
		a=mutare.primaCoordonata+1, b=(int)mutare.aDouaCoordonata-'a'+2;
		while(a<2||a>11||b<2||b>11||(mutare.actiune!='s'&&mutare.actiune!='d'&&mutare.actiune!='f'))
		{
			cin>>mutare.primaCoordonata>>mutare.aDouaCoordonata>>mutare.actiune;
			a=mutare.primaCoordonata+1, b=(int)mutare.aDouaCoordonata-'a'+2;
		}

		if(mutare.actiune=='s')
		{
			if(numere[a][b]=='*')
			{
				for(i=2;i<11;i++)
					for(j=2;j<11;j++)
						if(numere[i][j]=='*')
							joc[i][j]='*';
				cout<<endl<<"	"<<"BANG BANG YOU'RE DEAD"<<endl<<endl;
				for(i=0;i<12;i++)
				{
					for(j=0;j<12;j++)
						cout<<joc[i][j]<<" ";
					cout<<endl;
				}
				ok=0;
			}
			else
				if(numere[a][b]>'0' && numere[a][b]<='9')
				{
					joc[a][b]=numere[a][b];
					for(i=0;i<12;i++)
					{
						for(j=0;j<12;j++)
							cout<<joc[i][j]<<" ";
						cout<<endl;
					}
				}
				else
				{
					joc[a][b]=' ';
					q.push_back(make_pair(a,b));
					while(!q.empty())
					{
						x=q.front().first;
						y=q.front().second;
						for(i=x-1;i<=x+1;i++)
							for(j=y-1;j<=y+1;j++)
									if(numere[i][j]=='0' && joc[i][j] == 254)
									{
										joc[i][j]=' ';
										q.push_back(make_pair(i,j));
									}
									else
										if(numere[i][j]>'0' && numere[i][j]<='9')
											joc[i][j]=numere[i][j];
						q.pop_front();
					}
					for(i=0;i<12;i++)
					{
						for(j=0;j<12;j++)
							cout<<joc[i][j]<<" ";
						cout<<endl;
					}
				}
		}
		else
			if(mutare.actiune=='f')
			{
				joc[a][b]='+';
				for(i=0;i<12;i++)
					{
						for(j=0;j<12;j++)
							cout<<joc[i][j]<<" ";
						cout<<endl;
					}
			}
			else
			{

			}
	}while(ok);
	if(ok==0)
	{*/

	return 0;
}
