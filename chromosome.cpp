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

//Chromosome::Chromosome() {filename = "not_set.txt";} FIXME: How to define a constructor for a class with a vector?

void Chromosome::AddGene(Gene g) { genes.push_back(g); }

void Chromosome::AnalyzeGenotype()
{
	for (unsigned int i = 0; i < genes.size(); ++i)
	{
		Gene tempGene;
		Allele tempAlleleA;
		Allele tempAlleleB;
		Allele domAllele;
		string tempType;

		tempGene = genes.at(i);
		tempAlleleA = tempGene.GetAlleleA();
		tempAlleleB = tempGene.GetAlleleB();
		tempType = tempAlleleA.GetType();

		if (tempType == "Dominant")
		{
			domAllele = tempAlleleA;
		}
		else
		{
			domAllele = tempAlleleB;
		}

		cout << "Gene " << i + 1 << endl;
		cout << "Name: " << tempGene.GetName() << endl;
		cout << "Genetic Trait: " << tempGene.GetTrait() << endl;
		cout << "Expressed Allele: " << domAllele.GetVariant() << " -- " << domAllele.GetType() << endl;
		cout << "Nucleotide Sequence:" << domAllele.GetSequence() << endl;
	}
}

void Chromosome::OutputToFile(string fileName)
{
	Gene tempGene;
	Allele tempAllele;
	ofstream outFS;

	outFS.open(fileName);

	if (!outFS.is_open())
	{
		cout << "Could not open file " << fileName << endl;
	}

	for (unsigned int i = 0; i < genes.size(); ++i)
	{
		tempGene = genes.at(i);

		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
			{
				tempAllele = tempGene.GetAlleleA();
			}
			else
			{
				tempAllele = tempGene.GetAlleleB();
			}
			outFS << tempGene.GetName() << "," << tempGene.GetTrait() << ",";
			outFS << tempAllele.GetVariant() << "," << tempAllele.GetType() << "," << tempAllele.GetSequence() << endl;
		}
	}

	outFS.close();

	cout << "Output action complete." << endl;
}

// void Chromosome::InputToFile(string fileName) {}