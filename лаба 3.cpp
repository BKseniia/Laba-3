#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// задача 1. человек
class Person {
private:
    std::string name_;
    int height_;

public:
    Person(const std::string& name, int height)
        : name_(name), height_(height) {
    }

    void print() const {
        std::cout << name_ << ", рост: " << height_ << std::endl;
    }
};

// задача 2. имена
class Name {
private:
    std::string surname_;
    std::string first_name_;
    std::string patronymic_;

public:
    Name(const std::string& surname = "",
        const std::string& first_name = "",
        const std::string& patronymic = "")
        : surname_(surname),
        first_name_(first_name),
        patronymic_(patronymic) {
    }

    std::string GetFullName() const {
        std::string full_name;

        if (!surname_.empty()) {
            full_name += surname_;
        }

        if (!first_name_.empty()) {
            if (!full_name.empty()) {
                full_name += " ";
            }
            full_name += first_name_;
        }

        if (!patronymic_.empty()) {
            if (!full_name.empty()) {
                full_name += " ";
            }
            full_name += patronymic_;
        }

        return full_name;
    }

    void print() const {
        std::cout << GetFullName() << std::endl;
    }
};

// задача 3. человек с именем
class PersonWithName {
private:
    Name name_;
    int height_;

public:
    PersonWithName(const Name& name, int height)
        : name_(name), height_(height) {
    }

    void print() const {
        std::cout << name_.GetFullName()
            << ", рост: " << height_ << std::endl;
    }
};

// задача 4. города
class City {
private:
    struct Path {
        City* city;
        int cost;
    };

    std::string name_;
    std::vector<Path> paths_;

public:
    City(const std::string& name)
        : name_(name) {
    }

    City(const std::string& name,
        const std::vector<std::pair<City*, int>>& paths)
        : name_(name) {
        for (const auto& path : paths) {
            paths_.push_back({ path.first, path.second });
        }
    }

    void AddPath(City& city, int cost) {
        paths_.push_back({ &city, cost });
    }

    void print() const {
        std::cout << name_ << ": ";

        for (const Path& path : paths_) {
            std::cout << path.city->name_
                << ":" << path.cost << " ";
        }

        std::cout << std::endl;
    }
};

// задача 5. дроби
class Fraction {
private:
    int numerator_;
    int denominator_;

public:
    // конструктор
    Fraction(int numerator, int denominator)
        : numerator_(numerator), denominator_(denominator) {
        if (denominator_ == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю");
        }
    }

    // преобразование дроби в строку
    std::string ToString() const {
        return std::to_string(numerator_) + "/" +
            std::to_string(denominator_);
    }

    // сложение с дробью
    Fraction sum(const Fraction& other) const {
        return Fraction(
            numerator_ * other.denominator_ +
            other.numerator_ * denominator_,
            denominator_ * other.denominator_
        );
    }

    // сложение с целым числом
    Fraction sum(int number) const {
        return Fraction(
            numerator_ + number * denominator_,
            denominator_
        );
    }

    // вычитание дроби
    Fraction minus(const Fraction& other) const {
        return Fraction(
            numerator_ * other.denominator_ -
            other.numerator_ * denominator_,
            denominator_ * other.denominator_
        );
    }

    // вычитание целого числа
    Fraction minus(int number) const {
        return Fraction(
            numerator_ - number * denominator_,
            denominator_
        );
    }

    // кмножение на дробь
    Fraction multiply(const Fraction& other) const {
        return Fraction(
            numerator_ * other.numerator_,
            denominator_ * other.denominator_
        );
    }

    // умножение на целое число
    Fraction multiply(int number) const {
        return Fraction(
            numerator_ * number,
            denominator_
        );
    }

    // деление на дробь
    Fraction div(const Fraction& other) const {
        if (other.numerator_ == 0) {
            throw std::invalid_argument("Деление на ноль");
        }

        return Fraction(
            numerator_ * other.denominator_,
            denominator_ * other.numerator_
        );
    }

    // деление на целое число
    Fraction div(int number) const {
        if (number == 0) {
            throw std::invalid_argument("Деление на ноль");
        }

        return Fraction(
            numerator_,
            denominator_ * number
        );
    }

    // вывод 
    void print() const {
        std::cout << ToString() << std::endl;
    }
};


// функция 1 
void RunPersonTask() {
    std::cout << "\nЗадача 1. Человек" << std::endl;

    Person person1("Клеопатра", 152);
    Person person2("Пушкин", 167);
    Person person3("Владимир", 189);

    person1.print();
    person2.print();
    person3.print();

    std::cout << std::endl;
}

