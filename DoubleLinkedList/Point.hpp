#pragma once
class Point {
    int x, y;
public:
    Point();
    Point(const Point& other);
    Point(int x, int y);

    ~Point();

    int GetX() { return x; };
    int GetY() { return y; };

    void SetX(int value);
    void SetY(int value);

    Point& operator +=(const Point& other);
    Point& operator +=(int value);
    Point operator +(const Point& other);
    Point operator +(int value);
    Point operator +();
    Point operator -();
    
    friend Point operator +(int value, Point& name);
    friend Point operator -(Point& name, int value);
    friend Point operator -=(Point& name, int value);
    friend Point operator -(Point& one, Point& two);
};



