#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
    struct Book books[5];
    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin sach thu %d:\n", i + 1);
        getchar(); 
        printf("Nhap ten sach: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';
        printf("Nhap ten tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';
        printf("Nhap gia sach: ");
        scanf("%f", &books[i].price);
        printf("\n");
    }
    
    for (int i = 0; i < 5; i++) {
        printf("Sach %d:\n", i + 1);
        printf("Ten sach : %s\n", books[i].title);
        printf("Tac gia  : %s\n", books[i].author);
        printf("Gia      : %.2f\n", books[i].price);
    }

    return 0;
}
