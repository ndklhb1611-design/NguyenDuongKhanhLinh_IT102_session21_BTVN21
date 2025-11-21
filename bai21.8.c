#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char productID[20];
    char productName[50];
    int importPrice;
    int sellPrice;
    int quantity;
} Product;

Product productList[MAX];
int productCount = 0;
long long revenue = 0;

int findProductIndex(char productID[]) {
    for (int i = 0; i < productCount; i++) {
        if (strcmp(productList[i].productID, productID) == 0)
            return i;
    }
    return -1;
}

void inputProductList() {
    printf("Nhap so luong san pham: ");
    scanf("%d", &productCount);
    for (int i = 0; i < productCount; i++) {
        printf("\nSan pham %d:\n", i + 1);
        printf("Ma san pham: "); scanf("%s", productList[i].productID);
        printf("Ten san pham: "); scanf("%s", productList[i].productName);
        printf("Gia nhap: "); scanf("%d", &productList[i].importPrice);
        printf("Gia ban: "); scanf("%d", &productList[i].sellPrice);
        printf("So luong: "); scanf("%d", &productList[i].quantity);
    }
}

void displayProducts() {
    printf("\n----------------- DANH SACH SAN PHAM ---------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%s - %s - GiaNhap:%d - GiaBan:%d - SL:%d\n",
            productList[i].productID,
            productList[i].productName,
            productList[i].importPrice,
            productList[i].sellPrice,
            productList[i].quantity
        );
    }
}

void importProduct() {
    char id[20];
    int importQty;
    printf("Nhap ma san pham: ");
    scanf("%s", id);
    int index = findProductIndex(id);
    printf("Nhap so luong can nhap: ");
    scanf("%d", &importQty);
    if (index != -1) {
        productList[index].quantity += importQty;
        revenue -= (long long)importQty * productList[index].importPrice;
        printf("Da nhap them hang!\n");
    } else {
        strcpy(productList[productCount].productID, id);
        printf("Ten san pham: "); scanf("%s", productList[productCount].productName);
        printf("Gia nhap: "); scanf("%d", &productList[productCount].importPrice);
        printf("Gia ban: "); scanf("%d", &productList[productCount].sellPrice);
        productList[productCount].quantity = importQty;
        revenue -= (long long)importQty * productList[productCount].importPrice;
        productCount++;
        printf("Da them san pham moi!\n");
    }
}

void updateProduct() {
    char id[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", id);
    int index = findProductIndex(id);
    if (index == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    printf("Ten moi: "); scanf("%s", productList[index].productName);
    printf("Gia nhap moi: "); scanf("%d", &productList[index].importPrice);
    printf("Gia ban moi: "); scanf("%d", &productList[index].sellPrice);
    printf("Da cap nhat!\n");
}

void sortProducts() {
    int choice;
    printf("1. Tang dan\n2. Giam dan\nChon: ");
    scanf("%d", &choice);
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = i + 1; j < productCount; j++) {
            int asc = (choice == 1 && productList[i].sellPrice > productList[j].sellPrice);
            int desc = (choice == 2 && productList[i].sellPrice < productList[j].sellPrice);
            if (asc || desc) {
                Product temp = productList[i];
                productList[i] = productList[j];
                productList[j] = temp;
            }
        }
    }
    printf("Da sap xep!\n");
}

void searchProduct() {
    char id[20];
    printf("Nhap ma san pham can tim: ");
    scanf("%s", id);
    int index = findProductIndex(id);
    if (index == -1)
        printf("Khong tim thay san pham!\n");
    else
        printf("%s - %s - GiaNhap:%d - GiaBan:%d - SL:%d\n",
            productList[index].productID,
            productList[index].productName,
            productList[index].importPrice,
            productList[index].sellPrice,
            productList[index].quantity
        );
}

void sellProduct() {
    char id[20];
    int sellQty;
    printf("Nhap ma san pham can ban: ");
    scanf("%s", id);
    int index = findProductIndex(id);
    if (index == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    if (productList[index].quantity == 0) {
        printf("San pham het hang!\n");
        return;
    }

    printf("Nhap so luong can ban: ");
    scanf("%d", &sellQty);
    if (sellQty > productList[index].quantity) {
        printf("Khong du hang!\n");
        return;
    }

    productList[index].quantity -= sellQty;
    revenue += (long long)sellQty * productList[index].sellPrice;
    printf("Ban thanh cong!\n");
}

void showRevenue() {
    printf("Doanh thu hien tai: %lld\n", revenue);
}

int main() {
    int choice;

    do {
        printf("\n==================== MENU =====================\n");
        printf("1. Nhap danh sach san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap them san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Xem doanh thu\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: inputProductList(); break;
            case 2: displayProducts(); break;
            case 3: importProduct(); break;
            case 4: updateProduct(); break;
            case 5: sortProducts(); break;
            case 6: searchProduct(); break;
            case 7: sellProduct(); break;
            case 8: showRevenue(); break;
            case 9: printf("Thoat chuong trinh...\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }

    } while (choice != 9);

    return 0;
}

