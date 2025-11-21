#include <stdio.h>

struct Product {
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct Product products[5];
    float totalValue = 0;
    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin san pham thu %d:\n", i + 1);
        printf("Ten san pham: ");
        fflush(stdin); 
        fgets(products[i].name, sizeof(products[i].name), stdin);
        printf("Gia san pham: ");
        scanf("%f", &products[i].price);
        printf("So luong: ");
        scanf("%d", &products[i].quantity);
        totalValue += products[i].price * products[i].quantity;
    }
    printf("Tong gia tri tat ca san pham: %.2f\n", totalValue);

    return 0;
}

