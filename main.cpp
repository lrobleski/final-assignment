/*	Project:    Gene Analyzer - Assignment #5
	Name:       Lisa Robleski
    Class:      CSC 1810 - Section 3
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "allele.h"
#include "gene.h"
#include "chromosome.h"

// Prints the menu
void PrintMenu()
{
	cout << "MENU" << endl
		 << endl;
	cout << "1 – Create chromosome" << endl;
	cout << "2 – Analyze chromosome" << endl;
	cout << "3 – Output chromosome to file" << endl;
	cout << "4 – Input chromosome from file" << endl;
	cout << "5 – Combine chromosomes" << endl;
	cout << "6 – Exit" << endl
		 << endl;
	cout << "Please enter your choice (1-6): ";
}

int main(int argc, char *argv[])
{
	int menuChoice = 0;
	char geneLoop = 'y';

	string newName = "not set";
	string newTrait = "not set";
	string newVariant = "not set";
	string newSequence = "not set";
	string newType = "not set";

	string outputFileName = "output.txt";
	string inputFileName = "input.txt";
	string fullInputString = "empty";

	Allele currentAllele;
	Gene currentGene;

	Chromosome chromosomeX;
	Chromosome chromosomeY;
	Chromosome chromosomeC;

	ifstream inFS;

	while (menuChoice != 6)
	{

		PrintMenu();
		cin >> menuChoice;
		cin.get();

		// Create Chromosome: Collects info for a Chromosome record
		if (menuChoice == 1)
		{
			while (geneLoop == 'y')
			{
				//Set Gene name and Gene Trait
				cout << "What is the name of the new gene? (e.g. TZ458)" << endl;
				getline(cin, newName);
				cout << "What is the gene trait? (e.g. eye color)" << endl;
				getline(cin, newTrait);
				currentGene.SetNameTrait(newName, newTrait);

				//Set Gene Alleles
				for (int i = 1; i < 3; ++i)
				{
					cout << "What is the allele " << i << " variant? (e.g. brown/blue/etc.)" << endl;
					getline(cin, newVariant);
					cout << "Is allele " << i << " a dominant type? (indicate yes or no)" << endl;
					getline(cin, newType);
					if (newType == "yes")
					{
						newType = "Dominant";
					}
					else
					{
						newType = "Recessive";
					}
					cout << "What is allele " << i << " nucleotide sequence? (e.g.AGTC)" << endl;
					getline(cin, newSequence);

					currentAllele.SetAllele(newVariant, newType, newSequence);

					if (i == 1)
					{
						currentGene.SetAlleleA(currentAllele);
					}
					else
					{
						currentGene.SetAlleleB(currentAllele);
					}
				}
				// Add gene to chromosome
				chromosomeX.AddGene(currentGene);
				chromosomeY = chromosomeX;

				cout << "Your gene has been added." << endl;

				cout << "Would you like to add another gene? Select y to continue or n to return to the menu" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> geneLoop;
			}
		}

		// Analyze Chromosome

		else if (menuChoice == 2)
		{
			chromosomeX.AnalyzeGenotype();
		}

		// Output Chromosome to file

		else if (menuChoice == 3)
		{
			cout << "What file would you like to export to?" << endl;
			getline(cin, outputFileName);
			chromosomeX.OutputToFile(outputFileName);
		}

		else if (menuChoice == 4)
		{
			cout << "What is the import filename?" << endl;

			getline(cin, inputFileName);
			cout << "Opening file " << inputFileName << endl;

			inFS.open(inputFileName);
			if (!inFS.is_open())
			{
				cout << "Could not open file " << inputFileName << endl;
			}
			else
			{
				inFS >> fullInputString;

				cout << "Closing file " << inputFileName << endl;
				inFS.close();
			}
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}
	// This causes the program to pause at its completion.
	{
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}