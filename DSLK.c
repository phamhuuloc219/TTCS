#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

struct nguoi {
    char ten[30];
    int tuoi;
    struct nguoi* tiep;
};

typedef struct nguoi Nguoi;

Nguoi* dau = NULL;
Nguoi* cuoi = NULL;

void them() {
    char ten[30];
    Nguoi* p = (Nguoi*)malloc(sizeof(Nguoi));
    printf("Ten: ");
    gets(ten);
    strcpy(p->ten, ten);
    fflush(stdin);
    printf("Tuoi: ");
    scanf("%d", &p->tuoi);
    fflush(stdin);
    if (dau == NULL) {
        p->tiep = NULL;
        dau = p;
        cuoi = p;
    }
    else {
        p->tiep = NULL;
        cuoi->tiep = p;
        cuoi = p;
    }
}

void xoa() {
    int i;
    Nguoi* p;
    char ten[30];
    printf("Nhap ten nguoi muon xoa: ");
    gets(ten);
    fflush(stdin);
    p = dau;
    for (i = 0;; i++) {
        if (strcmp(dau->ten, ten) == 0) {
            dau = p->tiep;
            break;
        }
        else if (strcmp((p->tiep)->ten, ten) == 0) {
            p->tiep = (p->tiep)->tiep;
            break;
        }
        p = p->tiep;
        if (p->tiep == NULL) break;
    }
}

void sua() {
    int i, tuoi;
    Nguoi* p;
    char ten[30];
    printf("Nhap ten nguoi muon sua: ");
    gets(ten);
    fflush(stdin);
    p = dau;
    for (i = 0;; i++) {
        if (strcmp(p->ten, ten) == 0) {
            printf("Nhap ten can sua : ");
            gets(ten);
            strcpy(p->ten, ten);
            fflush(stdin);
            printf("Nhap tuoi can sua : ");
            scanf("%d", &p->tuoi);
            fflush(stdin);
            break;
        }
        p = p->tiep;
    }
}

void in() {
    int stt = 1;
    Nguoi* p;
    p = dau;
    while (p != NULL) {
        printf("%d. %s - Tuoi: %d\n", stt, p->ten, p->tuoi);
        stt += 1;
        p = p->tiep;
    }
}

void tim() {
    int i, dem, tuoi;
    Nguoi* p;
    char ten[30];
    printf("Nhap ten nguoi muon tim: ");
    gets(ten);
    fflush(stdin);
    printf("Ket qua:\n");
    p = dau;
    dem = 0;
    for (i = 0;; i++) {
        if (strcmp(p->ten, ten) == 0) {
            printf("%s - Tuoi: %d\n", p->ten, p->tuoi);
            dem += 1;
        }
        p = p->tiep;
        if (p == NULL) break;
    }
    if (dem == 0) printf("Khong co nguoi nay \n");
}

void sapxep() {
    int i;
    Nguoi *p1, *p2, *p;
    p1 = dau;
    p2 = p1->tiep;
    while (p1 != NULL) {
        while (p2 != NULL) {
            if (p2->tuoi < p1->tuoi) {
                p = (Nguoi*)malloc(sizeof(Nguoi));
                strcpy(p->ten, p1->ten);
                strcpy(p1->ten, p2->ten);
                strcpy(p2->ten, p->ten);
                free(p);

                p->tuoi = p1->tuoi;
                p1->tuoi = p2->tuoi;
                p2->tuoi = p->tuoi;
            }
            p2 = p2->tiep;
        }
        p1 = p1->tiep;
        if (p1 != NULL) p2 = p1->tiep;
    }
}

int main() {
    int n;
    printf("1.Them\n2.Xoa\n3.Sua\n4.In\n5.Tim\n6.Sap xep tuoi tang dan\n 0.Thoat\n");
    do {
        printf("\nChon 0 -> 6 : ");
        scanf("%d", &n);
        fflush(stdin);
        switch (n) {
        case 1: them(); break;
        case 2: xoa(); break;
        case 3: sua(); break;
        case 4: in(); break;
        case 5: tim(); break;
        case 6: sapxep(); break;
        }
    } while (n);
    return 0;
}

