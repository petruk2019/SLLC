#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head = NULL;
node *posisi;
int opsi = 0;
int struc(int databaru){
	node *baru;
	baru = new node;
	baru->data = databaru;
	baru->next = NULL;
	if (head == NULL){
		head = baru;
		head->next = NULL;
	}
	else{
		baru->next = head;
		head = baru;
	}
	return 0;
}

void tambahkedepan(){
	node *baru;
	baru = new node;
	cout<<"Masukkan data : ";
	cin>>baru->data;
	baru->next=NULL;
	if (head==NULL){
		head = baru;
	head->next = NULL;
}
	else {
		baru->next = head;
		head = baru;
	}
}
void tambahketengah(){
node *baru, *bantu;
int posisi_sisip;
	if(head != NULL){
	cout<<"Akan ditambahkan setelah Data Ke ? ";
	cin>>posisi_sisip;
	baru =new node;
	bantu=head;   
		for(int i=1;i<posisi_sisip-1;i++) {
			if(bantu->next != NULL)
				bantu=bantu->next;
			else {
				break; 
			}
			}
			cout << "Tambahkan data : ";
			cin >> baru->data;
			baru->next=bantu->next;
			bantu->next=baru;
	}
	else{
		cout<<"Belum terisi data !! silahkan isi datanya";
	}
} 
void tambahkebelakang(){
	node *temp, *temp2;
        temp = new node;
	cout<<"Masukkan data";
	cin>>temp->data;
	temp->next=NULL;
	if (head==NULL){
		head = temp;
		posisi = head;
	}
	else{
		temp2=head;
		while(temp2->next!=NULL){
			temp2=temp2->next;
		}
		temp2->next = temp;
	}
}
