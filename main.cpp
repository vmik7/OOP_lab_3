#include <iostream>
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
	my_vector(int x = 0, int y = 0, int z = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
    my_vector(int x_0, int y_0, int z_0, int x_1, int y_1, int z_1) {
		this->x = x_1 - x_0;
		this->y = y_1 - y_0;
		this->z = z_1 - z_0;
	}
	int get_x() const { return this->x; }
	int get_y() const { return this->y; }
	int get_z() const { return this->z; }
	
	
};
    
int main() {
	
	my_vector a, b(3, 4, 5), c(1, 2, 3, 4, 5, 6);
	
	cout << a.get_x() << " " << a.get_y() << " " << a.get_z() << endl;
	cout << b.get_x() << " " << b.get_y() << " " << b.get_z() << endl;
	cout << c.get_x() << " " << c.get_y() << " " << c.get_z() << endl;
  
    return 0;
}
