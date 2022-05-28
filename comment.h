/*
* Rodrigo Terán Hernández
* A01704108
* Materia: Programación orientada a objetos TC1030
* Profesor: Benjamin Valdés Aguirre
*/

#ifndef COMMENT_H
#define COMMENT_H
#include <iostream>
#include "includes/random.h"

using namespace std;

class Comment {
    private:
        string _id;
        string text;
        int numberReplies;
        Comment* arrayReplies;
        Comment* commentReplied;
    
    public:
        Comment();
        ~Comment();
        Comment(string);
        Comment(string, Comment);

        // Getters
        string getId();
        string getText();
        Comment* getArrayReplies();
        Comment* getCommentReplied();

        // Setters
        void setText(string);

        // Extra Methods
        void addReply(Comment);
};

// Constructors and destructors
Comment::~Comment() {
    delete [] this->arrayReplies;
    delete [] this->commentReplied;
};
Comment::Comment() {
    this->_id = createID();
    this->text = "";
    this->numberReplies = 0;
    this->arrayReplies = new Comment[100];
    this->commentReplied = NULL;
};
Comment::Comment(string text) {
    this->_id = createID();
    this->text = text;
    this->numberReplies = 0;
    this->arrayReplies = new Comment[100];
    this->commentReplied = NULL;
};
Comment::Comment(string text, Comment commentReplied) {
    this->_id = createID();
    this->text = text;
    this->numberReplies = 0;
    this->arrayReplies = new Comment[100];
    *this->commentReplied = commentReplied;
};

// Getters
string Comment::getId() {
    return this->_id;
};

string Comment::getText() {
    return this->text;
};

Comment* Comment::getArrayReplies() {
    return this->arrayReplies;
};

Comment* Comment::getCommentReplied() {
    return this->commentReplied;
};


// Setters
void Comment::setText(string text) {
    this->text = text;
};

// Extra Methods
void Comment::addReply(Comment comment) {
    this->arrayReplies[numberReplies] = comment;
    this->numberReplies = this->numberReplies + 1;
};

#endif