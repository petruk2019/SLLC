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
void hapusygdepan(){
	node *temp1,*temp2;
	if(head==NULL)
		cout<<"List kosong !"<<endl;
	else {
	temp1=head;
		if(temp1->next==NULL){
			delete temp1;
	head=NULL;
		}
		else {
		while(temp1->next!=NULL){
		temp2 = temp1;
		temp1=temp1->next;
	}
		delete temp1;
		temp2->next=NULL;
		}
	}
	
	}
void hapusygbelakang(){
	node *temp;
	temp = head;
	head=head->next;
	delete temp;	
	}
void tampilkandata(){
	node *temp;	
	temp = head;
	cout<<endl;
	cout<<"Data [";	
	if (temp == NULL)
		cout<<"List kosong"<<endl;
		else {	
			while (temp!=NULL){
			cout<<" "<<temp->data<<",";
			if (temp == posisi)
		cout<<" <<PosisiNode";
		temp=temp->next;
			}
		cout<<" ]";
		}
}
void hapusygtengah(){
int banyakdata,posisi_hapus,poshapus;
node *hapus, *bantu;
if(head != NULL){
	cout<<" Akan dihapus pada data ke : ";
	cin>>posisi_hapus;
	banyakdata=1;
	bantu=head;
	while(bantu->next != NULL){
		bantu=bantu->next;
		banyakdata++;
	}
	if((posisi_hapus<1)||(posisi_hapus>banyakdata)){
	cout<<"Belum ada data !! masukkan Data Dahulu ! \n";}		
	else{
		bantu=head;
		poshapus=1;
		while(poshapus<(posisi_hapus-1)){
			bantu=bantu->next;
			poshapus++;
		}
	hapus=bantu->next;
	bantu->next=hapus->next;
	delete hapus;
	}		
}
else {cout<<"Data Masih kosong ! ";}
}
int main(){
	head=NULL;
	struc(61);
	struc(52);
	struc(43);
	struc(34);
	struc(25);
	struc(16);		
option:
	tampilkandata();
	cout<<endl;
	cout<<"Program Node"<<endl;
	cout<<"Menu : "<<endl;
	cout<<"1. Tambah Node Depan"<<endl;
	cout<<"2. Tambah Node Belakang"<<endl;
	cout<<"3. Hapus Node Depan"<<endl;
	cout<<"4. Hapus Node Belakang"<<endl;
	cout<<"5. Tambah Node Tertentu"<<endl;
	cout<<"6. Hapus Node Tertentu"<<endl;
	cout<<"Masukkan pilihan : ";
	cin>>opsi;
	switch(opsi){
		case 1 : tambahkedepan();
			break;
		case 2 : tambahkebelakang();
			break;
		case 3 : hapusygdepan();
			break;
		case 4 : hapusygbelakang();
			break;
		case 5 : tambahketengah();
			break;
		case 6 : hapusygtengah();
			break;
		default : cout<<"Pilihan salah !"<<endl;
	}
	tampilkandata();
	cout<<endl;
	goto option;
	return 0;
}
