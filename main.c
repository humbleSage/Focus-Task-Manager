#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 128

struct focus_slip {
    char top_task_1[MAX_LENGTH];
    char top_task_2[MAX_LENGTH];
    char top_task_3[MAX_LENGTH];
    char side_quest_1[MAX_LENGTH];
    char side_quest_2[MAX_LENGTH];
    char side_quest_3[MAX_LENGTH];
    char later[MAX_LENGTH];
};

void show_slip(const struct focus_slip *slip);
void edit_field(char field[], const char *prompt);
int read_choice(void);
void save_slip(const struct focus_slip *slip);
void load_slip(struct focus_slip *slip);


int main(void) {
    printf("****************** TINY TASK MACHINE *******************\n");
    printf("(THE APPARENT CURE FOR ALL OF YOUR PROCRASTINATION WOES)\n");
    printf("********************************************************\n");
    printf("\n\n");
    struct focus_slip focus_slip1;
    strcpy(focus_slip1.top_task_1, "EMPTY");
    strcpy(focus_slip1.top_task_2, "EMPTY");
    strcpy(focus_slip1.top_task_3, "EMPTY");
    strcpy(focus_slip1.side_quest_1, "EMPTY");
    strcpy(focus_slip1.side_quest_2, "EMPTY");
    strcpy(focus_slip1.side_quest_3, "EMPTY");
    strcpy(focus_slip1.later, "EMPTY");

    load_slip(&focus_slip1);

    int choice = 0;

    while(choice != 10) {
        printf("\n1. SHOW SLIP\n");
        printf("2. EDIT PRIORITY 1\n");
        printf("3. EDIT PRIORITY 2\n");
        printf("4. EDIT PRIORITY 3\n");
        printf("5. EDIT SIDE QUEST 1\n");
        printf("6. EDIT SIDE QUEST 2\n");
        printf("7. EDIT SIDE QUEST 3\n");
        printf("8. EDIT LATER TASKS\n");
        printf("9. SAVE SLIP\n");
        printf("10. SAVE AND EXIT\n");
        printf("\n");
        printf("> ");

        choice = read_choice();

        switch(choice) {
            case 1:
                show_slip(&focus_slip1);
                break;
            case 2:
                edit_field(focus_slip1.top_task_1, "ENTER YOUR FIRST PRIORITY: ");
                break;
            case 3:
                edit_field(focus_slip1.top_task_2, "ENTER YOUR SECOND PRIORITY: ");
                break;
            case 4:
                edit_field(focus_slip1.top_task_3, "ENTER YOUR THIRD PRIORITY: ");
                break;
            case 5:
                edit_field(focus_slip1.side_quest_1, "ENTER YOUR FIRST SIDE QUEST: ");
                break;
            case 6:
                edit_field(focus_slip1.side_quest_2,"ENTER YOUR SECOND SIDE QUEST: ");
                break;
            case 7:
                edit_field(focus_slip1.side_quest_3,"ENTER YOUR THIRD SIDE QUEST: ");
                break;
            case 8:
                edit_field(focus_slip1.later,"ENTER LATER TASKS: ");
                break;
            case 9:
                save_slip(&focus_slip1);
                printf("SAVED!\n");
                break;
            case 10:
                save_slip(&focus_slip1);
                printf("SAVED!\n");
                printf("GOODBYE!\n");
                break;
            default:
                printf("PLEASE ENTER A NUMBER FROM 1 TO 10.\n");
                break;
        }
    }

    return 0;
}

void show_slip(const struct focus_slip *slip) {
    printf("PRIORITY 1: %s\n", slip->top_task_1);
    printf("PRIORITY 2: %s\n", slip->top_task_2);
    printf("PRIORITY 3: %s\n", slip->top_task_3);
    printf("SIDE QUEST 1: %s\n", slip->side_quest_1);
    printf("SIDE QUEST 2: %s\n", slip->side_quest_2);
    printf("SIDE QUEST 3: %s\n", slip->side_quest_3);
    printf("LATER: %s\n", slip->later);
}

void edit_field(char field[], const char *prompt) {
    printf ("%s", prompt);
    if (fgets(field, MAX_LENGTH, stdin) != NULL) {
        field[strcspn(field, "\n")] = '\0';
    }
}

int read_choice(void) {
    char input[MAX_LENGTH];
    int choice;

    if (fgets(input, MAX_LENGTH, stdin) == NULL) {
        return -1;
    }

    if (sscanf(input, "%d", &choice) != 1) {
        return -1;
    }

    return choice;
}

void save_slip(const struct focus_slip *slip) {
    FILE *file;
    file = fopen("focus_slip.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    fprintf(file, "%s\n", slip->top_task_1);
    fprintf(file, "%s\n", slip->top_task_2);
    fprintf(file, "%s\n", slip->top_task_3);
    fprintf(file, "%s\n", slip->side_quest_1);
    fprintf(file, "%s\n", slip->side_quest_2);
    fprintf(file, "%s\n", slip->side_quest_3);
    fprintf(file, "%s\n", slip->later);

    fclose(file);
}

void load_slip(struct focus_slip *slip) {
    FILE *file;
    file = fopen("focus_slip.txt", "r");
    if (file == NULL) {
        return;
    }

    if (fgets(slip->top_task_1, MAX_LENGTH, file) != NULL) {
        slip->top_task_1[strcspn(slip->top_task_1, "\n")] = '\0';
    }
    if (fgets(slip->top_task_2, MAX_LENGTH, file) != NULL) {
        slip->top_task_2[strcspn(slip->top_task_2, "\n")] = '\0';
    }
    if (fgets(slip->top_task_3, MAX_LENGTH, file) != NULL) {
        slip->top_task_3[strcspn(slip->top_task_3, "\n")] = '\0';
    }
    if (fgets(slip->side_quest_1, MAX_LENGTH, file) != NULL) {
        slip->side_quest_1[strcspn(slip->side_quest_1, "\n")] = '\0';
    }
    if (fgets(slip->side_quest_2, MAX_LENGTH, file) != NULL) {
        slip->side_quest_2[strcspn(slip->side_quest_2, "\n")] = '\0';
    }
    if (fgets(slip->side_quest_3, MAX_LENGTH, file) != NULL) {
        slip->side_quest_3[strcspn(slip->side_quest_3, "\n")] = '\0';
    }
    if (fgets(slip->later, MAX_LENGTH, file) != NULL) {
        slip->later[strcspn(slip->later, "\n")] = '\0';
    }

    fclose(file);
}