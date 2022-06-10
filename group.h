/*
* Rodrigo Terán Hernández
* A01704108
* Materia: Programación orientada a objetos TC1030
* Profesor: Benjamin Valdés Aguirre
*/

#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include "includes/random.h"
#include "post.h"
#include "event.h"
#include "poll.h"

using namespace std;

class Group {
    private:
        string _id;
        int participants;
        int polls;
        int events;
        string name;
        Poll arrayRelatedPoll[10];
        Event arrayRelatedEvent[10];

    public:
        Group();
        ~Group();
        Group(string);

        // Getters
        string getId();
        int getNumberParticipants();
        string getName();

        // Setters
        void setName(string);

        // Extra Methods
        void banMember();
        void joinMember();
        void printArrayRelatedPosts();
        void createRelatedPost(string, string, string);
        void createRelatedPost(string, string, string[], int);
};

// Constructors and destructors
Group::~Group() {
    delete [] this->arrayRelatedPoll;
    delete [] this->arrayRelatedEvent;
};

Group::Group() {
    this->_id = createID();
    this->name = "";
    this->participants = 0;
    this->polls = 0;
    this->events = 0;
};

Group::Group(string name) {
    this->_id = createID();
    this->name = name;
    this->participants = 0;
    this->polls = 0;
    this->events = 0;
};

// Getters
string Group::getId() {
    return this->_id;
};

int Group::getNumberParticipants() {
    return this->participants;
};

string Group::getName() {
    return this->name;
};

// Setters
void Group::setName(string name) {
    this->name = name;
};


// Extra Methods
void Group::printArrayRelatedPosts() {
    cout << this->name << "'s posts:" << endl;
    for (int i = 0; i < events; i++) {        
        cout << "- " << this->arrayRelatedEvent[i].getText() << endl;
    };
    for (int i = 0; i < polls; i++) {        
        cout << "- " << arrayRelatedPoll[i].getText() << endl;
    };
};

void Group::banMember() {
    this->participants = this->participants - 1;
};

void Group::joinMember() {
    this->participants = this->participants + 1;
};

void Group::createRelatedPost(string title, string question, string options[], int size) {
    Poll RelatedPost(title, question, options, size);
    this->arrayRelatedPoll[this->polls] = RelatedPost;
    this->polls = this->polls + 1;
};

void Group::createRelatedPost(string title, string where, string when) {
    Event RelatedPost(title, where, when);
    this->arrayRelatedEvent[this->events] = RelatedPost;
    this->events = this->events + 1;
};

#endif