#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include "Service.h"

/*
class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget* parent = Q_NULLPTR);
    Ui::QtWidgetsApplication1Class ui;
};
*/
class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);
    int a;
    void connect_signals_and_slots();
private:
    Service* service;
    vector<Movie> movies;
    vector<int> watchlist;
    Ui::QtWidgetsApplication1Class ui;
    //Ui::connect_signals_and_slots();
    void HTML_button_handler();
    void CSV_button_handler();
    void A_button_handler();
    void U_button_handler();
    void seeAll_button_handler();
    void add_button_handler();
    void delete_button_handler();
    void update_button_handler();
    void exit_button_handler();
    void seeWatchlist_button_handler();
    void openWatchlist_button_handler();
    void updateWatchlist_button_handler();
};
