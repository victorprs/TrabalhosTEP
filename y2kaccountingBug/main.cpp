#include <iostream>

using namespace std;

const int nr_months = 12, nr_posts = 8, nr_consecutive_posts = 5;
int s, d, result, posts[nr_months];

void calculate_amount(int pi, int amount)
{
  if (pi == nr_posts) {
    amount = 0;
    for (int i = 0; i < nr_months; i++) {
      amount += posts[i];
    }
    if (amount > result)
      result = amount;
  }
  else if (!pi) {
    int i;
    for (i = 0; i < nr_consecutive_posts; i++) {
      posts[i] = s;
      amount += s;
    }
    for (i--; i >= 0 && amount >= 0; i--) {
      posts[i] = -d;
      amount -= s + d;
    }
    calculate_amount(pi + 1, amount);
  }
  else {
    amount -= posts[pi - 1];
    posts[pi + nr_consecutive_posts - 1] = (amount + s < 0) ? s : -d;
    amount += posts[pi + nr_consecutive_posts - 1];
    calculate_amount(pi + 1, amount);
  }
}

int main()
{
    while (cin >> s) {
        cin >> d;
        result = -1;
        calculate_amount(0,0);
        if (result >= 0)
            cout << result << endl;
        else
            cout << "Deficit" << endl;
    }
    return 0;
}
