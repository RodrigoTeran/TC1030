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

using namespace std;

class Group {
    private:
        string _id;
        int participants;
        int posts;
        string name;
        Post* arrayRelatedPosts;
    

    public:
        Group();
        ~Group();
        Group(string);

        // Getters
        string getId();
        int getNumberParticipants();
        int getNumberPosts();
        string getName();
        Post* getArrayRelatedPosts();

        // Setters
        void setName(string);

        // Extra Methods
        void banMember();
        void joinMember();
        void createRelatedPost(string);
};

// Constructors and destructors
Group::~Group() {
    delete [] this->arrayRelatedPosts;
};

Group::Group() {
    this->_id = createID();
    this->name = "";
    this->participants = 0;
    this->posts = 0;
    this->arrayRelatedPosts = new Post[10];
};

Group::Group(string name) {
    this->_id = createID();
    this->name = name;
    this->participants = 0;
    this->posts = 0;
    this->arrayRelatedPosts = new Post[10];
};


// Getters
string Group::getId() {
    return this->_id;
};

int Group::getNumberParticipants() {
    return this->participants;
};

int Group::getNumberPosts() {
    return this->posts;
};

string Group::getName() {
    return this->name;
};

Post* Group::getArrayRelatedPosts() {
    return this->arrayRelatedPosts;
};

// Setters
void Group::setName(string name) {
    this->name = name;
};


// Extra Methods
void Group::banMember() {
    this->participants = this->participants - 1;
};

void Group::joinMember() {
    this->participants = this->participants + 1;
};

void Group::createRelatedPost(string text) {
    Post RelatedPost(text);
    this->arrayRelatedPosts[this->posts] = RelatedPost;
    this->posts = this->posts + 1;
};

#endif