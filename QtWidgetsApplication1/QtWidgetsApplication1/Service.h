#pragma once
#include "Repository.h"
#include "Movie.h"

using namespace std;

class Service {
private:
	int index;
	Repository* repo;
	vector<Movie> v;
public:
	Service();
	Service(vector<Movie> &vec, Repository *repo);
	void add_movie_service(std::string title, std::string genre, int year, int likes, std::string trailer);
	bool update_movie_service(int id,Movie m);
	void delete_movie_service(int id);
	//bool validate_movie(std::string title, std::string genre, int year, int likes, std::string trailer);
	bool validate_id(int id);
	Movie get_movie(int id);
	int get_vector_length();
	int get_index();
	void setup();
	vector<Movie> get_list();
	void write_repo();
	void add2_movie_service(Movie movie);
	void add_to_watchlist_s(int id);
	void delete_from_watchlist_s(int id);
	vector<int> get_watchlist_s();
	void write();
	void open();
	//void destroy();

};
