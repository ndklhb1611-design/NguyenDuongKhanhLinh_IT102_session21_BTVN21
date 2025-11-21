#include <stdio.h>
#include <string.h>
#define MAX 100

struct Product {
    int id;             
    char name[50];      
    float importPrice;  
    float sellPrice;    
    int quantity;       
};

void inputProducts(struct Product arr[], int *n) {
    printf("Nhap so luong san pham: ");
    scanf("%d", n);
    getchar();

    for (int i = 0; i < *n; i++) {
        printf("San pham %d \n", i + 1);
        printf("Ma san pham: ");
        scanf("%d", &arr[i].id);
        getchar();
        printf("Ten san pham: ");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';
        printf("Gia nhap: ");
        scanf("%f", &arr[i].importPrice);
        printf("Gia ban: ");
        scanf("%f", &arr[i].sellPrice);
        printf("So luong: ");
        scanf("%d", &arr[i].quantity);
    }
}

int findProductById(struct Product arr[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (arr[i].id == id) return i;
    }
    return -1;
}

void importMore(struct Product arr[], int *n, float *revenue) {
    int id;
    printf("Nhap ma san pham muon nhap: ");
    scanf("%d", &id);

    int pos = findProductById(arr, *n, id);

    if (pos == -1) {
        printf("San pham moi, tien hanh them vao danh sach.\n");
        pos = *n;
        (*n)++;

        arr[pos].id = id;
        getchar();

        printf("Nhap ten: ");
        fgets(arr[pos].name, sizeof(arr[pos].name), stdin);
        arr[pos].name[strcspn(arr[pos].name, "\n")] = '\0';

        printf("Gia nhap: ");
        scanf("%f", &arr[pos].importPrice);

        printf("Gia ban: ");
        scanf("%f", &arr[pos].sellPrice);

        arr[pos].quantity = 0;
    }

    int quantity;
    printf("Nhap so luong muon nhap: ");
    scanf("%d", &quantity);

    arr[pos].quantity += quantity;
    *revenue -= quantity * arr[pos].importPrice;
}

void updateProduct(struct Product arr[], int n) {
    int id;
    printf("Nhap ma san pham muon cap nhat: ");
    scanf("%d", &id);

    int pos = findProductById(arr, n, id);

    if (pos == -1) {
        printf("Khong tim thay san pham.\n");
        return;
    }

    getchar();
    printf("Nhap ten moi: ");
    fgets(arr[pos].name, sizeof(arr[pos].name), stdin);
    arr[pos].name[strcspn(arr[pos].name, "\n")] = '\0';

    printf("Nhap gia nhap moi: ");
    scanf("%f", &arr[pos].importPrice);

    printf("Nhap gia ban moi: ");
    scanf("%f", &arr[pos].sellPrice);

    printf("Nhap so luong moi: ");
    scanf("%d", &arr[pos].quantity);

    printf("Cap nhat thanh cong!\n");
}

void sortProducts(struct Product arr[], int n) {
    int choice;
    printf("\n1. Sap xep tang theo gia ban\n");
    printf("2. Sap xep giam theo gia ban\n");
    printf("Chon: ");
    scanf("%d", &choice);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int condition = (choice == 1 && arr[i].sellPrice > arr[j].sellPrice) ||
                            (choice == 2 && arr[i].sellPrice < arr[j].sellPrice);

            if (condition) {
                struct Product temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void searchProduct(struct Product arr[], int n) {
    char name[50];
    getchar();
    printf("Nhap ten san pham muon tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            printf("Tim thay:\n");
            printf("ID: %d\n", arr[i].id);
            printf("Gia ban: %.2f\n", arr[i].sellPrice);
            printf("So luong: %d\n", arr[i].quantity);
            return;
        }
    }
    printf("Khong tim thay san pham.\n");
}

void sellProduct(struct Product arr[], int n, float *revenue) {
    int id, quantity;
    printf("Nhap ma san pham: ");
    scanf("%d", &id);
    int pos = findProductById(arr, n, id);
    if (pos == -1) {
        printf("Khong tim thay san pham.\n");
        return;
    }

    if (arr[pos].quantity == 0) {
        printf("Het hang!\n");
        return;
    }

    printf("Nhap so luong ban: ");
    scanf("%d", &quantity);
    if (quantity > arr[pos].quantity) {
        printf("Khong du hang!\n");
        return;
    }

    arr[pos].quantity -= quantity;
    *revenue += quantity * arr[pos].sellPrice;
    printf("Ban thanh cong!\n");
}

int main() {
    struct Product products[MAX];
    int n = 0;
    float revenue = 0;
    int choice;

    while (1) {
        printf("1. Nhap danh sach san pham\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Nhap them san pham\n");
        printf("4. Cap nhat san pham\n");
        printf("5. Sap xep theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Xem doanh thu\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: inputProducts(products, &n); break;
            case 2: displayProducts(products,&n);break;
            case 3: importMore(products, &n, &revenue); break;
            case 4: updateProduct(products, n); break;
            case 5: sortProducts(products, n); break;
            case 6: searchProduct(products, n); break;
            case 7: sellProduct(products, n, &revenue); break;
            case 8: printf("Doanh thu hien tai: %.2f\n", revenue); break;
            case 9: return 0;
            default: printf("Lua chon khong hop le!\n");
        }
    }
}

