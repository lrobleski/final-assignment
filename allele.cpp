/*	Project:    Gene Analyzer - Assignment #5
	Name:       Lisa Robleski
    Class:      CSC 1810 - Section 3
*/

#include <iostream>
#include <string>
using namespace std;

#include "allele.h"

Allele::Allele()
{
	variant = "none";
	type = "none";
	sequence = "none";
}

void Allele::SetAllele(string aVariant, string aType, string aSequence)
{
	variant = aVariant;
	type = aType;
	sequence = aSequence;
}
