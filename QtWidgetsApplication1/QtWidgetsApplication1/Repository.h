#pragma once
#include "Movie.h"
#include "Validator.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>
#include <shellapi.h>

using namespace std;

class Repository 
{
protected:
	vector<Movie> list;
	vector<int> watchlist;
public:
	Repository();
	Repository(vector<Movie> vector);
	void add(Movie movie);
	void remove(int index);
	int get_length();
	Movie get_element(int index);
	vector<Movie> get_list();
	virtual void write();
	vector<int> get_watchlist();
	void delete_from_watchlist(int id);
	void add_to_watchlist(int id);
	virtual void open();
};

class CSVRepo : public Repository
{
public:
	CSVRepo(vector<Movie> vector);
	CSVRepo();
	void write();
	void open();
};

class HTMLRepo : public Repository
{
public:
	HTMLRepo();
	HTMLRepo(vector<Movie> vector);
	void write();
	void open();
};

