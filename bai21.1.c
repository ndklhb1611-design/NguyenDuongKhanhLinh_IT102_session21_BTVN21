#include <stdio.h>

struct Car {
    char model[50];
    int year;
    float price;
};

int main() {
    struct Car Car1={"Mercedes-AMG-GT", 2020, 11000000000 };

    printf("Thong tin xe:\n");
    printf("Model: %s\n", Car1.model);
    printf("Nam san xuat: %d\n", Car1.year);
    printf("Gia: %.0f VND\n", Car1.price);

    return 0;
}
