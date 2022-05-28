/*
* Rodrigo Terán Hernández
* A01704108
* Materia: Programación orientada a objetos TC1030
* Profesor: Benjamin Valdés Aguirre
*/

#ifndef USER_H
#define USER_H
#include <iostream>
#include "post.h"
#include "event.h"
#include "group.h"
#include "poll.h"
#include "pollOption.h"

using namespace std;

class User {
	private:
		string _id;
		string name;
		string password;
		string accessToken;
		string refreshToken;
		string email;
		int friends;
		int posts;
		int groups;
		User *arrayFriends;
		Post *arrayPosts;
		Group *arrayGroups;

	public:
		User();
		~User();
		User(string);
		User(string, string);
		User(string, string, string);

		// Getters
		string getId();
		string getName();
		string getPassword();
		string getAccessToken();
		string getRefreshToken();
		string getEmail();
		User* getArrayFriends();
		Post* getArrayPosts();
		Group* getArrayGroups();

		// Setters
		void setName(string);
		void setPassword(string);
		void setEmail(string);

		// Extra Methods
		void createOwnPost(string);
		void createGroupPost(string, Group);
		void createComment(string, Post);
		void joinGroup(Group);
		void connectWithFriend(User);
		void likeOrDislikePost(Post, bool);
		void joinEvent(Event);
		void voteInPoll(Poll, string);

};
// Constructors and destructors
User::~User() {
	delete [] this->arrayFriends;
	delete [] this->arrayPosts;
	delete [] this->arrayGroups;
};
User::User() {
	this->_id = createID();
	this->name = "";
	this->password = createID();
	this->accessToken = createID();
	this->refreshToken = createID();
	this->email = "";
	this->friends = 0;
	this->posts = 0;
	this->groups = 0;
	this->arrayFriends = new User[10];
	this->arrayPosts = new Post[10];
	this->arrayGroups = new Group[10];
};
User::User(string name) {
	this->_id = createID();
	this->name = name;
	this->password = createID();
	this->accessToken = createID();
	this->refreshToken = createID();
	this->email = "";
	this->friends = 0;
	this->posts = 0;
	this->groups = 0;
	this->arrayFriends = new User[10];
	this->arrayPosts = new Post[10];
	this->arrayGroups = new Group[10];
};
User::User(string name, string password) {
    this->_id = createID();
    this->name = name;
    this->password = password;
    this->accessToken = createID();
    this->refreshToken = createID();
    this->email = "";
	this->friends = 0;
	this->posts = 0;
	this->groups = 0;
    this->arrayFriends = new User[10];
    this->arrayPosts = new Post[10];
    this->arrayGroups = new Group[10];
};
User::User(string name, string password, string email) {
    this->_id = createID();
    this->name = name;
    this->password = password;
    this->accessToken = createID();;
    this->refreshToken = createID();
    this->email = email;
	this->friends = 0;
	this->posts = 0;
	this->groups = 0;
    this->arrayFriends = new User[10];
    this->arrayPosts = new Post[10];
    this->arrayGroups = new Group[10];
};


// Getters
string User::getId() {
	return this->_id;
};

string User::getName() {
	return this->name;	
};

string User::getPassword() {
	return this->password;	
};

string User::getAccessToken() {
	return this->accessToken;	
};

string User::getRefreshToken() {
	return this->refreshToken;	
};

string User::getEmail() {
	return this->email;	
};

User* User::getArrayFriends() {
	return this->arrayFriends;	
};

Post* User::getArrayPosts() {
	return this->arrayPosts;	
};

Group* User::getArrayGroups() {
	return this->arrayGroups;	
};

// Setters
void User::setName(string name) {
	this->name = name;	
};

void User::setPassword(string password) {
	this->password = password;	
};

void User::setEmail(string email) {
	this->email = email;	
};

// Extra Methods
void User::createOwnPost(string text) {
	Post OwnPost(text);
    this->arrayPosts[this->posts] = OwnPost;
    this->posts = this->posts + 1;
};

void User::createGroupPost(string text, Group group) {
	group.createRelatedPost(text);
};

void User::createComment(string text, Post post) {
	post.createComment(text);
};

void User::joinGroup(Group group) {
	group.joinMember();
};

void User::connectWithFriend(User user) {
	this->arrayFriends[this->friends] = user;
    this->friends = this->friends + 1;
};

void User::likeOrDislikePost(Post post, bool isLike) {
	if (isLike) {
		post.addLike();
	};
};

void User::joinEvent(Event event) {
	event.addParticipant();
};

void User::voteInPoll(Poll poll, string pollOption) {
	poll.addVote(pollOption);
};

#endif