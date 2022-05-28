// /*
//  * Rodrigo Terán Hernández
//  * A01704108
//  * Materia: Programación orientada a objetos TC1030
//  * Profesor: Benjamin Valdés Aguirre
//  */

#include <iostream>
#include "includes/random.h"
#include "user.h"
#include "event.h"
#include "poll.h"
#include <time.h>
#include <stdlib.h>
#include "conio.h"

using namespace std;

int main() {
    srand(time(NULL));

    User Rodrigo("Rodrigo", "12345", "rodrigo@gmail.com");
    User ErnestoFlores("Ernesto Flores", "54321", "ernestof@fb.com");
    Event Internship("Internship with Facebook", "San fransisco");

    Internship.announcePost();

    Group FacebookInterns("Facebook Interns 2022");
    Rodrigo.joinGroup(FacebookInterns);

    ErnestoFlores.createGroupPost("13 June welcome package!", FacebookInterns);
    string options[3] = {
        "small",
        "medium",
        "large"};
    Poll TShirtSizes("T-Shirt Sizes Poll", "What is your T-Shirt size?", options, 3);
    Rodrigo.voteInPoll(TShirtSizes, "small");

    Internship.announcePost();
    TShirtSizes.announcePost();

    getch();
    return 0;
};