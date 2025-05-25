#include <stdio.h>

#define MAX 1000

int arr[MAX];
int size = 0;

void showMenu() {
    printf("\n===== ARRAY OPERATIONS =====\n");
    printf("1. Insert a value\n");
    printf("2. Delete by position\n");
    printf("3. Update a value\n");
    printf("4. Display array\n");
    printf("5. Search a value\n");
    printf("6. Sort array\n");
    printf("7. Exit\n");
}

void display() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert() {
    if (size >= MAX) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    arr[size] = value;
    size++;
    printf("Value inserted!\n");
}

void delete() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    int pos;
    printf("Enter position to delete (0 to %d): ", size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Deleted successfully.\n");
}

void update() {
    int pos, newUpdate;
    printf("Enter position to update (0 to %d): ", size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &newUpdate);
    arr[pos] = newUpdate;
    printf("Updated successfully.\n");
}

void search() {
    int value, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &value);
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Value found at position %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Value not found in array.\n");
    }
}

void sort() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
}

int main() {
    int initial;

    printf("How many elements do you want to input (max 1000)? ");
    scanf("%d", &initial);

    if (initial > MAX || initial < 0) {
        printf("Invalid size!\n");
        return 0;
    }

    printf("Enter %d elements:\n", initial);
    for (int i = 0; i < initial; i++) {
        scanf("%d", &arr[i]);
    }
    size = initial;
    display();

    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                display();
                break;
            case 2:
                delete();
                display();
                break;
            case 3:
                update();
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                search();
                display();
                break;
            case 6:
                sort();
                display();
                break;
            case 7:
                printf("Excuet program. \n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

