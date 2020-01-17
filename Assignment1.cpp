/*
KULDEEP NATH
19HCS4029
ABOUT : PROGRAM THAT USES RECURSION TO CALCULATE GCD, FACTORIAL, POWER AND PRINT N TERMS OF FIBONACCI SERIES
*/
#include<iostream>
using namespace std;

int calcFacRecr(int);    			// FUNCTION TO CALCULATE FACTORIAL USING RECURSION
int calcGCDRecr(int,int); 			// FUNCTION TO CALCULATE GCD USING RECURSION 
int calcPowRecr(int,int); 		    // FUNCTION TO CALCULATE POWER USING RECURSION
int FiboRecr(int);					// FUNCTION TO PRINT N TERMS OF FIBONACCI SERIES USING RECURSION


int calcFact(int); 					// FUNCTION TO CALCULATE FACTORIAL USING ITERATION
int calcGCD(int,int); 				// FUNCTION TO CALCULATE GCD USING ITERATION
int calcPow(int,int); 		    	// FUNCTION TO CALCULATE POWER USING ITERATION
void Fibo(int);						// FUNCTION TO PRINT N TERMS OF FIBONACCI SERIES USING ITERATION	

int main()
{
	int n,m;
	
	cout<<"\t ######################## Using RECURSIVE Function #############################\n";
	
	//################################ POWER ####################################
	cout<<"To calc Power \n";
	cout<<"Enter Base : ";
	cin>>m;
	cout<<"Enter Power : ";
	cin>>n;
	
	try
	{
		if(n<0)
		throw  0;
		
		else if(n==0 &&m==0)
		throw "\nResult not defined...";
		
		cout<<"\nResult : "<<calcPowRecr(m,n);
	}
	
	catch (int x)
	{
		cout<<"\nResult : 1/("<<calcPowRecr(m,n)<<")";
	}
	catch (const char *x)
	{
		cout<<x;
	}
	/**################################# FACTORIAL #################################*/
	cout<<"\n\nTo calculate factorial\n";
	cout<<"Enter a number : ";
	cin>>n;
	try
	{
		if(n<0)
		throw "\nWrong input...\n";
		if (n==0)
		throw 1;
		cout<<"Factorial : "<<calcFacRecr(n);
	}
	catch (int x)
	{
		cout<<"Factorial : "<<x;
	}
	catch (const char *x)
	{
		cout<<x;
	}
	
	//################################### GCD ##################################
	cout<<"\n\nTo calculate GCD  \n";
	cout<<"Enter two numbers :\n";
	cin>>n>>m;
	try
	{
		if(n<0&&m<0)
		throw "\nWrong input...\n";
		cout<<"GCD : "<<calcGCDRecr(n,m);
	}
	catch (const char *x)
	{
		cout<<x;
	}
	//############################### FIBONACCI SERIES ##########################
	cout<<"\n\nTo Print Fibonacchi Series  \n";
	cout<<"Enter no of terms :\n";
	cin>>n;
	try
	{
		if(n<=0)
		throw "\nWrong input...\n";
		
		for(int i=1;i<=n;i++)
		cout<<FiboRecr(i)<<" ";
	}
	catch (const char *x)
	{
		cout<<x;
	}
	
	
	cout<<"\n\n\t ######################## Using ITERATIVE Function #############################\n";
	
	//##################################### POWER #####################################
	cout<<"To calc Power \n";
	cout<<"Enter Base : ";
	cin>>m;
	cout<<"Enter Power : ";
	cin>>n;
	
	try
	{
		if(n<0)
		throw  0;
		
		else if(n==0 &&m==0)
		throw "\nResult not defined...";
		
		cout<<"\nResult : "<<calcPow(m,n);
	}
	
	catch (int x)
	{
		cout<<"\nResult : 1/("<<calcPow(m,n)<<")";
	}
	catch (const char *x)
	{
		cout<<x;
	}
	/**############################## FACTORIAL ####################################*/
	cout<<"\n\nTo calculate factorial\n";
	cout<<"Enter a number : ";
	cin>>n;
	try
	{
		if(n==0)
		throw 1;
		if(n<0)
		throw "\nWrong input...\n";
		cout<<"Factorial : "<<calcFact(n);
	}
	catch (const char *x)
	{
		cout<<x;
	}
	catch (int x)
	{
		cout<<"Factorial : "<<x;
	}
	
	//############################### GCD ###########################################
	cout<<"\n\nTo calculate GCD  \n";
	cout<<"Enter two numbers :\n";
	cin>>n>>m;
	try
	{
		if(n<0&&m<0)
		throw "\nWrong input...\n";
		cout<<"GCD : "<<calcGCD(n,m);
	}
	catch (const char *x)
	{
		cout<<x;
	}
	//########################## FIBONACCI SERIES #####################################
	cout<<"\n\nTo Print Fibonacchi Series  \n";
	cout<<"Enter no of terms :\n";
	cin>>n;
	try
	{
		if(n<=0)
		throw "\nWrong input...\n";
		Fibo(n);
	}
	catch (const char *x)
	{
		cout<<x;
	}
	
	
	return 0;
}

//
int calcFacRecr(int num)
{
	if(num==1)
	return 1;
	else
	return num*calcFacRecr(num-1);
}

//
int calcGCDRecr(int var_1, int var_2)
{
	if (var_2==0)
	return var_1;
	else
	return calcGCDRecr(var_2,var_1%var_2);
}

//
int FiboRecr(int term)
{
	if(term==1)
	return 0;
	else if(term==2)
	return 1;
	
	return FiboRecr(term-2) + FiboRecr(term-1);
}
//
int calcPowRecr(int m, int n)
{
	n=(n<0)?-n:n;
	if(n==0)
		return 1;
	else 
		return m*calcPowRecr(m,n-1); 
}

//
int calcFact(int n)
{
	int fact=1;
	for(int i=1;i<=n;i++)
		fact*=i;
	return fact;
}

//
int calcPow(int m, int n)
{
	n=(n<0)?-n:n;
	int pow=1;
	for(;n!=0;n--)
	pow*=m;
	return pow;
}

//
int calcGCD(int num1,int num2)
{
	int t=0;
	while(num2!=0)
	{
		t=num1;
		num1=num2;
		num2=t%num2;
	}
	return num1;
}

//
void Fibo(int n)
{
	int a=0,b=1,s=0;
	cout<<"Fibonacci Series of "<<n<<" terms : ";
	for(int i=0;i<n;i++)
	{
		cout<<a<<" ";
		s=a+b;
		a=b;
		b=s;
	}
}
