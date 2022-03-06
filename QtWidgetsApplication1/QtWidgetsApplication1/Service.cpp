#include "Service.h"
#include <algorithm>
#include <numeric>
#include <iostream>

Service::Service() {

}

Service::Service(vector<Movie> &vec, Repository* repo) {
	this->v = vec;
	this->index = 0;
	this->repo = repo;
}

void Service::add_movie_service(std::string title, std::string genre, int year, int likes, std::string trailer) {
	//adds a movie in the database
	Movie movie(index, title, genre, year, likes, trailer);
	//v.push_back(movie);
	//v[v.size()-1].set_id(v.size() - 1);
	//
	repo->add(movie);
	index++;
}

void Service::add2_movie_service(Movie movie) {
	//adds a movie in the database
	//v.push_back(movie);
	//v[v.size()-1].set_id(v.size() - 1);
	//
	MovieValidator::validate(movie);
	repo->add(movie);
	index++;
}

bool Service::update_movie_service(int id,Movie m) {
	MovieValidator::validate(m);
	repo->remove(id);
	repo->add(m);
	return true;
}
void Service::delete_movie_service(int id) {
	//deletes a movie
	//v.erase(v.begin() + id);
	//for (Movie &mov : v){
	//	if (mov.get_id() > id)
	//	mov.set_id(mov.get_id()-1);
//	}
	repo->remove(id);
	index--;
}
/*
bool Service::validate_movie(std::string title, std::string genre, int year, int likes, std::string trailer) {
	//validates the input
	return true;
	if (year <1800 || year> 2030) {
		return false;
	}
	if (likes < 0) {
		return false;
	}
	if (title == "") {
		return false;
	}
	if (genre == "") {
		return false;
	}
	if (trailer == "") {
		return false;
	}
	return true;
}
*/
bool Service::validate_id(int id) {
	return true;
}

Movie Service::get_movie(int id) {
	return v[id];
	//return vector.get_element(id);
}

void Service::write() {
	repo->write();
}

int Service::get_vector_length() {
	return v.size();
	//return vector.get_length();
}

int Service::get_index() {
	return this->index;
}

void Service::setup() {
	add_movie_service("Interstellar", "SciFi", 2001, 1200, "https://www.youtube.com/watch?v=zSWdZVtXT7E");
	add_movie_service("Titel pa dealuri2", "Adventure", 2002, 1200, "http");
	add_movie_service("Georgel pa campii3", "Action", 2002, 1200, "www");
	add_movie_service("Titel pa campii4", "SciFi", 2000, 1200, "hashtetepe");
	add_movie_service("Titel pa dealuri5", "Adventure", 1980, 1200, "hashtetepe");
	add_movie_service("Titel pa campii6", "Horror", 2000, 1200, "hashtetepe");
	add_movie_service("Titel pa dealuri7 iar", "Horror", 2005, 1200, "hashtetepe");
	add_movie_service("Titel pa dealuri8", "Thriller", 2012, 1200, "hashtetepe");
	add_movie_service("Titel pa campii9", "Comedy", 2010, 1200, "hashtetepe");
	add_movie_service("Titel pa campii10", "Comedy", 2010, 1200, "hashtetepe");
}

vector<Movie> Service::get_list() {
	return repo->get_list();
}

void Service::write_repo() {
	repo->write();
}
void Service::add_to_watchlist_s(int id) {
	repo->add_to_watchlist(id);
}

void Service::delete_from_watchlist_s(int id) {
	repo->delete_from_watchlist(id);
}

vector<int> Service::get_watchlist_s() {
	return repo->get_watchlist();
}

void Service::open() {
	repo->open();
}