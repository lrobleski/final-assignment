/*	Project:    Gene Analyzer - Assignment #5
	Name:       Lisa Robleski
    Class:      CSC 1810 - Section 3
*/

#ifndef GENE_H
#define GENE_H

#include <string>

#include "allele.h"

class Gene
{
  public:
	Gene();
	Gene(Allele initialA, Allele initialB);
	void SetNameTrait(string geneName, string geneTrait);
	void SetAlleleA(Allele firstAllele) { alleleA = firstAllele; }
	void SetAlleleB(Allele secondAllele) { alleleB = secondAllele; }
	Allele GetAlleleA() const { return alleleA; }
	Allele GetAlleleB() const { return alleleB; }
	string GetName() const { return name; }
	string GetTrait() const { return traitType; }

  private:
	string name;
	string traitType;
	Allele alleleA;
	Allele alleleB;
};

#endif