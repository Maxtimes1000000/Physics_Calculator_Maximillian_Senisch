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

using namespace std;

void Velocity();
void Acceleration();
void Motion();
void NewtonsSecondLaw();
void Weight();
void Momentum();

int main()
{
  //****************************************************************************************

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
    Velocity();
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

void Velocity()//*******************************************************************
{
  double ds = 0.0, dt = 0.0, V = 0.0;
  string dsUnits;
  string dtUnits;
  string vUnits;

  cout << "\nVelocity maths\n\nDue to the inability of C++ to easily take in functions this option will only calculate the average velocity";
  cout << "\n\nPlease enter (Δs)\n";
  ds = validateDouble(ds);
  cout << "\n\nPlease enter the units for (Δs)\n";
  dsUnits = validateString(dsUnits);

  do
  {
    cout << "\n\nPlease enter (Δt) greater than zero\n";
    dt = validateDouble(dt);
  }
  while(dt <= 0.0);

  cout << "\n\nPlease enter the units for (Δt)\n";
  dtUnits = validateString(dtUnits);

  V = ds/dt;
  vUnits = dsUnits + "/" + dtUnits;

  cout << fixed << setprecision(4) << "\n" << ds << " " << dsUnits << " / " << dt << " " << dtUnits << " = " << V << " ";
  cout << vUnits << endl;
}
void Acceleration()//**************************************************************************
{
  double dv = 0.0, dt = 0.0, A = 0.0;
  string dvUnits;
  string dtUnits;
  string aUnits;

  cout << "\nAcceleration maths\n\nDue to the inability of C++ to easily take in functions this option will only calculate the average acceleration";
  cout << "\n\nPlease enter (Δv)\n";
  dv = validateDouble(dv);
  cout << "\n\nPlease enter the units for (Δv)\n";
  dvUnits = validateString(dvUnits);

  do
  {
    cout << "\n\nPlease enter (Δt) greater than zero\n";
    dt = validateDouble(dt);
  }
  while(dt <= 0.0);

  cout << "\n\nPlease enter the units for (Δt)\n";
  dtUnits = validateString(dtUnits);

  A = dv/dt;
  aUnits = dvUnits + "/" + dtUnits;

  cout << fixed << setprecision(4) << A << " ";
  cout << aUnits << endl;
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
void NewtonsSecondLaw()//**************************************************************************
{
  double m = 0.0, a = 0.0, N = 0.0;
  string mUnits;
  string aUnits;
  string NUnits;

  cout << "\n\tNewton's Second law maths\n\n";
  cout << "\n\tPlease enter the mass\n\t";
  m = validateDouble(m);
  cout << "\n\tPlease enter the units for mass;\n\t";
  mUnits = validateString(mUnits);
  cout << "\n\tPlease enter the acceleration\n\t";
  a = validateDouble(a);
  cout << "\n\tPlease enter the units for acceleration;\n\t";
  aUnits = validateString(aUnits);

  N = m*a;

  NUnits = mUnits + " " + aUnits;

  cout << "\n\t" << fixed << setprecision(4) << N << " = (" << m << " x " << a << ")\n";
  cout << "\tThe force is " << N << "\n\n";
}
void Weight()//******************************************************************************
{
  double m = 0.0, g = 0.0, W = 0.0;
  string mUnits;
  string gUnits;
  string WUnits;

  cout << "\n\tWeight maths\n\n";
  cout << "\n\tPlease enter the mass\n\t";
  m = validateDouble(m);
  cout << "\n\tPlease enter the units for mass;\n\t";
  mUnits = validateString(mUnits);
  cout << "\n\tPlease enter the gravitational acceleration\n\t";
  g = validateDouble(g);
  cout << "\n\tPlease enter the units for gravitaional acceleration;\n\t";
  gUnits = validateString(gUnits);

  W = m*g;

  WUnits = mUnits + " " + gUnits;

  cout << "\n\t" << fixed << setprecision(4) << W << " = (" << m << " x " << g << ")\n";
  cout << "\tThe weight is " << W << WUnits << "\n\n";
}
void Momentum()//****************************************************************************
{
  double m = 0.0, v = 0.0, P = 0.0;
  string mUnits;
  string vUnits;
  string PUnits;

  cout << "\n\tMomentum maths\n\n";
  cout << "\n\tPlease enter the mass\n\t";
  m = validateDouble(m);
  cout << "\n\tPlease enter the units for mass;\n\t";
  mUnits = validateString(mUnits);
  cout << "\n\tPlease enter the velocity\n\t";
  v = validateDouble(v);
  cout << "\n\tPlease enter the units for velocity;\n\t";
  vUnits = validateString(vUnits);

  P = m*v;

  PUnits = mUnits + " " + vUnits;

  cout << "\n\t" << fixed << setprecision(4) << P << " = (" << m << " x " << v << ")\n";
  cout << "\tThe momentum is " << P << "\n\n";
}