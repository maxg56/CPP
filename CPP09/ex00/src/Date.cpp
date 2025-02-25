#include "Date.hpp"
#include <ctime>

// Constructeur par défaut : initialise la date à la date actuelle
Date::Date() {
    _maintenant();
}

// Constructeur avec paramètres
Date::Date(int day, int month, int year) 
: _day(day), _month(month), _year(year) ,is_valide(true) 
{
    _check_date();
}

// Constructeur par copie
Date::Date(Date const &src) 
{
    *this = src;
}

// Destructeur
Date::~Date() {}

// Opérateur d'affectation
Date &Date::operator=(Date const &other) {
    if (this != &other) {
        _day = other._day;
        _month = other._month;
        _year = other._year;
    }
    return *this;
}

// Détermine si l'année est bissextile
bool Date::_bissextile() const {
    return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
}

int Date::_longueur_mois(int month) const {
    if (month < 1 || month > 12) // Vérifier la validité de month
        return 0;
    static const int jours_par_mois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && _bissextile())
        return 29;
    return jours_par_mois[month - 1];
}

void Date::_check_date() {
    this->is_valide = true; // Par défaut, on considère que la date est valide
    if (_month < 1 || _month > 12 || _day < 1 || _day > _longueur_mois(_month)) {
        this->is_valide = false;
    }
}

// Initialise la date au jour actuel
void Date::_maintenant() {
    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    _day = ltm->tm_mday;
    _month = ltm->tm_mon + 1;
    _year = ltm->tm_year + 1900;
    this->is_valide = true;
}

// Opérateurs de comparaison
bool Date::operator==(Date const &rhs) const { return _day == rhs._day && _month == rhs._month && _year == rhs._year; }
bool Date::operator!=(Date const &rhs) const { return !(*this == rhs); }
bool Date::operator<(Date const &rhs) const { return _year < rhs._year || (_year == rhs._year && (_month < rhs._month || (_month == rhs._month && _day < rhs._day))); }
bool Date::operator>(Date const &rhs) const { return rhs < *this; }
bool Date::operator<=(Date const &rhs) const { return !(rhs < *this); }
bool Date::operator>=(Date const &rhs) const { return !(*this < rhs); }

// Opérateurs d'incrémentation et de décrémentation
Date &Date::operator++() {
    if (++_day > _longueur_mois(_month)) {
        _day = 1;
        if (++_month > 12) {
            _month = 1;
            ++_year;
        }
    }
    return *this;
}

Date Date::operator++(int) {
    Date tmp(*this);
    ++(*this);
    return tmp;
}

Date &Date::operator--() 
{
    if (--_day < 1) {
        if (--_month < 1) {
            _month = 12;
            --_year;
        }
        _day = _longueur_mois(_month);
    }
    return *this;
}

Date Date::operator--(int)
{
    Date tmp(*this);
    --(*this);
    return tmp;
}

// Opérateurs arithmétiques
Date &Date::operator+=(int days) 
{
    while (days--) ++(*this);
    return *this;
}

Date &Date::operator-=(int days) 
{
    while (days--) --(*this);
    return *this;
}

Date Date::operator+(int days) const 
{
    Date tmp(*this);
    tmp += days;
    return tmp;
}

Date Date::operator-(int days) const 
{
    Date tmp(*this);
    tmp -= days;
    return tmp;
}

// Getters
int Date::getDay() const { return _day; }
int Date::getMonth() const { return _month; }
int Date::getYear() const { return _year; }

// Surcharge de l'opérateur de sortie
std::ostream &operator<<(std::ostream &o, Date const &i) {
    o << (i.getDay() < 10 ? "0" : "") << i.getDay() << "-"
      << (i.getMonth() < 10 ? "0" : "") << i.getMonth() << "-"
      << i.getYear();
    return o;
}
