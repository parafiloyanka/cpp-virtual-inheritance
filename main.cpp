#include <iostream>
#include <string>

using namespace std;

// Базовий клас Person
class Person {
protected:
    string name;
    string birth_date;
    string death_date;

public:
    // Конструктор
    Person(string name, string birth_date, string death_date) {
        this->name = name;
        this->birth_date = birth_date;
        this->death_date = death_date;
        cout << "Конструктор: " << this->name << " народився " << this->birth_date << endl;
    }

    // Геттери для доступу до даних
    string get_name() const {
        return name;
    }

    string get_birth_date() const {
        return birth_date;
    }

    string get_death_date() const {
        return death_date;
    }

    // Метод для відображення інформації
    void show_info() const {
        cout << "Ім'я: " << name << endl;
        cout << "Дата народження: " << birth_date << endl;
        cout << "Дата смерті: " << death_date << endl;
    }

    // Деструктор
    virtual ~Person() {
        cout << "Деструктор: " << name << " помер " << death_date << endl;
    }
};

// Прадідусі й прабабусі
class IvanDrahomanov : public virtual Person {
public:
    IvanDrahomanov() : Person("Іван Драгоманов", "1790", "1860") {}
};

class HannaDrahomanova : public virtual Person {
public:
    HannaDrahomanova() : Person("Ганна Драгоманова", "1795", "1870") {}
};

class IvanKosach : public virtual Person {
public:
    IvanKosach() : Person("Іван Косач", "1785", "1855") {}
};

class MariyaKosach : public virtual Person {
public:
    MariyaKosach() : Person("Марія Косач", "1790", "1865") {}
};

// Дідусі й бабусі
class MykhailoDrahomanov : public virtual Person {
public:
    MykhailoDrahomanov() : Person("Михайло Драгоманов", "1841", "1895") {}
};

class YelyzavetaDrahomanova : public virtual Person {
public:
    YelyzavetaDrahomanova() : Person("Єлизавета Драгоманова", "1825", "1890") {}
};

class MykhailoKosach : public virtual Person {
public:
    MykhailoKosach() : Person("Михайло Косач", "1819", "1884") {}
};

class AdelaidaKosach : public virtual Person {
public:
    AdelaidaKosach() : Person("Аделаїда Косач", "1820", "1893") {}
};

// Батьки
class PetroKosach : public virtual Person {
public:
    PetroKosach() : Person("Петро Косач", "1841", "1909") {}
};

class OlhaDrahomanova : public virtual Person {
public:
    OlhaDrahomanova() : Person("Ольга Драгоманова", "1849", "1930") {}
};

// Головний клас Лесі Українки
class LesyaUkrainka : public PetroKosach, public OlhaDrahomanova {
public:
    LesyaUkrainka() : PetroKosach(), OlhaDrahomanova(), Person("Леся Українка", "1871", "1913") {
        cout << "\nСтворення об'єкта Лесі Українки" << endl;
    }

    void show_genealogy() const {
        // Починаємо з прабабусь/прадідусів
        cout << "\nПрабабусі та прадідусі:" << endl;
        IvanDrahomanov().show_info();
        IvanKosach().show_info();
        HannaDrahomanova().show_info();
        MariyaKosach().show_info();

        // Бабусі та дідусі
        cout << "\nБабусі та дідусі:" << endl;
        MykhailoDrahomanov().show_info();
        MykhailoKosach().show_info();
        YelyzavetaDrahomanova().show_info();
        AdelaidaKosach().show_info();

        // Батьки
        cout << "\nБатьки:" << endl;
        PetroKosach().show_info();
        OlhaDrahomanova().show_info();

        // Дитина
        cout << "\nДитина (Леся Українка):" << endl;
        show_info();
    }
};

// Головний запуск програми
int main() {
    LesyaUkrainka lesya;
    lesya.show_genealogy();

    cout << "\nЗавершення програми" << endl;

    return 0;
}