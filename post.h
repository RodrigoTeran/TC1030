/*
 * Rodrigo Terán Hernández
 * A01704108
 * Materia: Programación orientada a objetos TC1030
 * Profesor: Benjamin Valdés Aguirre
 */

#ifndef POST_H
#define POST_H
#include <iostream>
#include "comment.h"
#include "includes/random.h"

using namespace std;

class Post {
    private:
        string _id;
        int likes;
        int comments;
        Comment* arrayComments;
        string text;
        string fileInCDN;

    public:
        Post();
        ~Post();
        Post(string);

        // Getters
        string getId();
        int getLikes();
        Comment* getArrayComments();
        string getText();
        string getFileInCdn();

        // Setters
        void setLikes(int);
        void setArrayComments(Comment[]);
        void setText(string);

        // Extra Methods
        void createComment(string);
        void addLike();
        virtual void announcePost() = 0;
};

// Constructors and destructors
Post::~Post() {
    delete [] this->arrayComments;
};

Post::Post() {
    this->_id = createID();
    this->text = "";
    this->likes = 0;
    this->comments = 0;
    this->arrayComments = new Comment[10];

    // TODO: Save file in a CDN or Database...
    this->fileInCDN = "https://www.cdn.socialMedia.com/file/" + this->_id;
};

Post::Post(string text) {
    this->_id = createID();
    this->text = text;
    this->likes = 0;
    this->comments = 0;
    this->arrayComments = new Comment[10];

    // TODO: Save file in a CDN or Database...
    this->fileInCDN = "https://www.cdn.socialMedia.com/file/" + this->_id;
};


// Getters
string Post::getId() {
    return this->_id;
};

int Post::getLikes() {
    return this->likes;
};

Comment* Post::getArrayComments() {
    return this->arrayComments;
};

string Post::getText() {
    return this->text;
};

string Post::getFileInCdn() {
    return this->fileInCDN;
};

// Setters
void Post::setLikes(int likes) {
    this->likes = likes;
};


void Post::setArrayComments(Comment arrayComments[]) {
    this->arrayComments = arrayComments;
};

void Post::setText(string text) {
    this->text = text;
};


// Extra Methods
void Post::createComment(string text) {
    Comment NewComment(text);

    this->arrayComments[comments] = NewComment;
    this->comments = this->comments + 1;
};

void Post::addLike() {
    this->likes = this->likes + 1;
};

#endif