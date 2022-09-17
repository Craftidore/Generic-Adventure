#include <iostream>
#include <string>
#include <vector>
using namespace std;

void getAnswer(string &inputVariable, vector<string> possibleAnswers ) {
  while (cin >> inputVariable) {
    for (int i = 0; i < possibleAnswers.size(); i++) {
      if (inputVariable == possibleAnswers.at(i)) return;
    }
    cout << endl << "Invalid Answer. Try again: ";
  }
  // validation, with an array of possible answers
}
bool getYesNo(){
  string x;
  vector<string> yesAnswers = {"Yes","yes","Y","y"};
  vector<string> noAnswers = {"No", "no","N","n"};
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

void startGame () {
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
}

int main() {
  // start program
  startGame();
  return 0;
}
