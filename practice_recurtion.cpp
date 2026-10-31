#include <iostream>

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    int result = base * power(base, exponent - 1);
    return result;
}

void stars(int n);









int get_window_sum(int arr[], int start, int count) {
    if (count == 0) {
        return 0;
    }
    return arr[start] + get_window_sum(arr, start + 1, count - 1);
}






int find_min_subsequence_index(int arr[], int size, int i = 0, int window_size = 10, int min_sum = INT_MAX, int best_idx = 0) {
    if (i > size - window_size) {
        return best_idx;
    }

    int current_sum = get_window_sum(arr, i, window_size);

    if (current_sum < min_sum) {
        min_sum = current_sum;
        best_idx = i;
    }

    return find_min_subsequence_index(arr, size, i + 1, window_size, min_sum, best_idx);
}



int sumRange(int a, int b) {
    if (a > b) {
        return 0;
    }
    else {
        return a + sumRange(a + 1, b);
    }
}


int main()
{
    //number 1
    int base, exp;
    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter exp: ";
    std::cin >> exp;

    std::cout << base << "in" << exp << '=' << power(base, exp)<<'\n';

    //number 2
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    stars(n);

    //number 3
    int a, b;
    std::cout << "Введіть початкове число (a): ";
    std::cin >> a;
    std::cout << "Введіть кінцеве число (b): ";
    std::cin >> b;
    if (a > b) {
        std::cout << "Помилка: число 'a' має бути меншим або дорівнювати 'b'." << std::endl;
    }
    else {
        int result = sumRange(a, b);
        std::cout << "Сума чисел у діапазоні від " << a << " до " << b << " дорівнює: " << result << std::endl;
    }


    //number 4
    srand(time(NULL));
    int arr[100];
    int min = 1, max = 100;
    for (int i = 0; i < 100; i++) {
        int randomNumber = rand() % (max - min + 1) + min;
        arr[i] = randomNumber;
    }
    int start_position = find_min_subsequence_index(arr, 100);
    std::cout << "Znaidena pochatkova pozytsiia: " << start_position << '\n';
    std::cout << "Znaidena poslidovnist: ";
    for (int j = start_position; j < start_position + 10; ++j) {
        std::cout << arr[j] << " ";
    }
    std::cout << std::endl;
    std::cout << "Suma tsiiei poslidovnosti: " << get_window_sum(arr, start_position, 10) << '\n';
}

void stars(int n) {
    std::cout << '*';
    stars(n - 1);
    std::cout << '\n';
}
