// Programming Challenge: Monkey Business
#include <iostream>
#include <iomanip>
using namespace std;

// Constant for the number of monkeys
const int MONKEYS = 3;
//Constant for the number of days
const int DAYS = 5;

// Function prototypes
void displayDailyAvg(double[][DAYS]); //Displays average per day
void displayLeastFood(double[][DAYS]); //Displays the monkey and day with the least food
void displayMostFood(double[][DAYS]); //Displays the monkey and day with the most food

int main()
{
	// Array to hold the food data
	double food[MONKEYS][DAYS];

	// Get the amount of food eaten each day by each monkey.
	for (int monkey = 0; monkey < MONKEYS; monkey++)
	{
		for (int day = 0; day < DAYS; day++)
		{
			cout << "Enter the pounds eaten by monkey number ";
			cout << (monkey+1);
			cout << " on day ";
			cout << (day+1) << ": ";
			cin >> food[monkey][day];

			// Does not accept negative numbers.
			while (food[monkey][day] < 0)
			{
				cout << "Pounds must be 0 or more.\n"
					<< "Please re-enter: ";
				cin >> food[monkey][day];
			}
		}
	}

	cout << fixed << setprecision(5) << endl;

	//Function calls
	displayDailyAvg(food);
	displayLeastFood(food);
	displayMostFood(food);

	system("pause");
	return 0;
}

void displayDailyAvg(double pounds[][DAYS])
{
	double total = 0.0; // Accumulator

	// Step through the columns and rows of the 
	//array and add each value to total.
	for (int col = 0; col < DAYS; col++)
	{
		total = 0.0; //Reset total
		for (int row = 0; row < MONKEYS; row++)
		{
			total += pounds[row][col];

		}

		double average = total / MONKEYS;
		cout << "The average amount eaten on day ";
		cout << col+1 << " is ";
		cout << average;
		cout << " pounds." << endl;
	}
}

void displayLeastFood(double pounds [][DAYS])
{
	int leastMonkey = 0;		//To hold the row and column with the least food
	int leastDay = 0;

	// Declare variable least to hold lowest value
	// and initialize row 0 column 0 as the lowest.
	double least = pounds[0][0];

	// Compare the value in least to all the
	// other values in the array.
	for (int col = 0; col < DAYS; col++)
	{
		for (int row = 0; row < MONKEYS; row++)
		{
			if (pounds[row][col] <= least)
			{
				least = pounds[row][col];
				leastMonkey = row+1;
				leastDay = col+1;
			}
			
		}
	}
	cout << "Monkey number " << leastMonkey << " ate the least amount of food, ";
	cout << least << " pounds, on day " << leastDay << endl;
}


void displayMostFood(double pounds [][DAYS])
{

	int mostMonkey = 0;		//To hold the row and column with the most food
	int mostDay = 0;

	// Declare variable most to hold highest value
	// and initialize row 0 column 0 as highest.	
	double most = pounds[0][0];

	// Compare the value in most to all the
	// other values in the array.
	for (int col = 0; col < DAYS; col++)
	{
		for (int row = 0; row < MONKEYS; row++)
		{
			if (pounds[row][col] >= most)
			{
				most = pounds[row][col];
				mostMonkey = row+1;
				mostDay = col+1;
			}

		}
	}
	cout << "Monkey number " << mostMonkey << " ate the most amount of food, ";
	cout << most << " pounds, on day " << mostDay << endl;
}