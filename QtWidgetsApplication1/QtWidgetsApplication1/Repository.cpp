#include "Repository.h"


Repository::Repository() {

}

Repository::Repository( vector<Movie> vector) {
	this->list = vector;
}

CSVRepo::CSVRepo() {

}

HTMLRepo::HTMLRepo() {

}

CSVRepo::CSVRepo(vector<Movie> vector) {
	this->list = vector;
}

HTMLRepo::HTMLRepo(vector<Movie> vector) {
	this->list = vector;
}


void Repository::add(Movie movie) {
	list.push_back(movie);
	list[list.size() - 1].set_id(list.size() - 1);
}

void Repository::remove(int index) {
	list.erase(list.begin() + index);
	for (Movie& mov : list) {
		if (mov.get_id() > index)
			mov.set_id(mov.get_id() - 1);
	}
}
int Repository::get_length() {
	return list.size();
}

Movie Repository::get_element(int index) {
	return list[index];
}

vector<Movie> Repository::get_list() {
	return this->list;
}

void Repository::add_to_watchlist(int id) {
	cout << id;
	watchlist.push_back(id);
}

void Repository::delete_from_watchlist(int id) {
	watchlist.erase(watchlist.begin() + id);
}

vector<int> Repository::get_watchlist() {
	return watchlist;
}

void Repository::write() {
	ofstream out("out.txt");
	for (auto m : list) {
		out << "ID:";
		out << m.get_id() << "\n";
		out << "Title:";
		out << m.get_title() << "\n";
		out << "Genre:";
		out << m.get_genre() << "\n";
		out << "Year:";
		out << m.get_year() << "\n";
		out << "Likes:";
		out << m.get_likes() << "\n";
		out << "Trailer:";
		out << m.get_trailer() << "\n";
		out << "\n";
	}
	out.close();
}

void CSVRepo::write() {
	ofstream out("watchlist.csv");
	for (auto i : watchlist) {
		out << list[i].get_id() << "," << list[i].get_title() << "," << list[i].get_genre() << "," << list[i].get_year() << ","
			<< list[i].get_likes() << "," << list[i].get_trailer() << "\n";
	}
	out.close();
	//ShellExecute(0, 0, L"http://www.google.com", 0, 0, SW_SHOW); //-- opening a link
	// PUNE 2 \\-uri
	//ShellExecute(NULL, L"open", L"c:\\watchlist.csv", NULL, NULL, SW_SHOW);
}
void CSVRepo::open() {
	ShellExecute(0, L"open", L"c:\\Users\\Andrei\\source\\repos\\a67-915-Mocanu-Andrei\\Project1\\Project1\\watchlist.csv", 0, 0, SW_SHOW);// PUNE 2 \\-uri
}

void Repository::open() {
	ShellExecute(0, L"open", L"c:\\Users\\Andrei\\source\\repos\\a67-915-Mocanu-Andrei\\Project1\\Project1\\out.txt", 0, 0, SW_SHOW);
}

void HTMLRepo::write() {
	ofstream out("watchlist.html");
	out << "<!DOCTYPE html>";
	out << "<html>";
	out << "<head>";
	out << "<title>Watchlist</title>";
	out << "</head>";
	out << "<body>";
	out << "<table border=\"1\">";
	out << "<tr>";
	out << "<td>" << "Title" << "</td>";
	out << "<td>" << "Year" << "</td>";
	out << "<td>" << "Likes" << "</td>";
	out << "<td>" << "Trailer" << "</td>";
	out << "</tr>";
	for (auto i : watchlist) {
		out << "<tr>";
		out << "<td>"<<list[i].get_title()<<"</td>";
		out << "<td>" << list[i].get_year() << "</td>";
		out << "<td>" << list[i].get_likes() << "</td>";
		out << "<td>" <<"<a href=\""<< list[i].get_trailer() << "\">Trailer</a></td>";
		out << "</tr>";
		out << "<tr>";
	}
	out << "</table>";
	out << "</body>";
	out << "</html>";
	out.close();
}

void HTMLRepo::open() {
	ShellExecute(0, L"open", L"c:\\Users\\Andrei\\source\\repos\\a67-915-Mocanu-Andrei\\Project1\\Project1\\watchlist.html", 0, 0, SW_SHOW);
}