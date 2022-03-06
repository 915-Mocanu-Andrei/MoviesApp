#include "Movie.h"

/*Movie::Movie(int id, std::string title, std::string genre, int year, int likes, std::string trailer) {
	this->id = id;
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}*/

Movie::Movie(int id , std::string title , std::string genre , int year, int likes , std::string trailer) {
	this->id = id;
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

int Movie::get_id() {
	return this->id;
}

int Movie::get_year() {
	return this->year;
}

int Movie::get_likes() {
	return this->likes;
}

std::string Movie::get_title() {
	return this->title;
}
std::string Movie::get_genre() {
	return this->genre;
}
std::string Movie::get_trailer() {
	return this->trailer;
}

void Movie::set_id(int input) {
	this->id = input;
}

void Movie::set_year(int input) {
	 this->year = input;
}

void Movie::set_likes( int input) {
	 this->likes = input;
}

void Movie::set_title(std::string input) {
	this->title = input;
}
void Movie::set_genre(std::string input) {
	this->genre = input;
}
void Movie::set_trailer(std::string input) {
	this->trailer = input;
}
