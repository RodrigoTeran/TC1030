// /*
//  * Rodrigo Terán Hernández
//  * A01704108
//  * Materia: Programación orientada a objetos TC1030
//  * Profesor: Benjamin Valdés Aguirre
//  */

#ifndef POLLOPTION_H
#define POLLOPTION_H
#include <iostream>
#include "includes/random.h"

using namespace std;

class PollOption {
    private:
        string _id;
        string option;
        int votes;

    public:
        PollOption();
        PollOption(string);

        // Getters
        string getId();
        string getOption();
        int getNumberVotes();

        // Setters
        void setOption(string);
        
        // Extra Methods
        void vote();
};

// Constructors and destructors
PollOption::PollOption() {
    this->option = "";
    this->votes = 0;
    this->_id = createID();
};

PollOption::PollOption(string option) {
    this->option = option;
    this->votes = 0;
    this->_id = createID();
};

// Getters
string PollOption::getId(){
    return this->_id;
};

string PollOption::getOption(){
    return this->option;
};

int PollOption::getNumberVotes(){
    return this->votes;
};

// Setters
void PollOption::setOption(string option){
    this->option = option;
};

// Extra Methods
void PollOption::vote() {
    this->votes = this->votes + 1;
};

#endif