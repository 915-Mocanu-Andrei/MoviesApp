#include "QtWidgetsApplication1.h"

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.horizontalLayoutWidget->hide();
    ui.horizontalLayoutWidget_3->hide();
    ui.horizontalLayoutWidget_4->hide();
}
/*
Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}
*/
void QtWidgetsApplication1::connect_signals_and_slots() {
    connect(ui.pushButton_4, &QPushButton::clicked, this, &QtWidgetsApplication1::HTML_button_handler);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &QtWidgetsApplication1::CSV_button_handler);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &QtWidgetsApplication1::A_button_handler);
    connect(ui.pushButton, &QPushButton::clicked, this, &QtWidgetsApplication1::U_button_handler);
    connect(ui.seeAllButton, &QPushButton::clicked, this, &QtWidgetsApplication1::seeAll_button_handler);
    connect(ui.addButton, &QPushButton::clicked, this, &QtWidgetsApplication1::add_button_handler);
    connect(ui.updateButtonA, &QPushButton::clicked, this, &QtWidgetsApplication1::update_button_handler);
    connect(ui.deleteButtonA, &QPushButton::clicked, this, &QtWidgetsApplication1::delete_button_handler);
    connect(ui.exitButtonA, &QPushButton::clicked, this, &QtWidgetsApplication1::exit_button_handler);
    connect(ui.exitButtonU, &QPushButton::clicked, this, &QtWidgetsApplication1::exit_button_handler);
    connect(ui.seeWatchlistButton, &QPushButton::clicked, this, &QtWidgetsApplication1::seeWatchlist_button_handler);
    connect(ui.openButton, &QPushButton::clicked, this, &QtWidgetsApplication1::openWatchlist_button_handler);
    connect(ui.updateButtonU, &QPushButton::clicked, this, &QtWidgetsApplication1::updateWatchlist_button_handler);
}

void QtWidgetsApplication1::HTML_button_handler() {
    ui.horizontalLayoutWidget->show();
    ui.pushButton_3->hide();
    Repository* rep_ptr = new HTMLRepo(movies);
    Service* ser_ptr = new Service(movies, rep_ptr);
    this->service = ser_ptr;
    service->setup();
    service->write();
}

void QtWidgetsApplication1::CSV_button_handler() {
    ui.horizontalLayoutWidget->show();
    ui.pushButton_4->hide();
    Repository* rep_ptr = new CSVRepo(movies);
    Service* ser_ptr = new Service(movies, rep_ptr);
    this->service = ser_ptr;
    service->setup();
    service->write();
}

void QtWidgetsApplication1::A_button_handler() {
    movies = service->get_list();
    ui.horizontalLayoutWidget_3->show();
    ui.pushButton->hide();

}

void QtWidgetsApplication1::U_button_handler() {
    movies = service->get_list();
    ui.horizontalLayoutWidget_4->show();
    ui.pushButton_2->hide();
}

void QtWidgetsApplication1::seeAll_button_handler() {
    ui.listWidget->clear();
    for (Movie m : movies) {
        std::string movie_string;
        movie_string = to_string(m.get_id())+". " + m.get_genre() + ", " + to_string(m.get_id()) + ", " + to_string( m.get_likes()) + ", " + m.get_title() + ", " + m.get_title() + ", " + m.get_trailer() + ", " + to_string(m.get_year());
        QString item;
        item = QString::fromStdString(movie_string);
        ui.listWidget->addItem(item);
    }
}

void QtWidgetsApplication1::add_button_handler(){
    string title, genre, trailer;
    int likes, year;
    int id = 12;
    title = ui.titleEntry->text().toStdString();
    genre = ui.genreEdit->text().toStdString();
    trailer = ui.trailerEntry->text().toStdString();
    likes = ui.likesEntry->text().toInt();
    year = ui.yearLikes->text().toInt();
    Movie m(id,title,genre,year,likes,trailer);
    //cin >> m;
    try {
        service->add2_movie_service(m);
    }
    catch (ValidationException& exception) {
        cout << exception.getMessage() << '\n';
    }
    movies = service->get_list();
}

void QtWidgetsApplication1::delete_button_handler() {
    int id;
    id = ui.idEntry->text().toInt();
    if (service->validate_id(id)) {
        service->delete_movie_service(id);
    }
    else {
        cout << "Can't delete a movie that doesn't exist!\n";
    }
    movies = service->get_list();
}

void QtWidgetsApplication1::update_button_handler() {
    string title, genre, trailer;
    int likes, year,id;
    id = ui.idEntry->text().toInt();
    title = ui.titleEntry->text().toStdString();
    genre = ui.genreEdit->text().toStdString();
    trailer = ui.trailerEntry->text().toStdString();
    likes = ui.likesEntry->text().toInt();
    year = ui.yearLikes->text().toInt();
    Movie movie(id, title, genre, year, likes, trailer);
    try {
        service->update_movie_service(id, movie);
    }
    catch (ValidationException& exception) {
        cout << exception.getMessage() << '\n';
    }
    movies = service->get_list();
}


void QtWidgetsApplication1::exit_button_handler() {
    QApplication::exit();
}

//User part

void QtWidgetsApplication1::seeWatchlist_button_handler() {
    watchlist = service->get_watchlist_s();
    movies = service->get_list();
    for (int i : watchlist) {
        Movie m;
        m = movies[i];
        std::string movie_string;
        movie_string = to_string(m.get_id()) + ". " + m.get_genre() + ", " + to_string(m.get_id()) + ", " + to_string(m.get_likes()) + ", " + m.get_title() + ", " + m.get_title() + ", " + m.get_trailer() + ", " + to_string(m.get_year());
        QString item;
        item = QString::fromStdString(movie_string);
        ui.listWidget->addItem(item);
    }
}

void QtWidgetsApplication1::openWatchlist_button_handler() {
    service->open();
}
void QtWidgetsApplication1::updateWatchlist_button_handler() {

    watchlist = service->get_watchlist_s();
    string genre;
    genre = ui.genreEdit->text().toStdString();
    for (Movie m : movies) {
        if (m.get_genre() == genre) {
            std::string movie_string;
            movie_string = to_string(m.get_id()) + ". " + m.get_genre() + ", " + to_string(m.get_id()) + ", " + to_string(m.get_likes()) + ", " + m.get_title() + ", " + m.get_title() + ", " + m.get_trailer() + ", " + to_string(m.get_year());
            QString item;
            item = QString::fromStdString(movie_string);
            ui.listWidget->addItem(item);
            service->add_to_watchlist_s(m.get_id());
        }
    }
    service->write();
}

