/*
ASSIGNMENT 3 PROGRAMMING TECHNIQUE (SET 2)

TEAM MEMBERS:
YASMIN BATRISYIA BINTI ZAHIRUDDIN (A23CS0201)
NURUL ASYIKIN BINTI KHAIRUL ANUAR (A23CS0162)
NAJMA SHAKIRAH BINTI SHAHRULZAMAN (A23CS0140)
*/

#include<iostream>
using namespace std;

const int MAX_OPERATIONS = 100;



int multiplyUsingAddition(int , int );
void displayMainMenu();
void performMultiplication(int[], int[], int &);
void displayResults(int[] ,int[], int);

int main()
{
	int operands1[MAX_OPERATIONS];
	int results[MAX_OPERATIONS];
	int operationCount = 0,choice;
	
	do
	{
		displayMainMenu();
		do {
		cout << "Enter your choice: ";
		cin >> choice;
		} while (choice < 1 || choice > 3);
		cout << endl;
		
		
	
		switch(choice)
		{
			case 1: if(operationCount < MAX_OPERATIONS)
					{
					  	performMultiplication(operands1,results,operationCount);
					  	break;
					}
					else
					{
					  	cout << "Maximum number of operations reached!"
						     << "Cannot perform another multiplication" << endl << endl;
					  	break;		
					}
	
			case 2: if(operationCount == 0)
					{
					  	cout << "No operation in system." << endl << endl;
					  	break;
					}
					else
					{
					  	displayResults(operands1,results,operationCount);
						break;		
					}
			
			
			case 3:	cout << "Goodbye!" << endl << endl;
					cout << "--------------------------------" << endl;
                    system ("pause"); //tambah ni
					return 0;
					break;
                    
		}

	}while(true);
		
}

int multiplyUsingAddition(int a, int b)
{
	int result = 0;
	
	for(int i = 1; i <= b; i++)//repeat addition b times(if 4*5, then 4+4+4+4+4)
	{
		result += a;
	}
	return result;
}

void displayMainMenu()
{
	cout << "<<<<<Main Menu>>>>>" << endl;
	cout << "=============================" << endl;
	cout << "1. Perform Multiplication" << endl;
	cout << "2. Display Results" << endl;
	cout << "3. Quit" << endl;
}

void performMultiplication(int operands1[], int results[], int &operationCount)
{
	int a,b;
	
	
	
	cout << "Enter the number of operands for multiplication: ";
	cin >> operands1[operationCount];
	
	for(int i = 1; i <= operands1[operationCount]; i++)
	{
		if(i == 1)
		{
			cout << "Enter operand " << i << ": ";
			cin >> a;	
		}
		else
		{
			cout << "Enter operand " << i << ": ";
			cin >> b;
			
			a = multiplyUsingAddition(a, b);
		}
		
	}
	
	results[operationCount] = a;
	
	cout << "\nMultiplication performed successfully!\n" << endl;
	
	operationCount++;
}

void displayResults(int operands1[], int results[], int operationCount)
{
	cout << "Results of Mathematical Operations: " << endl;
	cout << "========================================" << endl;
	
	for(int i = 0; i < operationCount; i++)
	{
		cout <<	"Operation " << i+1 << ": " << results[i] 
		     << " (Operands: " << operands1[i] << ")" << endl;
	} 

	cout << endl << endl;

}
