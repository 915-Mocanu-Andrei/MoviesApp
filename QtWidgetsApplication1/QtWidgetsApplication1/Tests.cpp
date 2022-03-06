#include "Tests.h"
#include <assert.h>
/*
void test_add_service() {
	DynamicVector<Movie> vector(50);
	Service service(vector);
	service.add_movie_service("Titel pa campii", "Groactiune", 1200, 1200, "hashtetepe");
	service.add_movie_service( "Titel pa dealuri", "Groactiune", 1200, 1200, "hashtetepe");
	service.add_movie_service( "Titel pa campii3", "Groactiune", 1200, 1200, "hashtetepe");
	//cout << vector.get_length();
	service.add_movie_service( "Titel pa campii4", "Groactiune", 1200, 1200, "hashtetepe");
	service.add_movie_service( "Titel pa campii5", "Groactiune", 1200, 1200, "hashtetepe");
	//cout << vector.get_length();
	service.add_movie_service( "Titel pa campii6", "Groactiune", 1200, 1200, "hashtetepe");
	service.add_movie_service( "Titel pa campii7", "Groactiune", 1200, 1200, "hashtetepe");
	//vector.resize_array(50);
	Movie m;
	m = vector.get_element(12);
	assert(vector.get_element(0).get_title() == "Titel pa campii");
	assert(vector.get_element(1).get_id() == 1);
	assert(vector.get_element(2).get_id() == 2);
	assert(vector.get_element(6).get_id() == 6);
	assert(service.get_movie(6).get_title() == "Titel pa campii7");
	service.delete_movie_service(0);
	assert(vector.get_element(0).get_title() == "Titel pa dealuri");
	assert(vector.get_element(6).get_id() == 6);
	int a;
	//vector.resize_array(50);
	vector.destroy();
	//Console console(service);
	//console.run();
}

void test_movie() {
	Movie m(1,"Titlu","Gen",3,3,"http");
	string genre, trailer, title;
	int year, likes,id;
	assert(m.get_genre() == "Gen");
	assert(m.get_title() == "Titlu");
	assert(m.get_trailer() == "http");
	m.set_genre("Gen2");
	m.set_title("Titlu2");
	m.set_trailer("http2");
	m.set_id(6);
	m.set_likes(100);
	m.set_year(2100);
	assert(m.get_genre() == "Gen2");
	assert(m.get_title() == "Titlu2");
	assert(m.get_trailer() == "http2");
	assert(m.get_id()==6);
	assert(m.get_likes() == 100);
	assert(m.get_year() == 2100);
	m.set_likes(100);
}
void test_resize() {
	DynamicVector<Movie> vector(2);
	Service service(vector);
	service.add_movie_service("Titel pa campii", "Groactiune", 1200, 1200, "hashtetepe");
	service.add_movie_service("Titel pa dealuri", "Groactiune", 1200, 1200, "hashtetepe");
	service.add_movie_service("Titel pa campii3", "Groactiune", 1200, 1200, "hashtetepe");
}

void test_update_movie() {
	Movie m;
	DynamicVector<Movie> vector(50);
	Service service(vector);
	service.add_movie_service("Titel pa campii", "Groactiune", 1200, 1200, "hashtetepe");
	service.add_movie_service("Titel pa dealuri", "Groactiune", 1200, 1200, "hashtetepe");
	service.update_movie_service(0, "Titel pa dealuri", "Groactiune", 1200, 1200, "hashtetepe");
	assert(service.get_movie(0).get_title() == service.get_movie(1).get_title());
}

void test_watchlist() {
	DynamicVector<Movie> vector(50);
	Service service(vector);
	service.add_to_watchlist(2);
	service.add_to_watchlist(3);
	assert(service.get_watchlist_element(0) == 2);
	service.delete_from_watchlist_service(0);
	assert(service.get_watchlist_element(0) == 3);
	int a,b;
	a = service.get_vector_length();
	b = service.get_index();
	assert(a == vector.get_length());
}

void test_validate_movie() {
	DynamicVector<Movie> vector(50);
	Service service(vector);
	Movie m1(1, "", "Gen", 3, 3, "http");
	Movie m2(1, "Titlu", "", 3, 3, "http");
	Movie m3(1, "Title", "Gen", 3, 3, "");
	assert(service.validate_id(2) == true);
	assert(service.validate_movie( "", "Gen", 2000, 3, "http") == false);
	assert(service.validate_movie("Titlu", "", 2000, 3, "http") == false);
	assert(service.validate_movie("Titlu", "Gen", 2000, 3, "") == false);
	assert(service.validate_movie("Title", "Gen", 1000, 3, "http") == false);
	assert(service.validate_movie("Title", "Gen",2000, -5, "http") == false);


}
*/
void test_all() {
	//test_add_service();
	//test_movie();
	//test_validate_movie();
	//test_update_movie();
	//test_watchlist();
	//test_resize();
}