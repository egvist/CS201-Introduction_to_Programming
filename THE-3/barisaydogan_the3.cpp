#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int howmany(ifstream , string );
void Greetings();



int howmany(string li, string filename)
{
	int times = 0;
	ifstream filenameinput;
	
	filenameinput.open(filename.c_str());
	while (getline(filenameinput, li))
	{
		times += 1;
	
	}
	return times;

}

 void Greetings()
 {
 
	cout << "Hello and welcome to the Hogwarts house sorting hat program!" << endl;
	cout << "When I call your name, you'll come forth, I shall place the sorting hat on your head, and you will be sorted into your houses." << endl;

 
 
 }







int main()
{
	string word;
	ifstream filenameinput;
	ifstream answerKeyinput;
	string filename;
	string answerKey;
	string name, surname;
	bool a = true;
	int sum;
	
	Greetings();


	cout << "Enter the name of the key file: " ;
	cin >> answerKey;
	answerKeyinput.open(answerKey.c_str());

	while(a)
	{
		if (answerKeyinput.fail())
		{
		
			cout << "Error: Cannot open file " << answerKey << endl;;
			cout << "Enter the name of the key file: ";
			cin >> answerKey;
			answerKeyinput.open(answerKey.c_str());
		
		}
		else 
		{
			cout << "Enter the name of the answer file: ";
			cin >> filename;
		
			filenameinput.open(filename.c_str());

			while(a)
			{
				if (filenameinput.fail())
				{
					cout << "Error: Cannot open file " << filename << endl;
					cout << "Enter the name of the answer file: ";
					cin >> filename;
					filenameinput.open(filename.c_str());
		
				}
	
				else
				{
					a = false;
					
				}
	
			}
				
		}
	
	}
	



	

	

	
	

	
	
	
	while (!filenameinput.eof())
	{
		
		string li;
		string useranswerstring;
		string answer;
		
		while (getline(filenameinput, li))
		{
			
			if (li != "" &&  li != "\r" )
			{
			
				sum  = 0;
				int questionnumber = 1;
				int i = 1;
				istringstream useranswers(li);
				useranswers >> name >> surname;

				while (useranswers >> useranswerstring)
				{
				
					string line;
					getline(answerKeyinput, line);
				
				
					istringstream realanswers(line);
				
				

				
					int point = 1;
					
				
					if (i == questionnumber)
					{
						while (realanswers >> answer)
						{

						
						

								if (answer == useranswerstring)
								{
							
									sum += point;

								}
							
						
						
							point += 1;
						}
					
					}

					i += 1;
				
			
					questionnumber += 1;
				
				}
				

				string legionname;

				if (sum < 10)
				{
	
					legionname =  "Hufflepuff";
	
				}
				else if (sum < 15 && sum >= 10)
				{
	
					legionname = "Ravenclaw";
	
				}
				else if (sum < 21 && sum >= 15)
				{
	
					legionname = "Gryffindor";
				}
	
				else if (sum >= 21)
				{
	
					legionname = "Slytherin";
				}

 
 

				cout << "Oh! we have "<< name << " " << surname << " under the sorting hat. " << name << ", you scored " << sum << " points, you are a " << legionname  << "!" << endl;
				
				
				answerKeyinput.seekg(0);
			
			
			
			
			
			
			}


		}




		
		
	}
	
	
	


	answerKeyinput.close();
	filenameinput.close();
	return 0;
}