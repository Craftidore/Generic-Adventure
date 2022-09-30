#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void beginningOfAdventure();

string to_lower(string s) {
  stringstream returnValue;
  for (int i = 0; i < s.size(); i++) {
    returnValue << (char)tolower(s.at(i));
  }
  return returnValue.str();
}

void getAnswer(string &inputVariable, vector<string> possibleAnswers ) {
  while (cin >> inputVariable) {
    inputVariable = to_lower(inputVariable);// resolve case issues
    for (int i = 0; i < possibleAnswers.size(); i++) {
      if (inputVariable == possibleAnswers.at(i)) return;
    }
    cout << endl << "Invalid Answer. Try again: ";
  }
  // validation, with an array of possible answers
}
/*
void getAnswer(string &inputVariable, string possibleAnswers[], int size) {
  vector<string> v;
  
  return getAnswer(inputVariable, v);
}
*/
bool getYesNo(){
  string x;
  vector<string> yesAnswers = {"yes","y"};
  vector<string> noAnswers = {"no","n"};
  vector<string> allAnswers = noAnswers;
  for (int i = 0; i < yesAnswers.size(); i++) {
    allAnswers.push_back(yesAnswers.at(i));
  }
  
  getAnswer(x, allAnswers);
  for (int i = 0; i < yesAnswers.size(); i++) {
    if (x == yesAnswers.at(i)) return true;
  }
  
  return false;
}

void elvenCastleIntro() {
  bool pleadIdentity;
  cout << "You begin in an Elven Castle, tasked with delivering a package to the king's court." << endl;
  cout << "The halls are long and the tapestries rich with depictions of ballads of famous warriors, priests, magicians, and text adventure game creators. ";
  cout << "At the end of the hall, you step into a large that is well lit. ";
  cout << "In front of you, at the end of the room is the Elven king. ";
  cout << "He looks very distressed but his expression lightens when you step into the room." << endl;
  cout << "\"Ahhh... you're here,\" the king says. ";
  cout << "\"I could have sworn you were supposed to arrive yesterday; the dragon has been terrorizing our lands, and every delay results in more human life.";
  cout << "What do you have to say for yourself, Ragnar?\"" << endl;

  cout << endl << endl;
  cout << "Your name is not Ragnar. ";
  cout << "You were summoned to deliver a package, not kill a dragon. " << endl;
  cout << "Would you like to plead that you are not Ragnar (yes/no)? ";
  pleadIdentity = getYesNo();
  if (pleadIdentity) cout << "Are you scared of the dragon? This is an adventure game! Get out of here; you're playing the wrong game." << endl;
  else cout << "Well, I guess you're killing a dragon now." << endl;

  beginningOfAdventure();
}

void beginningOfAdventure () {
  string pathToTake;
  vector <string> answers = {"road","wilderness"};
  cout << "After you are given gear to defeat the dragon, you leave the Elvin castle and start your journey. "
       << "In front of you is the main road that the heros before you have taken to defeat the dragon." << endl;
  cout << "Do you want to take the main road or would you like to make your own path through the wilderness to the dragon (road/wilderness)? ";

  getAnswer(pathToTake, answers);

  if (pathToTake == "road") {
    cout << "You decide to take the path the other heros have taken. "
         << "There are probably less obstacles to face because the path has already been cleared anyway." << endl;
    // some main-road function
  }
  else {
    cout << "You decide to go through the wilderness. "
         << "You will probably be able to catch the dragon off guard since no heros have gone this way." << endl;
    // some wilderness path function
  }
}

void startGame () {
  bool keepGoing = true;
  while (keepGoing) {
    elvenCastleIntro();
    cout << endl << "Would you like to play again (yes/no)? ";
    keepGoing = getYesNo();
  }
}

int main() {
  // start program
  startGame();
  return 0;
}
