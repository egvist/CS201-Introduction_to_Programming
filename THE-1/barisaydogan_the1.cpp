#include <iostream>
#include <string>
using namespace std;


void getInput(double &min, int &rep, double& liftedWeight) {
    
    if (liftedWeight==1) {
        cin >> min >> rep ;


    }
    else {

        cin >> min >> rep >> liftedWeight ;


    }
        



}

void calculateMET(int reps, string exercise, double& MET){

    if (exercise == "lunges") {
        if (reps < 15){

            MET += 3;
        }

        else if(reps >= 15 && reps < 30){

            MET += 6.5;

        }

        else if(reps >= 30) {

            MET += 10.5;

        }
    }
    else if(exercise == "pushups") {

        if (reps < 15){

            MET += 4;

        }
        else if(reps >= 15){

            MET += 7.5;

        }
        

    }
    else if(exercise == "pullups") {

        if (reps < 25){

            MET += 5;

        }
        else if(reps >= 25){

            MET += 9;
        }
    }




}

void calculateWeightMET(int reps, double liftedWeights, double& MET) {

    if (liftedWeights < 5){

        if (reps < 20){

            MET += 3;


        }
        else if(reps >= 20 && reps < 40){

            MET += 5.5;


        }
        else if(reps >= 40){

            MET += 10;

        }

    }
    else if(liftedWeights >= 5 && liftedWeights < 15){
        if (reps < 20){

            MET += 4;


        }
        else if(reps >= 20 && reps < 40){

            MET += 7.5;


        }
        else if(reps >= 40){

            MET += 12;

        }



    }
    else if(liftedWeights >= 15){

        if (reps < 20){

            MET += 5;


        }
        else if(reps >= 20 && reps < 40){

            MET += 9;


        }
        else if(reps >= 40){

            MET += 13.5;

        }





    }





}

void computeResults(double weight, double goal, int repsLunge, int repsPushUp, int repsPullUp, double WeightLift, double minLunge, double minPushUp, double minPullUp, double minWeightLift, double liftedWeight) {

    void displayResults(double difference, double total, double weight, double METlunges, double METpushups, double METpullups, double METweightlift, double caloriesburnedLunge, double caloriesburnedPushups, double caloriesburnedPullups, double caloriesburnedWeightLift);
    double caloriesburnedLunge, caloriesburnedPushups, caloriesburnedPullups, caloriesburnedWeightLift, total, difference;
    double METlunges, METpushups, METpullups, METweightlift;
    total = 0;
    METlunges = 0;
    METpushups = 0;
    METpullups = 0;
    METweightlift = 0;
    caloriesburnedLunge = 0;
    caloriesburnedPushups = 0;
    caloriesburnedPullups = 0;
    caloriesburnedWeightLift = 0;

    calculateMET(repsLunge,"lunges", METlunges);
    calculateMET(repsPushUp,"pushups", METpushups);
    calculateMET(repsPullUp,"pullups", METpullups);
    calculateWeightMET(WeightLift, liftedWeight, METweightlift);
    caloriesburnedLunge = minLunge *(METlunges*3.5*weight)/200;
    caloriesburnedPushups = minPushUp *(METpushups*3.5*weight)/200;
    caloriesburnedPullups = minPullUp *(METpullups*3.5*weight)/200;
    caloriesburnedWeightLift = minWeightLift *(METweightlift*3.5*weight)/200;
    total = caloriesburnedLunge + caloriesburnedPushups + caloriesburnedPullups + caloriesburnedWeightLift;
    difference = total - goal;
    displayResults(difference, total, weight, METlunges, METpushups, METpullups, METweightlift, caloriesburnedLunge, caloriesburnedPushups, caloriesburnedPullups, caloriesburnedWeightLift);








}

