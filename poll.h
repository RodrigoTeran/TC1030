// /*
//  * Rodrigo Terán Hernández
//  * A01704108
//  * Materia: Programación orientada a objetos TC1030
//  * Profesor: Benjamin Valdés Aguirre
//  */

#ifndef POLL_H
#define POLL_H
#include <iostream>
#include "post.h"
#include "polloption.h"

using namespace std;

class Poll: public Post {
    private:
        string question;
        PollOption* options;
        int numberOptions;

    public:
        Poll();
        ~Poll();
        Poll(string, string, string[], int);

        // Getters
        string getQuestion();
        PollOption* getOptions();

        // Setters
        void setQuestion(string);
        
        // Extra Methods
        void addVote(string);
        void announcePost();
};

// Constructors and destructors
Poll::~Poll(){
    delete [] this->options;
};

Poll::Poll(): Post() {
    this->question = "";
    this->options = new PollOption[5];
    this->numberOptions = 0;
};

Poll::Poll(string text, string question, string textOptions[], int size): Post(text) {
    this->question = question;    
    this->options = new PollOption[5];

    if (size > 5) {
        size = 5;
    };

    this->numberOptions = size;

    for (int i = 0; i < size; i++) {
        PollOption NewOption(textOptions[i]);
        this->options[i] = NewOption;
    };
};

// Getters
string Poll::getQuestion() {
    return this->question;
};

PollOption* Poll::getOptions() {
    return this->options;
};


// Setters
void Poll::setQuestion(string question) {
    this->question = question;
};

// Extra Methods
void Poll::addVote(string option) {
    bool optionFounded = false;
    for (int i = 0; i < this->numberOptions; i++) {
        PollOption curr = options[i];
        if (curr.getOption() == option) {
            curr.vote();
            optionFounded = true;
        }
    };

    if (!optionFounded) {
        cout << "Opción no hallada... :/" << endl;
    };
};

void Poll::announcePost(){
    cout << "Encuesta: " << this->question << endl;
    cout << "Opcones: " << endl;
    for (int i = 0; i < this->numberOptions; i++) {
        PollOption curr = options[i];
        cout << "- " << curr.getOption() << endl;
    };
};

#endif