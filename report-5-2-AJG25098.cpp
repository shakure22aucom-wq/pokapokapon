//AJG25098 三江海世

今回の課題では、友愛数を求めるプログラムを作成することで、約数の求め方や繰り返し処理、条件分岐について学んだ。特に、2つの数についてそれぞれ自分自身を除いた約数の和を計算し、互いに元の数と一致するかを調べる考え方が興味深かった。普段あまり意識しない数の性質をプログラムで確認でき、条件を整理して処理することの大切さが分かった。

#include <iostream>
using namespace std;

int divisor_sum(int n) {
    int sum = 0;

    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    cout << "2000以下の友愛数の組：" << endl;

    for (int i = 1; i <= 2000; i++) {
        int sum1 = divisor_sum(i);

        if (sum1 > i && sum1 <= 2000) {
            int sum2 = divisor_sum(sum1);

            if (sum2 == i) {
                cout << i << " と " << sum1 << endl;
            }
        }
    }

    return 0;
}
