#include <stdio.h>
#include<conio.h>
#include <string.h>
#define MAX_FRIENDS 50
#define MAX_NAME_LENGTH 50
struct Friend {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
};
struct Friend friends[MAX_FRIENDS];
int num_friends = 0;

void addFriend(char name[], int day, int month) {
    if (num_friends < MAX_FRIENDS) {
        strcpy(friends[num_friends].name, name);
       
friends[num_friends].day = day;
        friends[num_friends].month = month;
        num_friends++;
    } else {
        printf("Maximum number of friends reached.\n");
    }
}

void displayFriends() {
    printf("Birthday list:\n");
    for (int i = 0; i < num_friends; i++) {
        printf("%s: %d/%d\n", friends[i].name, friends[i].month, friends[i].day);
    }
}

void searchFriend(char name[]) {
    int found = 0;
    for (int i = 0; i < num_friends; i++) {
        if (strcmp(friends[i].name, name) == 0) {
            printf("%s's birthday is on %d/%d\n", friends[i].name, friends[i].month, friends[i].day);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Friend not found.\n");
    }
}

void displayMonthlyBirthdays(int month) {
    printf("Birthdays in month %d:\n", month);
    for (int i = 0; i < num_friends; i++) {
        if (friends[i].month == month) {
            printf("%s: %d/%d\n", friends[i].name, friends[i].month, friends[i].day);
        }
    }
}

int main() {
    addFriend("Riya", 28, 4);
    addFriend("Raj", 23, 5);
    addFriend("Gunjan", 15, 9);
    addFriend("Yash", 7, 1);
    addFriend("Gauri", 12, 12);

    displayFriends();

    searchFriend("Gunjan");

    displayMonthlyBirthdays(5);

    return 0;
};
