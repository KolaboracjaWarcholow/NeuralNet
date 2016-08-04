#ifndef FUNCTIONS_FOR_FILES_H
#define FUNCTIONS_FOR_FILES_H
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <new>
#include <cstdio>
using namespace std;
void LoadInLearningSet(vector<vector<double>> &trainingSet, const int NumberOfInputNeurons)
{
	ifstream myFile;
	string NamePart = "LearningData";
	string txtPart = ".txt";
	string FolderPart = "LearningSet\\";
	string FilePath;
	string line;
	string Value1 = "\t0.1";
	string Value9 = "\t0.9";
	int i = 1;
	string SetNumber = to_string(i);
	FilePath = FolderPart + NamePart + SetNumber + txtPart;
	myFile.open(FilePath);
	while (myFile.is_open())
	{
		while (!myFile.eof())
		{
			vector<double> LetterData;
			while (LetterData.size() < NumberOfInputNeurons)
			{
				getline(myFile, line);
				if (line == Value1)
				{
					LetterData.push_back(0.1);
				}
				else if (line == Value9)
				{
					LetterData.push_back(0.9);
				}
				if (line == "")
					break;
			}
			if (line == "")
				break;
			trainingSet.push_back(LetterData);

		}
		i++;
		if (i == 125)
			i = 151;
		if (i == 166)
			i = 251;
		myFile.close();
		SetNumber = to_string(i);
		FilePath = FolderPart + NamePart + SetNumber + txtPart;
		myFile.open(FilePath);
	}
}
void LoadInDesiredOutputs(vector<vector<double>> &DesiredOutputs, const int NumberOfOutputNeurons, const char *filepath)
{
	ifstream myFile;
	string line = "";
	string Value1 = "\t0.1";
	string Value9 = "\t0.9";
	myFile.open(filepath);
	if (!myFile.is_open())
		cout << "Something went wrong with desired outputs file!" << endl;
	while (!myFile.eof())
	{
		vector<double> LetterOutput;
		while (LetterOutput.size() < NumberOfOutputNeurons)
		{
			getline(myFile, line);
			if (line == Value1)
				LetterOutput.push_back(0.1);
			else if (line == Value9)
				LetterOutput.push_back(0.9);
		}
		DesiredOutputs.push_back(LetterOutput);
	}
	myFile.close();
}
void PrintErrorsToFile(const char *filepath, std::vector<double> &ErrorsVector)
{
	ofstream ErrorsFile;
	ErrorsFile.open(filepath, ios::trunc);
	for (unsigned int i = 0; i < ErrorsVector.size(); i++)
	{
		ErrorsFile << ErrorsVector[i] << endl;
	}
	ErrorsFile.close();
}
#endif
