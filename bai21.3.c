#include <stdio.h>
#include <string.h>

struct Address {
    char street[100];
    char city[50];
    int zip;
};

struct Person {
    char name[50];
    int age;
    struct Address address;
};

int main() {
    struct Person person1;
    printf("Nhap ten: ");
    fgets(person1.name, sizeof(person1.name), stdin);
    person1.name[strcspn(person1.name, "\n")] = '\0';  
    printf("Nhap tuoi: ");
    scanf("%d", &person1.age);
    getchar(); 
    printf("Nhap ten duong: ");
    fgets(person1.address.street, sizeof(person1.address.street), stdin);
    person1.address.street[strcspn(person1.address.street, "\n")] = '\0';
	getchar(); 
    printf("Nhap ten thanh pho: ");
    fgets(person1.address.city, sizeof(person1.address.city), stdin);
    person1.address.city[strcspn(person1.address.city, "\n")] = '\0';
	getchar(); 
    printf("Nhap ma buu dien: ");
    scanf("%d", &person1.address.zip);
    printf("Ten: %s\n", person1.name);
    printf("Tuoi: %d\n", person1.age);
    printf("Dia chi:\n");
    printf("  Duong: %s\n", person1.address.street);
    printf("  Thanh pho: %s\n", person1.address.city);
    printf("  Ma buu dien: %d\n", person1.address.zip);

}

