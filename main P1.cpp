/*
 *  main.cpp
 *
 * COSC 051 Spring 2019
 * Project #1 (Code) 
 *
 * Due on: February 13, 2019
 * Author: vl208 
 *
 *
 * In accordance with the class policies and Georgetown's
 * Honor Code, I certify that, with the exception of the
 * class resources and those items noted below, I have neither
 * given nor received any assistance on this project. 
 *
 * References not otherwise commented within the program source code.
 * Note that you should not mention any help from the TAs, the professor, 
 * or any code taken from the class textbooks.
 */

#include <iostream>		// Header file needed to use stream manipulator 
#include <string>		// Header file needed to use string objects
#include <iomanip>		// Header file needed to input output manipulator 

using namespace std;

//global constants
const double PRICE_PER_POUND_PACKING_TYPE_B = 0.065;
const double PRICE_PER_POUND_PACKING_TYPE_W = 0.256;
const double PRICE_PER_POUND_PACKING_TYPE_C = 0.459;
const double PRICE_PER_MILE_TYPE_B = 0.0011;
const double PRICE_PER_MILE_TYPE_W = 0.0011;
const double PRICE_PER_MILE_TYPE_C = 0.0012;
const double MINIMUM_NUMBER_OF_MILES = 1;
const double MAXIMUM_NUMBER_OF_MILES = 3200;
const double MINIMUM_WEIGHT = 1200;
const double MAXIMUM_WEIGHT = 18000;
const int MAXIMUM_NUMBER_OF_PIANOS = 3;
const double FEE_OVER_15_STAIRS = 132.00;
const double FEE_PIANO = 275.00;
const double FEE_PIANO_AND_STAIRS_ONCE = 575.00;
const double FEE_PIANO_AND_STAIRS_TWICE = 1075.00;


