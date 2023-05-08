#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "strutils.h"
using namespace std;


struct reservations
	{
		int sailorid, boatcode;
		string name, boatname, boatcolour, reservationdate;
		double age, sailorrank;
	
	};




int main()
{

	
	string boatsfile = "Boats.txt";
	string sailorsfile = "Sailors.txt";
	string reservesfile, r, b, s, reservationdatein, sailornamein, sailorlastnamein, boatcolorin, boatnamein;
	ifstream inputreservefile, inputboatsfile, inputsailorsfile;
	int sailoridin, boatcodein;
	double sailorrankin, sailoragein;
	cout << "Enter filename for reservation database: ";
	cin >> reservesfile;

	inputreservefile.open(reservesfile.c_str());
	if (inputreservefile.fail())
	{
	
		cout << "Cannot open the files. Exiting..." << endl;
	
	}
	
	else
	{
		int rlinenumber = -1;
		
		
		vector<reservations> info(5);
		vector<reservations> sortedinfo(5);
		

		while (getline(inputreservefile,r))
		{
			istringstream rinput(r);
			
		
			if (rlinenumber > -1)
			{
			
				rinput >> sailoridin >> boatcodein >> reservationdatein;
				
				info[rlinenumber].sailorid = sailoridin;
				info[rlinenumber].boatcode = boatcodein;
				info[rlinenumber].reservationdate = reservationdatein;


			}

			rlinenumber += 1;
		
		}
		

		inputreservefile.close();

		inputboatsfile.open(boatsfile.c_str());
		int blinenumber = -1;
		while (getline(inputboatsfile,b))
		{
	
		

			istringstream binput(b);

			if (blinenumber > -1)
			{

				binput >> boatcodein >> boatnamein >> boatcolorin;
				for (int i = 0 ; i < 5; i++ )
				{
			
					if (info[i].boatcode == boatcodein)
					{
					
						info[i].boatname = boatnamein;
						info[i].boatcolour = boatcolorin;

					}
			
			
				}
		
			}
			blinenumber += 1;

			
	
		}
		inputboatsfile.close();



		inputsailorsfile.open(sailorsfile.c_str());
		int slinenumber = -1;
		while (getline(inputsailorsfile, s))
		{
			istringstream sinput(s);

			if (slinenumber > -1)
			{
				sinput >> sailoridin >> sailornamein >> sailorrankin >> sailoragein;
				for (int i = 0; i < 5; i++)
				{
					if (info[i].sailorid == sailoridin)
					{
						
						info[i].sailorrank = sailorrankin;
						info[i].age = sailoragein;
						info[i].name = sailornamein;

					}
				
				}
				
			}
			slinenumber += 1;
		}
		inputsailorsfile.close();

		
		string temp,s2,s1;
		
		for (int i = 0; i < info.size(); i++)
		{
			
			for (int j = i+1; j < info.size();j++)
			{
			
				if (info[i].reservationdate > info[j].reservationdate)
				{
				
						reservations temp = s1;
						s1 = s2;
						s2 = temp;
				
				}

				else if (info[i].reservationdate == info[j].reservationdate)
				{
				
					if (info[i].name > info[j].name)
					{
						
						reservations temp = s1;
						s1 = s2;
						s2 = temp;
					
					}
				
				}
				
			
			}
		
		}



		for (int i = 0 ; i < 5; i++ )
		{
			
			
			cout << info[i].reservationdate << " -> " << info[i].name <<"(" << info[i].age << "," << info[i].sailorrank << ")" << " has reserved " << info[i].boatname << "(" << info[i].boatcolour << ")" << endl;
			
		
		}
		







		



	
	}
	

	


	return 0;



}