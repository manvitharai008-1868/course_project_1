#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNI 200
#define MAX_LEN 50

typedef struct
{
    int id;
    char name[MAX_LEN];
    char department[MAX_LEN];
    int gradYear;
    char email[MAX_LEN];
    char phone[MAX_LEN];
} Alumni;

Alumni alumniList[MAX_ALUMNI];
int alumniCount = 0;

void addAlumni();
void displayAlumni();
void searchAlumni();
void removeAlumni();
void saveToFile();
void loadFromFile();

int main()
{
    int choice;

    loadFromFile();

    while (1)
    {
        printf("\n==== University Alumni Management System ====\n");
        printf("1. Add Alumni\n");
        printf("2. View All Alumni\n");
        printf("3. Search Alumni by ID\n");
        printf("4. Remove Alumni\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAlumni();
            break;
        case 2:
            displayAlumni();
            break;
        case 3:
            searchAlumni();
            break;
        case 4:
            removeAlumni();
            break;
        case 5:
            saveToFile();
            printf("Saved. Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice, try again!\n");
        }
    }
}

void addAlumni()
{
    if (alumniCount >= MAX_ALUMNI)
    {
        printf("Alumni list is full!\n");
        return;
    }

    Alumni a;

    printf("\nEnter Alumni ID: ");
    scanf("%d", &a.id);
    getchar();

    printf("Enter Name: ");
    fgets(a.name, MAX_LEN, stdin);
    a.name[strcspn(a.name, "\n")] = 0;

    printf("Enter Department: ");
    fgets(a.department, MAX_LEN, stdin);
    a.department[strcspn(a.department, "\n")] = 0;

    printf("Enter Graduation Year: ");
    scanf("%d", &a.gradYear);
    getchar();

    printf("Enter Email: ");
    fgets(a.email, MAX_LEN, stdin);
    a.email[strcspn(a.email, "\n")] = 0;

    printf("Enter Phone: ");
    fgets(a.phone, MAX_LEN, stdin);
    a.phone[strcspn(a.phone, "\n")] = 0;

    alumniList[alumniCount++] = a;

    printf("Alumni added successfully!\n");
}

void displayAlumni()
{
    if (alumniCount == 0)
    {
        printf("No alumni to display.\n");
        return;
    }

    printf("\n---- Alumni List ----\n");
    for (int i = 0; i < alumniCount; i++)
    {
        printf("ID: %d\n", alumniList[i].id);
        printf("Name: %s\n", alumniList[i].name);
        printf("Department: %s\n", alumniList[i].department);
        printf("Graduation Year: %d\n", alumniList[i].gradYear);
        printf("Email: %s\n", alumniList[i].email);
        printf("Phone: %s\n", alumniList[i].phone);
        printf("------------------------\n");
    }
}

void searchAlumni()
{
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < alumniCount; i++)
    {
        if (alumniList[i].id == id)
        {
            printf("\n--- Alumni Found ---\n");
            printf("ID: %d\n", alumniList[i].id);
            printf("Name: %s\n", alumniList[i].name);
            printf("Department: %s\n", alumniList[i].department);
            printf("Graduation Year: %d\n", alumniList[i].gradYear);
            printf("Email: %s\n", alumniList[i].email);
            printf("Phone: %s\n", alumniList[i].phone);
            return;
        }
    }

    printf("No alumni found with ID %d\n", id);
}

void removeAlumni()
{
    int id, index = -1;
    printf("Enter ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < alumniCount; i++)
    {
        if (alumniList[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("No alumni found with ID %d\n", id);
        return;
    }

    for (int i = index; i < alumniCount - 1; i++)
    {
        alumniList[i] = alumniList[i + 1];
    }

    alumniCount--;
    printf("Alumni with ID %d removed successfully.\n", id);
}

void saveToFile()
{
    FILE *fp = fopen("alumni_data.txt", "wb");

    if (!fp)
    {
        printf("Error saving file!\n");
        return;
    }

    fwrite(&alumniCount, sizeof(int), 1, fp);
    fwrite(alumniList, sizeof(Alumni), alumniCount, fp);

    fclose(fp);
}
void loadFromFile()
{
    FILE *fp = fopen("alumni_data.txt", "rb");

    if (!fp)
        return;

    fread(&alumniCount, sizeof(int), 1, fp);
    fread(alumniList, sizeof(Alumni), alumniCount, fp);

    fclose(fp);
}