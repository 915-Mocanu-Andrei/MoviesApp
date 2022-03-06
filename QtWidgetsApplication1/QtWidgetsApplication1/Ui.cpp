#include "Ui.h"

Console::Console() {
	this->service = NULL;
}

void Console::choose_type_of_repo() {
	int x;
	cout << "Choose the type of watchlist:\n";
	cout << "1.HTML\n";
	cout << "2.CSV\n";
	cin >> x;
	if (x == 1) {
		Repository* rep_ptr = new HTMLRepo(movies);
		Service* ser_ptr = new Service(movies, rep_ptr);
		this->service = ser_ptr;
		service->setup();
		service->write();
	}
	if (x == 2) {
		Repository* rep_ptr = new CSVRepo(movies);
		Service* ser_ptr = new Service(movies, rep_ptr);
		this->service = ser_ptr;
		service->setup();
		service->write();

	}
}

void Console::run() {
	choose_type_of_repo();
	int x;
	cout << "1.Administrator mode\n2.User mode\n";
	cin >> x;
	if (x == 1) {
		run1();
	}
	if (x == 2) {
		run2();
	}
	service->write_repo();
}

void Console::run1() {
	p_menu();
	int x;
	cout << "Option:";
	cin >> x;
	while (x != 0) {
		this->movies = service->get_list();
		if (x == 1) {
			add_ui();
		}
		if (x == 2) {
			delete_ui();
		}
		if (x == 3) {
			update_ui();
		}
		if (x == 4) {
			see_all();
		}
		cout << "Option:";
		cin >> x;
	}
}

void Console::see_all() {
	for (Movie m : movies) {
		/*cout << "ID:";
		cout << m.get_id() << "\n";
		cout << "Title:";
		cout << m.get_title() << "\n";
		cout << "Genre:";
		cout << m.get_genre() << "\n";
		cout << "Year:";
		cout << m.get_year() << "\n";
		cout << "Likes:";
		cout << m.get_likes() << "\n";
		cout << "Trailer:";
		cout << m.get_trailer()<<"\n";
		cout << "\n";*/
		cout << m<<'\n';
	}
}

Movie Console::get_movie_ui(int id) {
	return service->get_movie(id);
}


void Console::p_menu() {
	cout << "Menu:\n";
	cout << "1.Add\n";
	cout << "2.Delete\n";
	cout << "3.Update\n";
	cout << "4.See all the movies\n";
	cout << "0.Exit\n";
	cout << "";
	cout << "";
}
/*
void Console::add_ui() {
	string title,genre,trailer;
	int year, likes;
	cout << "Title:\n";
	cin >> title;
	cout << "Genre:\n";
	cin >> genre;
	cout << "Year:\n";
	cin >> year;
	cout << "Likes:\n";
	cin >> likes;
	cout << "Trailer:\n";
	cin >> trailer;
	if (service.validate_movie(title, genre, year, likes, trailer) == true) {
		service.add_movie_service(title, genre, year, likes, trailer);
	}
	else {
		cout << "Invalid movie!\n";
	}
}
*/
void Console::add_ui() {
	Movie m;
	cin >> m;
	try {
		service->add2_movie_service(m);
	}
	catch(ValidationException& exception){
		cout << exception.getMessage()<<'\n';
	}
}
void Console::update_ui() {
	int id;
	cout << "Id:\n";
	cin >> id;
	Movie movie;
	cin >> movie;
	try {
		service->update_movie_service(id,movie);
	}
	catch (ValidationException& exception) {
		cout << exception.getMessage() << '\n';
	}
}

void Console::delete_ui() {
	int id;
	cout << "Id:";
	cin >> id;
	if (service->validate_id(id)) {
		service->delete_movie_service(id);
	}
	else {
	cout << "Can't delete a movie that doesn't exist!\n";
	}
}

void Console::get_option(int x) {
	cin >> x;
}

//functions related to the user mode

void Console::run2() {
	int x = 0;
	while (x != 5) {
		this->movies = service->get_list();
		cout << "1.See the watchlist\n";
		cout << "2.Update the watchlist\n";
		cout << "3.Delete movie from the watchlist\n";
		cout << "4.Open the wattchlist.\n";
		cout << "5.Exit";
		cout << "Option:";
		cin >> x;
		cout << "\n";
		if (x == 1) {
			see_watchlist();
		}
		if (x == 2) {
			update_watchlist();
		}
		if (x == 3) {
			delete_from_watchlist();
		}
		if (x == 4) {
			service->open();
		}
	}
	service->write();
}

void Console::delete_from_watchlist() {
	cout << "What movie do you wish to delete?";
	//see_watchlist();
	int x;
	cin >> x;
	service->delete_from_watchlist_s(x);
	//see_watchlist();
}

void Console::see_watchlist() {
	watchlist = service->get_watchlist_s();
	movies = service->get_list();
	for (int i : watchlist) {
		Movie m;
		m = movies[i];
		/*
		cout << "Title:";
		cout << m.get_title() << "\n";
		cout << "Genre:";
		cout << m.get_genre() << "\n";
		cout << "Year:";
		cout << m.get_year() << "\n";
		cout << "Likes:";
		cout << m.get_likes() << "\n";
		cout << "Trailer:";
		cout << m.get_trailer() << "\n";
		cout << "\n";*/
		cout << m;
	}
}

void Console::update_watchlist() {
	watchlist = service->get_watchlist_s();
	string genre;
	cout << "Genre:";
	cin >> genre;
	for (Movie m : movies) {
		cout << m.get_genre();
		if (m.get_genre() == genre){
			/*
			cout << "Title:";
			cout << m.get_title() << "\n";
			cout << "Genre:";
			cout << m.get_genre() << "\n";
			cout << "Year:";
			cout << m.get_year() << "\n";
			cout << "Likes:";
			cout << m.get_likes() << "\n";
			cout << "Trailer:";
			cout << m.get_trailer() << "\n";
			cout << "\n";
			cout << "Add to the watchlist?\n";*/
			cout << m;
			cout << "1.Yes\n";
			cout << "2.No\n";
			cout << "3.Exit list update\n";
			int x;
			cin >> x;
			if (x == 1) {
				service->add_to_watchlist_s((m.get_id()));
			}
			if (x == 3) {
				break;
			}
		}
	}
	service->write();
}