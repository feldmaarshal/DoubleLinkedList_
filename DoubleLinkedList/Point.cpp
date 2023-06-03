#include "Point.hpp"
// конструкторы

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point& other) {
    this->x = other.x;
    this->y = other.y;
}


//деструкторы

Point::~Point() {}



// геттеры и сеттеры

void Point::SetX(int value) {
    this->x = value;
}

void Point::SetY(int value) {
    this->y = value;
}



// Операторы(методы)

Point Point:: operator +(const Point& other) {
    Point temp;
    temp.x = other.x + this->x;
    temp.y = other.y + this->y;
    return temp;
}

Point Point:: operator +(int value) {
    Point temp;
    temp.x = this->x + value;
    temp.y = this->y + value;
    return temp;
}

Point& Point::operator +=(const Point& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;

}

Point& Point::operator +=(int value) {
    this->x += value;
    this->y += value;
    return *this;
}

Point Point:: operator+() {
    this->x = x < 0 ? -x:x;
    this->y = y < 0 ? -y:y;
    return *this;
}

Point Point:: operator-() {
    this->x = -x;
    this->y = -y;
    return *this;
}

// глобальные фукнции


Point operator -=(Point& name, int value) {
    name.x = name.x - value;
    name.y = name.y - value;
    return name;
}

Point operator -(Point& name, int value) {
    Point temp;
    temp.x = name.x - value;
    temp.y = name.y - value;
    return temp;
}

Point operator -(Point& one, Point& two) {
    Point temp;
    temp.x = one.x - two.x;
    temp.y = one.y - two.y;
    return temp;
}

Point operator +(int value, Point& name) {
    Point temp;
    temp.x = value + name.x;
    temp.y = value + name.y;
    return temp;
};
