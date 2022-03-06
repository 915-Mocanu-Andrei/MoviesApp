#pragma once
#include "Service.h"
#include <iostream>

class Console {
private:
	Service* service;
	vector<Movie> movies;
	vector<int> watchlist;

public:
	Console();
	void run();
	void p_menu();
	void add_ui();
	void update_ui();
	void delete_ui();
	void get_option(int x);
	void run2();
	void run1();
	void see_all();
	Movie get_movie_ui(int id);
	void see_watchlist();
	void update_watchlist();
	void delete_from_watchlist();
	void choose_type_of_repo();
};