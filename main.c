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
void edit_top_task(struct focus_slip *slip);


int main(void) {
    struct focus_slip focus_slip1;
    strcpy(focus_slip1.top_task, "Undefined");
    strcpy(focus_slip1.quick_win_1, "Undefined");
    strcpy(focus_slip1.quick_win_2, "Undefined");
    strcpy(focus_slip1.later, "Undefined");

    show_slip(focus_slip1);
    edit_top_task(&focus_slip1);
    show_slip(focus_slip1);

    return 0;
}

void show_slip(struct focus_slip slip) {
    printf("Top Task: %s\n", slip.top_task);
    printf("Quick Win 1: %s\n", slip.quick_win_1);
    printf("Quick Win 2: %s\n", slip.quick_win_2);
    printf("Later: %s\n", slip.later);
}

void edit_top_task(struct focus_slip *slip) {
    printf ("Enter top task: ");
    if (fgets(slip->top_task, MAX_LENGTH, stdin) != NULL) {
        slip->top_task[strcspn(slip->top_task, "\n")] = '\0';
    }
}