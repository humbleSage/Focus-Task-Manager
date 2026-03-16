#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 128

struct focus_slip {
    char top_task[MAX_LENGTH];
    char quick_win_1[MAX_LENGTH];
    char quick_win_2[MAX_LENGTH];
    char later[MAX_LENGTH];
};

void show_slip(struct focus_slip slip);
void edit_field(char field[], const char *prompt);


int main(void) {
    struct focus_slip focus_slip1;
    strcpy(focus_slip1.top_task, "Undefined");
    strcpy(focus_slip1.quick_win_1, "Undefined");
    strcpy(focus_slip1.quick_win_2, "Undefined");
    strcpy(focus_slip1.later, "Undefined");

    int choice = 0;

    while(choice != 6) {
        printf("\n1. Show slip\n");
        printf("2. Edit top task.\n");
        printf("3. Edit quick win 1.\n");
        printf("4. Edit quick win 2.\n");
        printf("5. Edit later.\n");
        printf("6. Exit.\n");

        printf("Choose: ");

        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                show_slip(focus_slip1);
                break;
            case 2:
                edit_field(focus_slip1.top_task, "Enter your top task: ");
                break;
            case 3:
                edit_field(focus_slip1.quick_win_1, "Enter your quick win 1: ");
                break;
            case 4:
                edit_field(focus_slip1.quick_win_2, "Enter your quick win 2: ");
                break;
            case 5:
                edit_field(focus_slip1.later, "Enter your later task: ");
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

void show_slip(struct focus_slip slip) {
    printf("Top Task: %s\n", slip.top_task);
    printf("Quick Win 1: %s\n", slip.quick_win_1);
    printf("Quick Win 2: %s\n", slip.quick_win_2);
    printf("Later: %s\n", slip.later);
}

void edit_field(char field[], const char *prompt) {
    printf ("%s", prompt);
    if (fgets(field, MAX_LENGTH, stdin) != NULL) {
        field[strcspn(field, "\n")] = '\0';
    }
}