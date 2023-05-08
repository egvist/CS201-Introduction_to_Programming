


// Baris Baran Aydogan 


#include <iostream>
#include <string>
#include "strutils.h"
using namespace std;

bool controltheinput(string word);
string Secret(string word);
string updatesecret(string , char , string );
void whichpartofbody(int, string);
bool letterornot(string , string );
bool charornot(string);
bool repetitive(string);
bool alphaornot(char);

bool controltheinput(string word) 
{
    bool boolean = true;
    int len = word.length();
    for (int index = 0; index < len ; index++ ) 
	{
        
        char ch = word.at(index);
        
        if (!(alphaornot(ch))) 
		{
            boolean = false;

        }

    }
    
    return boolean;
}

string Secret(string word) 
{
	int len = word.length();
	string secretword;
	for (int i = 0 ; i < len ; i++) 
	{

		secretword += "-";
		
	}
	return secretword;

}

string updatesecret(string decidedword, string guess, string secret)
{
	
	for (int lenword = decidedword.length(), index = 0 ; index < lenword; index++ )
	{
	
		if (guess.at(0) == decidedword.at(index))
		{
		
			secret[index] = guess.at(0);

		}
	
	}
	
	return secret;

}

void whichpartofbody(int howmanyguess, string player2)
{
	if (howmanyguess == 5)
	{
		cout << "You have lost a leg!" << endl;
	}
	else if (howmanyguess == 4)
	{
		cout << "You have lost a leg!" << endl;
	}
	else if (howmanyguess == 3)
	{
		cout << "You have lost an arm!" << endl;
	}
	else if (howmanyguess == 2)
	{
		cout << "You have lost an arm!" << endl;
	}
	else if (howmanyguess == 1)
	{
		cout << "You have lost a head! GAME OVER!" << endl;
		cout << player2 << " lost the game :(";
	}


}

bool letterornot(string guess, string decidedword) 
{
	if ((guess.find(" ") != string::npos) || (guess.length() > decidedword.length() ))
	{
		return false;
	
	}
	
	else 
	{
		if ((controltheinput(guess) == true))
		{
		
			return true;
		}
		else
		{
		
			return false;

		}
			

	
	}

}

bool charornot(string guess) 
{
	
	if ((guess.length() == 1) && (controltheinput(guess) == true))
	{
		return true;
	}
	else 
	{
		
		return false;
	
	}


}

bool repetitive(string guess, string repet)
{
	
	for (int lenrepet = repet.length(), index = 0; index < lenrepet; index++)
	{
	
		if (guess.at(0) == repet.at(index))
		{
			return true;
			break;
		
		}

	}


	repet += guess.at(0);

	return false;


}

bool alphaornot(char guess)
{
	
	if ((guess >= 'a' && guess <= 'z') || ((guess >= 'A' && guess <= 'Z' )))
	{
	
		return true;
	
	
	}

	else
	{
	
		return false;
	}
		
}


int main() 
{
string repet = ".";
string player1,player2, decidedword;
string choose;
string guess;

cout << "Welcome to the HANGMAN GAME" << endl;
cout << "---------------------------" << endl;
cout << "Player one, please enter your name: ";
cin >> player1 ;
cout << "Player two, please enter your name: ";
cin >> player2 ;
cout << "OK " << player1 << " and " << player2 << ". Let's start the game!" << endl;
cout << player1 << ", please input the word you want " << player2 << " to guess: ";
cin >> decidedword;
LowerString(decidedword);


while (controltheinput(LowerString(decidedword)) != true) 
{

    cout << "Invalid word! Try again." << endl;
    cout << player1 << ", please input the word you want " << player2 << " to guess: "; 
    cin >> decidedword;  
} 

decidedword = LowerString(decidedword);
string thesecretone = Secret(decidedword);


cout << player2 << ", you have 1 free guess, after that you will lose limbs!" << endl;
cout << "The word is: " << thesecretone << endl;

int howmanyguess = 7;
while ((howmanyguess != 1) && (thesecretone != decidedword))
{

	cout << player2 << ", do you want to guess the word(1) or guess a letter(2)? ";
	cin >> choose;

	if ((choose == "1") || (choose == "2"))
	{
		cout << "Your guess: ";
		cin >>  guess;
		guess = LowerString(guess);
		if (choose == "1" )
		{
			if (letterornot(guess,decidedword))
			{
			
				if (guess == decidedword)
				{
					thesecretone = LowerString(decidedword);
					cout << "The word is: " << thesecretone << endl;
					cout << "Congratulations " << player2 << ", you won!" << endl;
					cout << player2 << " won the game!" ;
					break;
				
				}

				else
				{
					
					if (howmanyguess == 7)
					{
					
						
						
						howmanyguess -= 1;
						cout << "You have no free guess left." << endl;
						cout << "The word is: " << thesecretone << endl;
							
						
					}

					else 
					{
						howmanyguess -= 1;
						if (howmanyguess == 1)
						{

							whichpartofbody(howmanyguess, player2);
							

						}
						else
						{

							whichpartofbody(howmanyguess, player2);
							cout << "The word is: " << thesecretone << endl;

						}

					}
				
				}
			
			}
			else 
			{
				cout << "Invalid entry! Try again." << endl;
				cout << "The word is: " << thesecretone << endl;
			
			}
		
		
		}
		else
		{
		
			if (charornot(guess))
			{
				
				
				if (howmanyguess == 7)
				{
				
					if (decidedword.find(guess[0]) == string::npos)
					{
						howmanyguess -= 1;
						cout << "You have no free guess left." << endl;
						cout << "The word is: " << thesecretone << endl;
						repet += guess;
						
					
					}

					else
					{
						
						thesecretone = updatesecret(decidedword, guess, thesecretone);
						cout << "The word is: " << thesecretone << endl;
						if (thesecretone == decidedword)
							{
								cout << "Congratulations " << player2 << ", you won!" << endl;
								cout << player2 << " won the game!";
							}
						repet += guess;

					}
					
					
				



				}
				
				else
				{


					if (repetitive(guess, repet) == false)
					{
					
					
						if (decidedword.find(guess) == string::npos)
						{
							howmanyguess -= 1;
							repet += guess;
							if (howmanyguess == 1)
							{
								whichpartofbody(howmanyguess, player2);
							
							}
							else 
							{
								whichpartofbody(howmanyguess, player2);
								cout << "The word is: " << thesecretone << endl;

							}

						
						}
						else
						{
							
							thesecretone = updatesecret(decidedword, guess, thesecretone);
							
							
							if (thesecretone == decidedword)
							{
								cout << "The word is: " << thesecretone << endl;
								cout << "Congratulations " << player2 << ", you won!" << endl;
								cout << player2 << " won the game!";
								
						
							

							}
							else
							{
								
								cout << "The word is: " << thesecretone << endl;
								
								repet += guess;
							
							
							
							}
					
					
						}

					}

					else 
					{
					
						cout << "Guess entered before! Try again." << endl;
						cout << "The word is: " << thesecretone << endl;
					
					}

					
					


						
				}
				
				
				
				


			
			}
			else 
			{
			
				cout << "Invalid entry! Try again." << endl;
				cout << "The word is: " << thesecretone << endl;
			
			}
		
		
		}
	
	
	}

	else 
	{
		cout << "Invalid option!" << endl;
		cout << "The word is: " << thesecretone << endl;
	
	}


}


return 0;

}

