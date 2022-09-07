#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

// Defined the struct of Line
struct Line {
    Point start;
    Point end;
};

void set_x(Point &a, double value) {
    a.x = value;
}

void set_y(Point &a, double value) {
    a.y = value;
}

double x_of(const Point &a) {
    return a.x;
}

double y_of(const Point &a) {
    return a.y;
}

void make_line(Line &l, const Point &start, const Point &end) {
    set_x(l.start, x_of(start));
    set_y(l.start, y_of(start)); 
    
    set_x(l.end, x_of(end)); 
    set_y(l.end, y_of(end)); 
}

Point start_of(const Line &l) {
    return l.start;
}

Point end_of(const Line &l) {
    return l.end;
}

double length(const Line &l) {
    double x = end_of(l).x - start_of(l).x; 
    double y = end_of(l).y - start_of(l).y;
    
    return sqrt(pow(x, 2) + pow(y, 2));
}


int main() {
    Point point1;
    Point point2;

    point1.x = 1.0;
    point1.y = 2.0;
    point2.x = 3.0;
    point2.y = 4.0;

    Line line1;

    make_line(line1, point1, point2);       

    cout << line1.start.x << endl;
    cout << line1.start.y << endl;
    cout << line1.end.x << endl;
    cout << line1.end.y << endl;

    cout << start_of(line1).x << start_of(line1).y << endl;
    cout << end_of(line1).x << end_of(line1).y << endl;

    cout << length(line1) << endl;
}