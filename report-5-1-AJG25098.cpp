//AJG25098 三江海世

今回の課題では、クラスの継承や仮想関数、ポインタを使ったプログラムの作り方について学んだ。特に、基本クラスを継承した派生クラスを作ることで、商品ごとに異なる料金計算を実現できる点が印象に残った。また、基本クラスのポインタから派生クラスの関数を呼び出せる仕組みについても理解を深めることができた。


#include <iostream>
#include <string>
#include "assignment5.h"

using namespace std;

// りんごクラス
class Apple : public base {
public:
    Apple() : base("apple", 1000.0) {}

    double get_price(double weight) override {
        return unit_price * weight;
    }
};

// ヨーグルトクラス
class Yogurt : public base {
public:
    Yogurt() : base("yogurt", 300.0) {}

    double get_price(double weight) override {
        return unit_price * weight + 50.0;
    }
};

int main() {
    Apple apple;
    Yogurt yogurt;

    
    base* p;

    string input_name;
    double weight;

    while (true) {
        cout << "Enter 'name' (apple or yogurt)." << endl;
        cin >> input_name;

        
        if (input_name == "apple") {
            p = &apple;
        }
        else if (input_name == "yogurt") {
            p = &yogurt;
        }
        else {
            cout << "Invalid name." << endl;
            continue;
        }

        cout << "Enter 'weight' (kg)." << endl;
        cin >> weight;

        
        double price = p->get_price(weight);

        cout << "The price of " << p->get_name()
             << " is " << price << " yen" << endl;
    }

    return 0;
}
