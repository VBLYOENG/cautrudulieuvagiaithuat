#include <iostream>
using namespace std;

struct SV {
    string hoTen;
    string MSSV;
    int birth;
    double GPA;
};

struct Node {
    SV in4;
    Node* next;
};

struct DS {
    Node* nodeDau;
};

void DS_init(DS* ds) {
    ds -> nodeDau = nullptr;
};

void DS_duyet(DS* ds) {
    Node* a = ds -> nodeDau;
    if (a == nullptr) cout << "DS rong";
    else {
        while (a != nullptr) {
            cout << "Ho&ten:" << a ->in4.hoTen <<endl;
            cout << "MSSV:" << a->in4.MSSV <<endl;
            cout << "NamSinh:" << a->in4.birth <<endl;
            cout << "GPA:" << a->in4.GPA << endl;
            a = a ->next;
        }
        cout << endl;
    } 
};

int DS_doDai(DS* ds) {
    Node* a = ds->nodeDau;
    int dem = 0;
    while (a != nullptr) {
        dem++;
        a=a->next;
    }
    return dem;
};

int DShon32_count (DS* ds, double Moc=3.2) {
    int dem = 0;
    Node* a = ds->nodeDau;
    while (a != nullptr) {
        if (a->in4.GPA > Moc) 
            dem++;
        a = a ->next; 
    }
    return dem;
};

void Doi(SV &a, SV &b) {
    SV tam =a;
    a = b;
    b = tam;
};

void SapXepSV_selectionSort (DS* ds) {
    if (ds ->nodeDau == nullptr) return;
    for ( Node* i = ds ->nodeDau; i ->next != nullptr; i = i->next) {
        Node* min = i;
        for (Node* j = i ->next; j != nullptr; j = j ->next ) {
            if (j ->in4.GPA < min->in4.GPA) min = j;
        }
        if (min != i) {
            Doi(i ->in4, min -> in4);
        }
    }
};  

void ChenSVtheoGPA (DS* ds, SV svnew) {
    Node* nodenew = new Node;
    nodenew ->in4 = svnew;
    nodenew ->next = nullptr;
    Node* a = ds->nodeDau;
    if (a == nullptr || a ->in4.GPA >= svnew.GPA) {
        nodenew ->next =a;
        ds ->nodeDau = nodenew;
        return;
    }
    while (a ->next != nullptr && a ->next ->in4.GPA <= svnew.GPA) {
        a = a ->next;
    }
    nodenew ->next = a ->next;
    a ->next = nodenew;
}
int main () {
    DS ds;
    DS_init(&ds);
    ds.nodeDau = 0;
    Node* sv1 = new Node{{"Vuong Ba Nhat", "20241", 2001, 3.5}, nullptr};
    Node* sv2 = new Node{{"Vuong Ba Nhi", "20242", 2002, 3.1}, nullptr};
    Node* sv3 = new Node{{"Vuong Ba Tam", "20243", 2003, 2.9}, nullptr};
    Node* sv4 = new Node{{"Vuong Ba Tu", "20244", 2004, 1.8}, nullptr};
    ds.nodeDau = sv1;
    sv1->next = sv2;
    sv2->next = sv3;
    sv3->next = sv4;
    cout << "DS ban dau" << endl;
    DS_duyet(&ds);

    cout << "Do dai danh sach: " << DS_doDai(&ds) << endl;

    cout << "So sinh vien loai gioi: " << DShon32_count(&ds, 3.2) << endl;

    SapXepSV_selectionSort(&ds);
    cout << "DS sau khi sap xep" << endl;
    DS_duyet(&ds);

    SV svMoi = {"Vuong Ba Long","20249",2006,2.4} ;
    ChenSVtheoGPA(&ds, svMoi);
    cout << "DS sau khi bo sung va sap xep" << endl;
    DS_duyet(&ds);
}