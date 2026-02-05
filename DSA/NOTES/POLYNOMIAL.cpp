#include <stdio.h>
#include <stdlib.h>

/* structure */
struct node {
    int coeff;
    int power;
    struct node *next;
};

/* create new node */
struct node* createNode(int c, int p) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->coeff = c;
    temp->power = p;
    temp->next = NULL;
    return temp;
}

/* insert term in sorted order */
struct node* insert(struct node *head, int c, int p) {
    struct node *temp = createNode(c, p);

    if (head == NULL || head->power < p) {
        temp->next = head;
        return temp;
    }

    struct node *cur = head;
    while (cur->next != NULL && cur->next->power > p)
        cur = cur->next;

    if (cur->next != NULL && cur->next->power == p) {
        cur->next->coeff += c;
        free(temp);
    } else {
        temp->next = cur->next;
        cur->next = temp;
    }

    return head;
}

/* create polynomial */
struct node* createPoly() {
    struct node *head = NULL;
    int n, c, p;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &c, &p);
        head = insert(head, c, p);
    }
    return head;
}

/* display polynomial */
void display(struct node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->power);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

/* addition */
struct node* add(struct node *p1, struct node *p2) {
    struct node *res = NULL;

    while (p1 && p2) {
        if (p1->power > p2->power) {
            res = insert(res, p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p2->power > p1->power) {
            res = insert(res, p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            res = insert(res, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) {
        res = insert(res, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2) {
        res = insert(res, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return res;
}

/* subtraction */
struct node* subtract(struct node *p1, struct node *p2) {
    struct node *res = NULL;

    while (p2) {
        res = insert(res, -p2->coeff, p2->power);
        p2 = p2->next;
    }

    while (p1) {
        res = insert(res, p1->coeff, p1->power);
        p1 = p1->next;
    }

    return res;
}

/* multiplication */
struct node* multiply(struct node *p1, struct node *p2) {
    struct node *res = NULL;

    for (struct node *i = p1; i != NULL; i = i->next) {
        for (struct node *j = p2; j != NULL; j = j->next) {
            res = insert(res,
                         i->coeff * j->coeff,
                         i->power + j->power);
        }
    }
    return res;
}

int main() {

    struct node *p1 = NULL, *p2 = NULL, *result = NULL;
    int choice;

    printf("===== POLYNOMIAL USING LINKED LIST =====\n");

    while (1) {
        printf("\n1. Create Polynomial 1");
        printf("\n2. Create Polynomial 2");
        printf("\n3. Display Polynomials");
        printf("\n4. Addition");
        printf("\n5. Subtraction (P1 - P2)");
        printf("\n6. Multiplication");
        printf("\n7. Exit");
        printf("\nEnter choice: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                p1 = createPoly();
                break;

            case 2:
                p2 = createPoly();
                break;

            case 3:
                printf("Polynomial 1: ");
                display(p1);
                printf("Polynomial 2: ");
                display(p2);
                break;

            case 4:
                result = add(p1, p2);
                printf("Addition Result: ");
                display(result);
                break;

            case 5:
                result = subtract(p1, p2);
                printf("Subtraction Result: ");
                display(result);
                break;

            case 6:
                result = multiply(p1, p2);
                printf("Multiplication Result: ");
                display(result);
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
