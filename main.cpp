/*
 * Rodrigo Terán Hernández
 * A01704108
 * Materia: Programación orientada a objetos TC1030
 * Profesor: Benjamin Valdés Aguirre
 */

/**
 * Este proyecto sirve para crear una red social
 * y establecer clases primarias
 * para la creación de contenido
 */ 

#include <iostream>   // para imprimir.
#include "includes/random.h"
#include "user.h"
#include "event.h"
#include "poll.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
    srand(time(NULL));

    // Users
    User Rodrigo("Rodrigo", "12345", "rodrigo@gmail.com");
    User ErnestoFlores("Ernesto Flores", "54321", "ernestof@fb.com");

    // Events
    Post* Internship = new Event("Internship with Facebook", "San Fransisco", "13/06/2022");

    cout <<"1" << endl;

    // Today's Event
    Internship->announcePost();

    cout <<"2" << endl;

    // Space
    cout << endl;

    // Groups
    Group FacebookInterns("Facebook Interns 2022");
    Rodrigo.joinGroup(FacebookInterns);

    // Group posts
    ErnestoFlores.createGroupPost("13 June welcome package!", "Menlo Park", "11/06/2022", &FacebookInterns);
    string optionsRodrigosPoll[2] = {
        "yes",
        "no"};
    Rodrigo.createGroupPost("First photo at Meta!", "Do you like Meta?", optionsRodrigosPoll, 2, &FacebookInterns);

    cout << FacebookInterns.getName() << "'s posts:" << endl;
        
    Post** arrayPostsFacebook = FacebookInterns.getArrayRelatedPosts();
    int numberPostsFacebook = FacebookInterns.getNumberPosts();
    for (int i = 0; i < numberPostsFacebook; i++) {
        cout << "- " << arrayPostsFacebook[i]->getText() << endl;
    };

    // Space
    cout << endl;

    // Own posts
    ErnestoFlores.createOwnPost("Hi friends!, I'm going to be manager at Meta!", "Seattle", "Tomorrow!");
    
    cout << "Ernesto's posts:" << endl;
    
    Post* arrayPostsErnesto = ErnestoFlores.getArrayPosts();
    int* statsErnesto = ErnestoFlores.getStats();
    for (int i = 0; i < statsErnesto[0]; i++) {
        cout << "- " << arrayPostsErnesto[i].getText() << endl;
    };

    // Space
    cout << endl;

    string optionsTShirt[3] = {
        "small",
        "medium",
        "large"};
    
    Post* TShirtSizes = new Poll("T-Shirt Sizes Poll", "What is your T-Shirt size?", optionsTShirt, 3);

    Rodrigo.voteInPoll(static_cast<Poll*>(TShirtSizes), "small");
    
    // Today's Event
    static_cast<Event*>(Internship)->addParticipant();
    Internship->announcePost();

    // Space
    cout << endl;

    // Announce poll answers
    TShirtSizes->announcePost();

    return 0;
};