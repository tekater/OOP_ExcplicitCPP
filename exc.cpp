#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Reservoir {
    int length; int width; int depth; 

    char* name;

    int area;
    int size;

    bool same = false;
public:
    Reservoir(const char* uname, int len, int wid, int dep) {
        name = new char[strlen(uname + 1)];
        strcpy(name, uname);
        length = len;
        width = wid;
        depth = dep;
    }
    Reservoir():Reservoir("None", 10, 10, 20) {}

    Reservoir(Reservoir& r) {
        name = new char[strlen(r.name) + 1];
        length = r.length;
        width = r.width;
        depth = r.depth;
        strcpy(name, r.name);
    }

    void ReSize(Reservoir& r) {
        if (length <= 0 || width <= 0 || depth <= 0) {
            cout << "Заполните значения.\n";
        }
        else {
            size = length * width * depth;
            cout << "Объём равен: " << width << endl;
        }
    }

    void ReArea(Reservoir& r) {
        r.area = r.length * r.width;
        cout << "Площадь равна: " << r.area << endl;
    }

    void ReWater(Reservoir& r, Reservoir& d) {
        if ((r.size <= 15 && r.size > 0) && (d.size <= 15 && d.size > 0)) {
            cout << "Эти водоёмы являются - Бассейнами.\n";
            d.same = true; r.same = true;
        }
        else if ((r.size <= 40 && r.size > 15) && (d.size <= 40 && d.size > 15)) {
            cout << "Эти водоёмы являются - Прудами.\n";
            d.same = true; r.same = true;
        }
        else if ((r.size <= 60 && r.size > 40) && (d.size <= 60 && d.size > 40)) {
            cout << "Эти водоёмы являются - Озёрами.\n";
            d.same = true; r.same = true;
        }
        else if ((r.size <= 100 && r.size > 60) && (d.size <= 100 && d.size > 60)) {
            cout << "Эти водоёмы являются - Морями.\n";
            d.same = true; r.same = true;
        }
        else if ((r.size > 100) && (d.size > 100)) {
            cout << "Эти водоёмы являются - Океанами.\n";
            d.same = true; r.same = true;
        }
        else {
            cout << "Эти водоёмы разные.\n";
        }
    }
    void Sravnenie(Reservoir& r, Reservoir& d) {
        if (r.area == d.area) {
            cout << "Площади равны\n";
        }
        else {
            cout << "Площади не равны\n";
        }
    }
    void CopyLength(Reservoir& r, Reservoir& d) {
        r.length = d.length;
    }
    void CopyWidth(Reservoir& r, Reservoir& d) {
        r.width = d.width;
    }
    void CopyDepth(Reservoir& r, Reservoir& d) {
        r.depth = d.depth;
        
    }
    void CopyObject(Reservoir& r, Reservoir& d) {
        r.size = d.size;
        r.width = d.width;
        r.size = d.size;
        delete[] r.name;
        r.name = new char[strlen(d.name)+1];
        strcpy(r.name, d.name);
    }
    ~Reservoir() {
        delete[] name;
    }
};
class Array {
    int* arr;
    int size;
public:
    explicit Array(int usize = 5) : arr{ new int[usize] }, size{ usize }
    {
        randomize(10, 20);
        cout << "Конструктор с параметром\n";
    }
    ~Array()
    {
        if (arr)
        {
            delete[]arr;
        }
        cout << "Деструктор\n";
    }
    
    void randomize(int a, int b) //10 20
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = a + rand() % (b - a + 1); //10-29
        }
    }
    void setElem(int ind, int x)
    {
        arr[ind] = x;
    }
    int getElem(int ind) const
    {
        return arr[ind];
    }
    int getSize() const { 
        return size;
    }
};

class Book {
    char* autor;
    char* name;
    
    double rating;

    double marks;
    int year;
    int papers;
public:
    Book(const char* aut, const char* uname, double mark, int paper,int years) {
        autor = new char[strlen(aut) + 1];
        strcpy(autor, aut);

        name = new char[strlen(uname) + 1];
        strcpy(name, uname);

        marks = mark;
        papers = paper;

        year = years;

    }
    void sortMarker(const Book* b, int size, const char* Uauthor) {
        for (int i = 0; i < size; i++) {
            if (strstr(b[i].autor,Uauthor)) {
                cout << "Книга: " << b[i].name << "\n";
            }
        }
    }

};
void print(const Array& obj)
{
    for (int i = 0; i < obj.getSize(); i++)
    {
        cout << obj.getElem(i) << " ";
    }
    cout << endl;
}
void main() {

    setlocale(0, "");
    srand(time(NULL));

    /*Reservoir lake("Duviri",30,30,60);
    Reservoir lake2("Deimos",30,30,60);

    lake.ReArea(lake); lake.ReSize(lake); cout << "\n";
    lake2.ReArea(lake2); lake2.ReSize(lake2); cout << "\n";

    lake.Sravnenie(lake, lake2); cout << "\n";

    lake.ReWater(lake, lake2);*/
    Book b[5] = { {"Михаил Булгаков","Мастер и Маргарита",6.3,32,1928},
                  {"Федор Михайлович Достоевский","Преступление и наказание",5.7,574,1866},
                  {"Михаил Булгаков","Собачье сердце",9.8,85,1925},
                  {"Михаил Лермонтов","Герой нашего времени",6.5,232,1840},
                  {"Джон Рональд Руэл Толкин","Властелин колец",8.2,600,1954} };

    b->sortMarker(b, 5, "Михаил Булгаков");


}
