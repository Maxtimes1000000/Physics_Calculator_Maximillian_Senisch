/*
	Input Validation with Ref Functions 
	A cleaner way to do input validation
	Validating input, an essential process.
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
	Keeping Dr. McMillan from breaking my code, defend against "dark side of the force",
	and/or legitimate user error. 
	//Try and Catch blocks are used in error checking
	Teacher: Dr. Tyson McMillan, Ph.D.  
  STUDENT (McMillanite): Maximillian Senisch
  Description:This program is going to be a looping menu that allows the user to choose between several physics maths they would like to do
*/
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
                              // Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include <string> //for string manipulation
#include <sstream> //for string manipulation and comparison
#include <iomanip>
#include <vector>

using namespace std;

void Multiply(int, vector<string>, vector<double>, vector<string>);
void Divide(int, vector<string>, vector<double>, vector<string>);
string concatinate(string, string);
double InputValue(vector<string>);
string InputUnits(vector<string>);
void Output();

void Velocity();
void Acceleration();
void Motion();
void NewtonsSecondLaw();
void Weight();
void Momentum();

int main()
{
  //****************************************************************************************
  vector<double> values;
  vector<string> units;
  vector<string> names;
  int vectorSize;
  char choice = '0';
  do
  {
    cout << "\n******************************************************";
    cout << "\nPhysics maths menu\n\n";
    cout << "1) velocity maths\n";
    cout << "2) acceleration maths\n";
    cout << "3) motion maths\n";
    cout << "4) Newton's second law maths\n";
    cout << "5) weight maths\n";
    cout << "6) momentum maths\n";
    cout << "7) clear screen\n";
    cout << "e or E) exit menu\n\n";

    choice = validateChar(choice);

    cout << "******************************************************";
    
    if(choice == '1')
    {
      vectorSize = 2;
      names.push_back = "change in position";
      names.push_back = "change in time";
      names.push_back = "velocity";
      Divide(vectorSize);
      
    }
    else if(choice == '2')
    Acceleration();
    else if(choice == '3')
    Motion();
    else if(choice == '4')
    NewtonsSecondLaw();
    else if(choice == '5')
    Weight();
    else if(choice == '6')
    Momentum();
    else if(choice == '7')
    system("cls");
    else if(choice == 'E' || choice == 'e')
    {
      //Exit program
      cout << "\nProgram terminated";
    }
    else
    {
      //Invalid input
      cout << "\nInvalid Input\n";
    }
  }
  while (choice != 'E' && choice != 'e');
  //********************************************************************************
  return 0;
}
/*
double Multiply(int vectorSize, vector<string> names, vector<double> values, vector<string> units)
{
  return;
}
*/
double Divide(int vectorSize, vector<string> names, vector<double> values, vector<string> units)
{
  for(int i=0; i < vectorSize; i++)
  {
    values.push_back = InputValue(names[i]);
    units.push_back = InputUnits(names[i]);
  }
  
  return;
}
/*
string concatinate(string, string)
{
  return;
}
*/
double InputValue(vector<string> &name)
{
  cout << "Please enter the " << name << ": ";
  cin >>
  return;
}
string InputUnits(vector<string> &name)
{
  return;
}
/*
void Output()
{
  
}

void Motion()//*******************************************************************************
{
  //This one has 4 options within it

  char choice = '0';
  do
  {
    double sFinal = 0.0, sInitial = 0.0, vFinal = 0.0, vInitial = 0.0, vFinalSquared = 0.0, vAvg = 0.0, a = 0.0, t = 0.0;
    cout << "\n\tMotion maths menu\n\n";
    cout << "\t1) Solve for final velocity\n";
    cout << "\t2) Solve for final position\n";
    cout << "\t3) Solve for final velocity^2\n";
    cout << "\t4) Solve for average velocity\n"; 
    cout << "\tr or R) Return to Physics maths menu\n\n\t";

    choice = validateChar(choice);

    if(choice == '1')
    {
      //solve for vFinal (need input of vInitial, acceleration, and time)
      cout << "\n\tYou chose option 1\n\n";
      cout << "\tPlease enter the initial velocity\n\t";
      vInitial = validateDouble(vInitial);
      cout << "\n\tPlease enter the acceleration\n\t";
      a = validateDouble(a);
      cout << "\n\tPlease enter the time\n\t";
      t = validateDouble(t);

      vFinal = (vInitial + (a * t));

      cout << "\n\t" << fixed << setprecision(4) << vFinal << " = (" << vInitial << " + (" << a << " x " << t << "))";
      cout << "\n\tThe final velocity is " << vFinal << "\n\n";
    }
    else if(choice == '2')
    {
      //solve for sFinal (need input of sInital, vInitial, time, and acceleration)
      cout << "\n\tYou chose option 2\n\n";
      cout << "\tPlease enter the initial position\n\t";
      sInitial = validateDouble(sInitial);
      cout << "\n\tPlease enter the initial velocity\n\t";
      vInitial = validateDouble(vInitial);
      cout << "\n\tPlease enter the time\n\t";
      t = validateDouble(t);
      cout << "\n\tPlease enter the acceleration\n\t";
      a = validateDouble(a);

      sFinal = (sInitial + (vInitial * t) + (.5 * a * (t * t)));

      cout << "\n\t" << fixed << setprecision(4) << sFinal << " = (" << sInitial << " + (" << vInitial << " x " << t << ") + ((1/2) x " << a << " x (" << t << " x " << t << ")))";
      cout << "\n\tThe final position is " << sFinal << "\n\n";
    }
    else if(choice == '3')
    {
      //solve for vFinal^2 (need input of vInitial, acceleration, sInitial, and sFinal)
      cout << "\n\tYou chose option 3\n\n";
      cout << "\n\tPlease enter the initial velocity\n\t";
      vInitial = validateDouble(vInitial);
      cout << "\n\tPlease enter the acceleration\n\t";
      a = validateDouble(a);
      cout << "\tPlease enter the initial position\n\t";
      sInitial = validateDouble(sInitial);
      cout << "\tPlease enter the final position\n\t";
      sFinal = validateDouble(sFinal);

      vFinalSquared = ((vInitial * vInitial) + (2 * a * (sFinal - sInitial)));

      cout << "\n\t" << fixed << setprecision(4) << vFinalSquared << " = ((" << vInitial << " x " << vInitial << ") + (2 x " << a << " x (" << sFinal << " - " << sInitial << "))";
      cout << "\n\tThis final velocity^2 is " << vFinalSquared << "\n\n";
    }
    else if(choice == '4')
    {
      //solve for vAvg (need input of vInitial and vFinal)
      cout << "\n\tYou chose option 4\n\n";
      cout << "\n\tPlease enter the initial velocity\n\t";
      vInitial = validateDouble(vInitial);
      cout << "\n\tPlease enter the final velocity\n\t";
      vFinal = validateDouble(vFinal);

      vAvg = (.5 * (vFinal + vInitial));

      cout << "\n\t" << fixed << setprecision(4) << vAvg << " = ((1/2) x (" << vFinal << " + " << vInitial << "))";
      cout << "\n\tThe average velocity is " << vAvg << "\n\n";
    }
    else if(choice == 'r' || choice == 'R')
    {
      //End program
      cout << "\n\tReturned to Physics maths menu\n";
    }
    else
    {
      //Invalid input
      cout << "\n\tInvalid Input\n\n";
    }
  }
  while (choice != 'r' && choice != 'R');
}
*/