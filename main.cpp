#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

int main()
{
	int i, j, k, l;
	cout<<endl;
	cout<<"		INSTRUCTIUNI JOC";
	cout<<endl<<endl;
	cout<<" ";
	char pas;
	cin>>pas;
	while(pas!= 'b' && pas!= 'i' && pas!= 'e')
		cin>>pas;
	switch(pas)
	{
		case 'b':
			char mine[12][12], numere[12][12];
			for(i=0;i<12;i++)
				for(j=0;j<12;j++)
					mine[i][j]= '0';
			mine[0][0]=mine[1][1]=mine[11][11]=mine[11][0]=mine[0][11]=mine[1][11]=mine[11][1]=mine[0][1]=mine[1][0]=' ';
			for(i=2;i<11;i++)
			{
				mine[0][i]='a' - 2 +i;
				mine[1][i]='-';
				mine[i][0]='1' - 2 + i ;
				mine[i][1]='|';
				mine[11][i]='-';
				mine[i][11]='|';
			}
			for(i=1;i<=10;i++)
			{
				k = rand() % 81 + 1;
				if(mine[k/9+2][k%9+2]=='0')
					mine[k/9+2][k%9+2]='1';
				else
					i--;
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
			/*for(i=0;i<12;i++)
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
			}*/
			break;
		case 'i':
			char mine[20][20], numere[20][20];
			for(i=0;i<20;i++)
				for(j=0;j<20;j++)
					mine[i][j]= '0';
			mine[0][0]=mine[1][1]=mine[0][2]=mine[1][2]=mine[19][2]=mine[19][19]=mine[19][0]=mine[0][19]=mine[1][19]=mine[19][1]=mine[0][1]=mine[1][0]=' ';
			for(i=3;i<19;i++)
			{
				mine[0][i]='a' - 3 +i;
				mine[1][i]='-';
				mine[19][i]='-';
			}
			for(i=2;i<19;i++)
			{
				if(i<11)
				{
					mine[i][0]=' ';
					mine[i][1]='1' - 2 + i;
				}
				else
				{
					mine[i][0]='1';
					mine[i][1]='0' - 11 + i;
				}
				mine[i][2]='|';
				mine[i][19]='|';
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
			char mine[20][34], numere[20][34];
			for(i=0;i<20;i++)
				for(j=0;j<34;j++)
					mine[i][j]= '0';
			mine[0][0]=mine[1][1]=mine[0][2]=mine[1][2]=mine[19][2]=mine[19][33]=mine[19][0]=mine[0][33]=mine[1][33]=mine[19][1]=mine[0][1]=mine[1][0]=' ';
			for(i=3;i<29;i++)
			{
				mine[0][i]='a' - 3 +i;
				mine[1][i]='-';
				mine[19][i]='-';
			}
			for(i=29;i<33;i++)
			{
				mine[0][i]='A' - 29 +i;
				mine[1][i]='-';
				mine[19][i]='-';
			}
			for(i=2;i<19;i++)
			{
				if(i<11)
				{
					mine[i][0]=' ';
					mine[i][1]='1' - 2 + i;
				}
				else
				{
					mine[i][0]='1';
					mine[i][1]='0' - 11 + i;
				}
				mine[i][2]='|';
				mine[i][33]='|';
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
	return 0;
}
