#include<iostream>
using namespace std;

int pass(int a,int b,int c)
{
	int sum=0;
	for(int i=2000;i<a;i++)
	{
		if((i%4==0&&i%100!=0)||(i%400==0))
			sum+=366;
		else
			sum+=365;
	}
	for(i=1;i<b;i++)
	{
		switch(i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			sum+=31;
			break;
		case 2:
			if((a%4==0&&a%100!=0)||(a%400==0))
				sum+=29;
			else
				sum+=28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			sum+=30;
			break;
		}
	}
	sum+=c;
	return sum-1;
}

int now(int a,int b,int c)
{	
	int sum=0;
	for(int i=1;i<b;i++)
	{
		switch(i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			sum+=31;
			break;
		case 2:
			if((a%4==0&&a%100!=0)||(a%400==0))
				sum+=29;
			else
				sum+=28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			sum+=30;
			break;
		}
	}
	sum+=c;
	return sum;
}

int main()
{
	int year[100],month[100],day[100],n=0;
	for(int i=0;i<100;i++)
	{
		cin>>year[i];
		if(year[i]==-1)
			break;
		cin>>month[i];
		cin>>day[i];
		n++;
		
	}
	for(i=0;i<n;i++)
	{
		cout<<pass(year[i],month[i],day[i])<<endl;
		cout<<now(year[i],month[i],day[i])<<endl;
	}
	return 0;
} 
