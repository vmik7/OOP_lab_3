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

	// Изменение координат
	void set_x(int value) { this->x = value; }
    void set_y(int value) { this->y = value; }
    void set_z(int value) { this->z = value; }

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

	int x_0, y_0, z_0, x_1, y_1, z_1;

	cout << "Введите крайние точки первого вектора: " << endl;

	cout << "x[0]: ";
	cin >> x_0;
	cout << "y[0]: ";
	cin >> y_0;
	cout << "z[0]: ";
	cin >> z_0;

	cout << "x[1]: ";
	cin >> x_1;
	cout << "y[1]: ";
	cin >> y_1;
	cout << "z[1]: ";
	cin >> z_1;

	my_vector a(x_0, y_0, z_0, x_1, y_1, z_1);

	cout << "Введите крайние точки второго вектора: " << endl;

	cout << "x[0]: ";
	cin >> x_0;
	cout << "y[0]: ";
	cin >> y_0;
	cout << "z[0]: ";
	cin >> z_0;

	cout << "x[1]: ";
	cin >> x_1;
	cout << "y[1]: ";
	cin >> y_1;
	cout << "z[1]: ";
	cin >> z_1;

	my_vector b(x_0, y_0, z_0, x_1, y_1, z_1);

	cout << "\nКоординаты первого вектора:\n";
	cout << a.get_x() << " " << a.get_y() << " " << a.get_z() << endl;
	cout << "Длина: " << a.length() << endl;

	cout << "\nКоординаты второго вектора:\n";
	cout << b.get_x() << " " << b.get_y() << " " << b.get_z() << endl;
	cout << "Длина: " << b.length() << endl;

	my_vector sum = a + b;
	cout << "\nКоординаты суммы этих векторов:\n";
	cout << sum.get_x() << " " << sum.get_y() << " " << sum.get_z() << endl;
	cout << "Длина: " << sum.length() << endl;

    my_vector dif = a - b;
    cout << "\nКоординаты разности этих векторов:\n";
    cout << dif.get_x() << " " << dif.get_y() << " " << dif.get_z() << endl;
    cout << "Длина: " << dif.length() << endl;

    cout << "\nСкалярное произведение этих векторов:\n";
    cout << a * b << endl;

    cout << "\nКосинус угла между векторами:\n";
    cout << a.cos(b) << endl;

    return 0;
}
