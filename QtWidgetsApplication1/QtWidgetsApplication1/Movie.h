#pragma once
#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
	int id;
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string trailer;
public:
	Movie(int id=0,std::string title="Title", std::string genre="Genre", int year=0, int likes=0, std::string trailer = "www");
	int get_id();
	int get_year();
	int get_likes();
	std::string get_title();
	std::string get_genre();
	std::string get_trailer();
	void set_id(int input);
	void set_year(int input);
	void set_likes(int input);
	void set_title(std::string input);
	void set_genre(std::string input);
	void set_trailer(std::string input);
	friend ostream& operator<<(std::ostream& output, Movie& m) {
		output << "ID:" << m.get_id() << "\n" << "Title:" << m.get_title()
			<< "\n" << "Genre:" << m.get_genre() << "\n"
			<< "Year:" << m.get_year() << "\n" << "Likes:" << m.get_likes() << "\n" << "Trailer:" << m.get_trailer() << "\n";
		return output;
	}
	friend istream& operator>>(std::istream& input, Movie &m) {
		input >> m.id >> m.title >> m.genre >> m.year >> m.likes >> m.trailer;
		return input;
	}
};
