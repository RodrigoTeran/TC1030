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
// #include "conio.h"

using namespace std;

int main() {
    srand(time(NULL));

    // Users
    User Rodrigo("Rodrigo", "12345", "rodrigo@gmail.com");
    User ErnestoFlores("Ernesto Flores", "54321", "ernestof@fb.com");

    // Events
    Event Internship("Internship with Facebook", "San Fransisco", "13/06/2022");

    // Today's Event
    Internship.announcePost();

    // Space
    cout << endl;

    // Groups
    Group FacebookInterns("Facebook Interns 2022");
    Rodrigo.joinGroup(FacebookInterns);

    // Group posts
    ErnestoFlores.createGroupPost("13 June welcome package!", &FacebookInterns);
    Rodrigo.createGroupPost("So excited to start my internship at Meta!", &FacebookInterns);

    cout << FacebookInterns.getName() << "'s posts:" << endl;
        
    Post* arrayPostsFacebook = FacebookInterns.getArrayRelatedPosts();
    int numberPostsFacebook = FacebookInterns.getNumberPosts();
    for (int i = 0; i < numberPostsFacebook; i++) {
        cout << "- " << arrayPostsFacebook[i].getText() << endl;
    };

    // Space
    cout << endl;

    // Own posts
    ErnestoFlores.createOwnPost("Hi friends!, I'm going to be manager at Meta!");
    
    cout << "Ernesto's posts:" << endl;
    
    Post* arrayPostsErnesto = ErnestoFlores.getArrayPosts();
    int* statsErnesto = ErnestoFlores.getStats();
    for (int i = 0; i < statsErnesto[0]; i++) {
        cout << "- " << arrayPostsErnesto[i].getText() << endl;
    };

    // Space
    cout << endl;

    string options[3] = {
        "small",
        "medium",
        "large"};
    Poll TShirtSizes("T-Shirt Sizes Poll", "What is your T-Shirt size?", options, 3);
    Rodrigo.voteInPoll(&TShirtSizes, "small");
    
    // Today's Event
    Internship.addParticipant();
    Internship.announcePost();

    // Space
    cout << endl;

    // Announce poll answers
    TShirtSizes.announcePost();

    return 0;
};