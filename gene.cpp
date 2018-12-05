/*	Project:    Gene Analyzer - Assignment #5
	Name:       Lisa Robleski
    Class:      CSC 1810 - Section 3
*/

#include <iostream>
#include <string>
using namespace std;

#include "allele.h"
#include "gene.h"

Gene::Gene()
{
	name = "abc123";
	traitType = "none";
}

Gene::Gene(Allele initialA, Allele initialB)
{
	this->alleleA = initialA;
	this->alleleB = initialB;
}

void Gene::SetNameTrait(string geneName, string geneTrait)
{
	name = geneName;
	traitType = geneTrait;
}