// функция 2 
void RunNameTask() {
    std::cout << "\nЗадача 2. Имена" << std::endl;

    Name name1("Клеопатра");
    Name name2("Пушкин", "Александр", "Сергеевич");
    Name name3("Маяковский", "Владимир");

    name1.print();
    name2.print();
    name3.print();

    std::cout << std::endl;
}

// функция 3 
void RunPersonWithNameTask() {
    std::cout << "\nЗадача 3. Человек с именем" << std::endl;

    Name name1("Клеопатра");
    Name name2("Пушкин", "Александр", "Сергеевич");
    Name name3("Маяковский", "Владимир");

    PersonWithName person1(name1, 152);
    PersonWithName person2(name2, 167);
    PersonWithName person3(name3, 189);

    person1.print();
    person2.print();
    person3.print();

    std::cout << std::endl;
}

// функция 4 
void RunCityTask() {
    std::cout << "\nЗадача 4. Города" << std::endl;

    City cityA("A");
    City cityB("B");
    City cityC("C");
    City cityD("D");
    City cityE("E");
    City cityF("F");

    // добавление путей между городами
    cityA.AddPath(cityF, 1);
    cityA.AddPath(cityD, 6);
    cityA.AddPath(cityB, 5);

    cityB.AddPath(cityA, 5);
    cityB.AddPath(cityC, 3);

    cityC.AddPath(cityB, 3);
    cityC.AddPath(cityD, 4);

    cityD.AddPath(cityC, 4);
    cityD.AddPath(cityE, 2);
    cityD.AddPath(cityA, 6);

    cityE.AddPath(cityF, 2);

    cityF.AddPath(cityB, 1);
    cityF.AddPath(cityE, 2);

    // вывод информации
    cityA.print();
    cityB.print();
    cityC.print();
    cityD.print();
    cityE.print();
    cityF.print();

    std::cout << std::endl;
}

// функция 5 
void RunFractionTask() {
    std::cout << "\nЗадача 5. Дроби" << std::endl;

    Fraction f1(1, 3);
    Fraction f2(2, 3);
    Fraction f3(3, 4);

    // сложение
    std::cout << f1.ToString() << " + " << f2.ToString()
        << " = " << f1.sum(f2).ToString() << std::endl;

    // вычитание
    std::cout << f1.ToString() << " - " << f2.ToString()
        << " = " << f1.minus(f2).ToString() << std::endl;

    // умножение
    std::cout << f1.ToString() << " * " << f2.ToString()
        << " = " << f1.multiply(f2).ToString() << std::endl;

    // деление
    std::cout << f1.ToString() << " / " << f2.ToString()
        << " = " << f1.div(f2).ToString() << std::endl;

    // операции с целыми числами
    std::cout << f1.ToString() << " + 2 = "
        << f1.sum(2).ToString() << std::endl;

    std::cout << f1.ToString() << " - 2 = "
        << f1.minus(2).ToString() << std::endl;

    std::cout << f1.ToString() << " * 2 = "
        << f1.multiply(2).ToString() << std::endl;

    std::cout << f1.ToString() << " / 2 = "
        << f1.div(2).ToString() << std::endl;

    // последовательное выполнение операций
    Fraction result = f1.sum(f2).div(f3).minus(5);

    std::cout << "\nf1.sum(f2).div(f3).minus(5) = "
        << result.ToString() << std::endl;

    std::cout << std::endl;
}



int main() {
    setlocale(LC_ALL, "Russian");
    int choice = -1;

    while (true) {
        std::cout << "1. Человек" << std::endl;
        std::cout << "2. Имена" << std::endl;
        std::cout << "3. Человек с именем" << std::endl;
        std::cout << "4. Города" << std::endl;
        std::cout << "5. Дроби" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Ваш выбор: ";

        if (!(std::cin >> choice)) {
            std::cout << "Ошибка! Введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else {
            switch (choice) {
            case 1:
                RunPersonTask();
                break;
            case 2:
                RunNameTask();
                break;
            case 3:
                RunPersonWithNameTask();
                break;
            case 4:
                RunCityTask();
                break;
            case 5:
                RunFractionTask();
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                return 0;
            default:
                std::cout << "Такой задачи нет. Попробуйте снова." << std::endl;
            }
        }
    }

    return 0;
}
