// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <deque>
using namespace std;

struct hdr {
    float angle;
    float data;
    int64_t time;
};

class Smooth {
private:
    int size_window;//Размер окна сглаживания
    deque <hdr> input;
public:
    Smooth(int size) : size_window(size) { }

    void put_data(hdr input_struct) {
    if (input.size() >= size_window){
        input.pop_front();
    }
    input.push_back(input_struct);
    }  

    hdr smooth_data(hdr input_struct) {
    put_data(input_struct);
    hdr output_struct;
    output_struct.angle = calculating_smooth_angle(input.size());
    int number = 0;
    if (input.size() < size_window) 
        number = input.size() % 2 ? input.size() / 2 : input.size() / 2 - 1;
    else  
        number = size_window % 2 ? size_window / 2 : (size_window / 2) - 1;
            
    output_struct.data = input.at(number).data;
    output_struct.time = input.at(number).time;
    return output_struct;
    }

    float calculating_smooth_angle(int window) {
        float angles_smooth = 0;
        for (int i = 0; i < window; i++) {
            angles_smooth += input.at(i).angle;
        }
        angles_smooth /= window;
        return angles_smooth;
    }
};

int main()
{
    hdr example;
    Smooth s(5);
    for (int i = 0; i < 7; i++) {
        cout << "angle";
        cin >> example.angle;
        cout << "data";
        cin >> example.data;
        cout << "time";
        cin >> example.time;
        hdr answer = s.smooth_data(example);
        cout << example.angle << " " << example.time << "   " << answer.angle << " " << answer.time << endl;
    }
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
