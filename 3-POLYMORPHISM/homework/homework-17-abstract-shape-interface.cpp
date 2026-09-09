#include <iostream>
#include <string>

using namespace std;
class Shape{
    public:
    virtual void draw()  = 0;
    virtual double calculateArea() = 0;
    virtual void resize(double val) = 0;

};
class DrawableShape : public Shape{
    public:
    void draw()override{
        cout << "Drawing: ";
    }
};
class Square : public DrawableShape{
    private:
    double side;
    public:
    void resize(double val)override{
        side = side * val;
    }
    void draw()override{
        DrawableShape::draw();
        cout << " square" << endl;
    }
    Square(double side){
        this -> side = side;
    }
    virtual ~Square(){}
    double calculateArea()override{
        return side*side;
    }
};
class Circle : public DrawableShape{
    private:
    double radius;
    public:
    void resize(double val)override{
        radius = radius * val;
    }
    void draw()override{
        DrawableShape::draw();
        cout << " circle" <<endl;
    }
    Circle(double radius){
        this ->radius = radius;
    }
    const double pi = 3.14;
    virtual ~Circle(){}
    double calculateArea()override{
        return pi*radius*radius;
    }

};
int main() {

    // Tip 4: Demonstrate the use of the interface or abstract class
    Circle circle(5.0);
    Square square(4.0);

    // Drawing and calculating area for the circle
    circle.draw();
    cout << "Circle Area: " << circle.calculateArea() << endl;
    circle.resize(1.5);
    cout << "Resized Circle Area: " << circle.calculateArea() << endl;

    // Drawing and calculating area for the square
    square.draw();
    cout << "Square Area: " << square.calculateArea() << endl;
    square.resize(2.0);
    cout << "Resized Square Area: " << square.calculateArea() << endl;

    return 0;
}
