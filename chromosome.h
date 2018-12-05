/*	Project:    Gene Analyzer - Assignment #5
	Name:       Lisa Robleski
    Class:      CSC 1810 - Section 3
*/

#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <string>
#include <vector>

#include "allele.h"
#include "gene.h"

class Chromosome
{
  public:
	// Chromosome(); FIXME: How to define a constructor for a class with a vector?
	void AddGene(Gene g);
	// Gene FindGene(string n); FIXME: When would this be used? What menu option calls it?
	void AnalyzeGenotype();
	void InputToFile(string fileName);
	void OutputToFile(string fileName);
	// Chromosome operator+(Chromosome rhs);
	// bool RunUnitTests();

  private:
	vector<Gene> genes;
	string fileName;
};

#endif