int main()
{
	//variables 
	char typeOfMove = ' ';
	double milesDriven = 0.0;
	double weightOfItemsMoved = 0.0;
	double minimumWeight = 0.0;
	double numberOfPianosMoved = 0.0;
	char stairsOrigin = ' ';
	char stairsDest = ' ';
	double costOfPacking = 0.0;
	double costOfDistanceDriven = 0.0;
	double surcharge = 0.0;
	double totalCost = 0.0;
	string nameOfMove = " ";

	cout << "Welcome to the BHMSI Moving price calculator!" << endl; // greeting message

	// Initial input for type of move that will be selected
	cout << "Please enter the type of move (B/b– Basic, W/w- Wall Pack, C/c – Complete): ";
	cin >> typeOfMove;
	cin.ignore(1000,'\n');
	typeOfMove = toupper (typeOfMove);

	// Input validation for type of move
	if(!(typeOfMove == 'B' || typeOfMove == 'C' || typeOfMove == 'W'))	// Data Validation 
	{
		cout << "The answer entered is not valid. The program will now end, Goodbye." << endl;
		return 1;
	}

	// Input for distance that will be travelled, in miles
	cout << "Please enter the distance from origin to destination [1, 3200]: ";
	cin >> milesDriven;

	// data validation
	if (milesDriven < MINIMUM_NUMBER_OF_MILES)
	{
		milesDriven = MINIMUM_NUMBER_OF_MILES;
		cout << "The distance entered is less than the minimum of 1 mile. We will continue to ";
		cout << "price this moving using the minimum distance of 1 mile." << endl;
	}

	// data validation 
	if (milesDriven > MAXIMUM_NUMBER_OF_MILES)
	{
		cout << "The distance entered exceeds BHSMI’s maximum of 3200 miles. Please refer this ";
		cout << "customer to BBMSI. The program will now end, Goodbye." << endl;
		return 1;
	}

	// check for condition 
	if (milesDriven > 0 && milesDriven < 600) 
	{
		minimumWeight = MINIMUM_WEIGHT;
		cout << "The minimum weight you can choose for a move of" << milesDriven << " is 1200 ";
		cout << "pounds. We will then continue to price this move using the minimum weight ";
		cout << "of 1200."  <<endl;
	}
	else if (2*milesDriven > MINIMUM_WEIGHT)
	{
		minimumWeight= 2*milesDriven;
		cout << "The minimum weight allowed is either 1200 pounds or twice the number of miles ";
		cout << "driven, whichever is greater. In this case, twice the number of miles is ";
		cout << "greater than the minimum weight of 1200 pounds. We will then continue to price ";
		cout << "this move using twice the number of miles as the weight of items moved" << endl;
	}

	// Input for weight of contents that will be moved
	cout << "Please enter the weight of contents to move [" << minimumWeight << ", ";
	cout << MAXIMUM_WEIGHT << ": ";
	cin >> weightOfItemsMoved;

	// check for condition
	if (weightOfItemsMoved < minimumWeight)
	{
		weightOfItemsMoved = minimumWeight;
		cout << "The minimum weight allowed is either 1200 pounds or twice the number of ";
		cout << "miles driven, whichever is greater. In this case, twice the number of miles is ";
		cout << "less than the minimum weight of " << minimumWeight << ". We will then continue ";
		cout << "to price this move using this minimum weight." << endl;
	}

	// check for condition
	if (weightOfItemsMoved > MAXIMUM_WEIGHT)
	{
		cout << "The weight entered exceeds BHSMI’s maximum of 18000 pounds. Please refer this ";
		cout << "customer to BBMSI. The program will now end, Goodbye." << endl;
		return 1;
	}
	// This prompt looks at the fees and surcharges that will be added to the total cost
	cout << "Does the origin of this move have more than 15 stairs?: ";
	cin >> stairsOrigin;
	cin.ignore(1000,'\n');
	stairsOrigin = toupper (stairsOrigin);

	cout << "Does the destination of this move have more than 15 stairs?: ";
	cin >> stairsDest;
	cin.ignore(1000,'\n');
	stairsDest = toupper (stairsDest);
 	
 	// Data Validation 
	if (!(stairsOrigin == 'Y' || stairsOrigin == 'N'))			
	{
		cout << "The answer entered is not valid. The program will now end, Goodbye." << endl;
		return 1;
	}

	// Data Validation 
	if (!(stairsDest == 'Y' || stairsDest == 'N'))				
	{
		cout << "The answer entered is not valid. The program will now end, Goodbye." << endl;
		return 1;
	}

	// Input for number of pianos to move
	cout << "Please enter the number of pianos you would like to move: ";
	cin >> numberOfPianosMoved;

	// Data Validation 
	if (numberOfPianosMoved < 0 || numberOfPianosMoved > 3)		
	{
		cout << "The answer entered is not valid. The program will now end, Goodbye." << endl;
		return 1;
	}

	// Data Validation 
	if (numberOfPianosMoved > MAXIMUM_NUMBER_OF_PIANOS)
	{
		cout << "Note that the number of pianos entered exceeds the maximum number of pianos ";
		cout << "allowed. The program will now end, Goodbye." << endl;
		return 1;
	}

	// Data Validation 
	if (stairsOrigin == 'Y' && stairsDest == 'Y')
	{
		surcharge = numberOfPianosMoved*FEE_PIANO_AND_STAIRS_ONCE + 2*FEE_OVER_15_STAIRS;
		cout << "There are more than 15 stairs both at the origin and destination of the move. ";
		cout << "We will continue to price this move including an incurred fee of " << surcharge;
		cout << "." <<endl;
	}

	else if (stairsOrigin == 'Y' || stairsDest == 'Y')
	{
		surcharge = numberOfPianosMoved*FEE_PIANO_AND_STAIRS_TWICE + FEE_OVER_15_STAIRS;
		cout << "There are more than 15 stairs at either the origin or the destination of the ";
		cout << "move. We will continue to price this move including an incurred fee of ";
		cout << surcharge << "." << endl;
	}

	else if (stairsOrigin == 'N' && stairsDest == 'N')
	{
		surcharge = numberOfPianosMoved*FEE_PIANO;
		cout << "There are NOT more than 15 stairs at either end of the move. We will continue to ";
		cout << "price this move including an incurred fee of ‘surcharge’." << endl;
	}

	//The following prompts will show the break up of the total cost
	cout << setw(25)<< "Your entries for this move are:" <<endl;
	cout << setw(10)<< typeOfMove << " - move type" <<endl;
	cout << setw(10)<< milesDriven << " - miles from origin to destination" <<endl;
	cout << setw(10)<< weightOfItemsMoved << " - total pounds of contents to move" <<endl;
	cout << setw(10)<< numberOfPianosMoved << " - total number of pianos to move" <<endl;
	cout << setw(10)<< stairsOrigin << " - there are over 15 stairs at origin" <<endl;
	cout << setw(10)<< stairsDest << " - there are over 15 stairs at destination" <<endl;

	// calculation for cost of move
	if (typeOfMove == 'B')
	{
		nameOfMove = "Basic";
		costOfPacking = PRICE_PER_POUND_PACKING_TYPE_B*weightOfItemsMoved;
		costOfDistanceDriven = PRICE_PER_MILE_TYPE_B*milesDriven;
	}

	else if (typeOfMove == 'W')
	{
		nameOfMove = "Wall Pack";
		costOfPacking = PRICE_PER_POUND_PACKING_TYPE_W*weightOfItemsMoved;
		costOfDistanceDriven = PRICE_PER_MILE_TYPE_W*milesDriven;
	}

	else if (typeOfMove == 'C')
	{
		nameOfMove = "Complete";
		costOfPacking = PRICE_PER_POUND_PACKING_TYPE_C*weightOfItemsMoved;
		costOfDistanceDriven = PRICE_PER_MILE_TYPE_C*milesDriven;
	}

	// costs added to find total cost
	totalCost = costOfPacking + costOfDistanceDriven + surcharge;

	// tabular output of costs 
	cout << setw(10)<< "Your cost for a " << nameOfMove << " move with these values is:" <<endl; 
	cout << setw(10)<< "$" << setw(10)<< fixed << setprecision(2) << costOfPacking << " - packing ";
	cout << "cost" <<endl;
	cout << setw(10)<< "$" << setw(10)<< fixed << setprecision(2) << costOfDistanceDriven << " -";
	cout << " moving cost" <<endl;
	cout << setw(10)<< "$" << setw(10)<< fixed << setprecision(2) << surcharge << " - piano ";
	cout << "surcharge + ";
	cout << "stairs surcharge" <<endl;
	cout << "---------------------------------------------------------" <<endl;
	cout << setw(10)<< "$" << setw(10)<< fixed << setprecision(2) << totalCost << " - TOTAL" <<endl;
	cout << "Your total cost for a " << nameOfMove << " move is $" << fixed << setprecision(2);
	cout << totalCost <<endl;

	cout << "Thank you for using the BHMSI price calculator" << endl; // Goodbye message 

	return 0;

} // END funtion main