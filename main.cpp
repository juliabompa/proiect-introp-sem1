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
		case 98:
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
			break;
		case 105:
			cout<<"bla";
			break;
		default:
			cout<<"blabla";
	}
	return 0;
}
