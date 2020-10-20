#include <iostream>
#include <cmath>
using namespace std;

/*
Составить описание класса для объектов-векторов, задаваемых координатами концов в трехмерном пространстве.
Обеспечить операции сложения и вычитания векторов с получением нового вектора (суммы или разности),
вычисления скалярного произведения двух векторов, длины вектора, косинуса угла между векторами.
Написать программу, демонстрирующую работу с этим классом. Программа должна содержать меню,
позволяющее осуществить проверку всех методов класса.
*/

class my_vector {
private: 
    int x, y, z;
	
public:
	// Конструкторы со списками инициализации
	my_vector(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {}
    my_vector(int x_0, int y_0, int z_0, int x_1, int y_1, int z_1) : x(x_1 - x_0), y(y_1 - y_0), z(z_1 - z_0) {}
	
	// Доступ к координатам вектора
	int get_x() const { return this->x; }
	int get_y() const { return this->y; }
	int get_z() const { return this->z; }
	
	// Получение длины вектора
	double length() const {
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	
	// Сложение двух векторов
	my_vector operator + (const my_vector& t) const {
		return my_vector(this->x + t.x, this->y + t.y, this->z + t.z);
	}
	
	// Вычитание двух векторов
	my_vector operator - (const my_vector& t) const {
		return my_vector(this->x - t.x, this->y - t.y, this->z - t.z);
	}
	
	// Скалярное произведение двух векторов
	int operator * (const my_vector& t) const {
		return this->x * t.x + this->y * t.y + this->z * t.z;
	}
	
	// Вычисление косинуса угла междлу векторами
	double cos(const my_vector& t) const {
		return (double)(*this * t) / (this->length() * t.length());
	}
};
    
int main() {
	
	my_vector a, b(3, 4, 5), c(1, 2, 3, 4, 5, 6);
	
	cout << a.get_x() << " " << a.get_y() << " " << a.get_z() << " " << a.length() << endl;
	cout << b.get_x() << " " << b.get_y() << " " << b.get_z() << " " << b.length() << endl;
	cout << c.get_x() << " " << c.get_y() << " " << c.get_z() << " " << c.length() << endl;
	
	my_vector d = b + c;
	cout << d.get_x() << " " << d.get_y() << " " << d.get_z() << " " << d.length() << endl;
	
	my_vector e = c - b;
	cout << e.get_x() << " " << e.get_y() << " " << e.get_z() << " " << e.length() << endl;
	
	cout << b * c << endl;
	
	cout << b.cos(b) << endl;
	
    return 0;
}