void displayResults(double difference, double total, double weight, double METlunges, double METpushups, double METpullups, double METweightlift, double caloriesburnedLunge, double caloriesburnedPushups, double caloriesburnedPullups, double caloriesburnedWeightLift ) {

    cout << "From lunges, you burned " << caloriesburnedLunge << " calories." << endl;
    cout << "From push ups, you burned " << caloriesburnedPushups << " calories." << endl;
    cout << "From pull ups, you burned " << caloriesburnedPullups << " calories." << endl;
    cout << "From weight lifting, you burned " << caloriesburnedWeightLift << " calories." << endl;
    cout << "You burned " << total << " calories." << endl << endl;

    if (difference == 0){
        cout << "Congratulations! You have reached your goal!" << endl;


    }
    else if(difference > 0){
        cout << "You have surpassed your goal! You can eat something worth "  << difference << " calories :)" << endl;


    }
    else if(difference < 0){

        cout << "You did not reach your goal by " << difference*-1 << " calories." << endl;
        cout << "You need to do lunges " << (200*(difference*-1))/(METlunges*3.5*weight) << " minutes more to reach your goal or,"<< endl;
        cout << "You need to do push ups " << (200*(difference*-1))/(METpushups*3.5*weight) << " minutes more to reach your goal or,"<< endl;
        cout << "You need to do pull ups " << (200*(difference*-1))/(METpullups*3.5*weight) << " minutes more to reach your goal or,"<< endl;
        cout << "You need to do weight lifting " << (200*(difference*-1))/(METweightlift*3.5*weight) << " minutes more to reach your goal."<< endl;





    }



}


bool inputCheck(double minlunges, double minpushups, double minpullups, int replunges, int reppushups, int reppullups, double liftedWeight, double minliftedWeight, int repliftedWeight, double weight) {

    if (weight < 30) {
        
        cout << "Weight out of range!" << endl;
        return false;
        
    }
    else if ((liftedWeight <= 0) || (liftedWeight > 35)) {

        cout << "Lifted weight out of range!" << endl;
        return false;

    }
    else if ((replunges  < 0) || (replunges > 50) ){

        cout << "Reps out of range!" << endl;
        return false;
    }
    else if ((reppushups  < 0) || (reppushups > 50) ){

        cout << "Reps out of range!" << endl;
        return false;
    }
    else if ((reppullups  < 0) || (reppullups > 50) ){

        cout << "Reps out of range!" << endl;
        return false;
    }
    else if ((repliftedWeight  < 0) || (repliftedWeight > 50) ){

        cout << "Reps out of range!" << endl;
        return false;
    }
    else if ((minlunges  < 0) || (minlunges  > 2000)){

        cout << "Minute out of range!" << endl;
        return false;

    }
    else if ((minpushups  < 0) || (minpushups  > 2000)){

        cout << "Minute out of range!" << endl;
        return false;

    }
    else if ((minpullups  < 0) || (minpullups  > 2000)){

        cout << "Minute out of range!" << endl;
        return false;

    }
    else if ((minliftedWeight  < 0) || (minliftedWeight  > 2000)){

        cout << "Minute out of range!" << endl;
        return false;
    }
    else {

        return true;
    }

    

}


int main() {
    string name;
    double weight;
    double caloriegoal;
    double minlunges, minpushups, minpullups, liftedWeight, minliftedWeight ;
    int replunges, reppushups, reppullups, repliftedWeight;

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Welcome " << name<<", please enter your weight(kg): ";
    cin >> weight;
    cout << name <<", please enter minutes and repetitions in a week for the activities below." << endl;
    cout << "Lunges: ";
    getInput(minlunges, replunges, liftedWeight= 1);

    cout << "Push Ups: ";
    getInput(minpushups, reppushups, liftedWeight = 1);

    cout << "Pull Ups: ";
    getInput(minpullups, reppullups, liftedWeight= 1);

    cout << name <<", please enter minutes, repetitions and lifted weight in a week for the activities below." << endl;
    cout << "Weight Lifting: ";

    liftedWeight = 0;
    getInput(minliftedWeight, repliftedWeight, liftedWeight);
    cout << name <<", please enter your weekly calorie burn goal: ";
    cin >> caloriegoal;

    if (inputCheck(minlunges, minpushups, minpullups, replunges, reppushups, reppullups, liftedWeight, minliftedWeight, repliftedWeight,weight) == false) {


        

    }
    else {
        
        computeResults(weight, caloriegoal, replunges, reppushups, reppullups, repliftedWeight, minlunges, minpushups, minpullups, minliftedWeight, liftedWeight);
    


    }

    

    return 0;



}