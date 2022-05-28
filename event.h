// /*
//  * Rodrigo Terán Hernández
//  * A01704108
//  * Materia: Programación orientada a objetos TC1030
//  * Profesor: Benjamin Valdés Aguirre
//  */

#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include "post.h"

using namespace std;

class Event: public Post {
    private:
        string date;
        string place;
        int participants;

    public:
        Event();
        Event(string);
        Event(string, string);

        // Getters
        string getDate();
        string getPlace();
        int getNumberParticipants();

        // Setters
        void setPlace(string);
        void setDate(string);
        
        // Extra Methods
        void addParticipant();
        void announcePost();
};

// Constructors
Event::Event(): Post() {
    this->place = "";
    this->date = "27/05/2022";
    this->participants = 0;
};

Event::Event(string text): Post(text) {
    this->place = "";
    this->date = "27/05/2022";
    this->participants = 0;
};

Event::Event(string text, string place): Post(text) {
    this->place = place;
    this->date = "27/05/2022";
    this->participants = 0;
};

// Getters
string Event::getDate(){
    return this->date;
};

string Event::getPlace(){
    return this->place;
};

int Event::getNumberParticipants(){
    return this->participants;
};

// Setters
void Event::setPlace(string place){
    this->place = place;
};

void Event::setDate(string date){
    this->date = date;
};

// Extra Methods
void Event::addParticipant(){
    this->participants = this->participants + 1;
};

void Event::announcePost(){
    cout << "Evento el día " << this->date << " en " << this->place << 
        ". ya están inscritos " << this->participants << " participantes." << endl;
};

#endif