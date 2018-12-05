/*	Project:    Gene Analyzer - Assignment #5
	Name:       Lisa Robleski
    Class:      CSC 1810 - Section 3
*/

#ifndef ALLELE_H
#define ALLELE_H

#include <string>

class Allele
{
  public:
	Allele();
	void SetAllele(string aVariant, string aType, string aSequence);
	string GetVariant() const { return variant; }
	string GetType() const { return type; }
	string GetSequence() const { return sequence; }

  private:
	string variant;
	string type;
	string sequence;
};

#endif