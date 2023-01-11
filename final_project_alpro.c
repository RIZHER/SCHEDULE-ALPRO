#include<stdio.h>
#include <string.h>
#include<stdlib.h>



//membuet bagian menambah event
struct Event{
    char nama[100];
    char tahun[100];
    char bulan[100];
    char tanggal[100];
    char hari[100];
    char jam[100];
    char prioritas[100];
    int selesai;
};

//membuat vungsi void atau vungsi tanpa kembaian untuk menampilkan menu
void menu(){
    printf("Program jadwal\n");
    printf("==============\n");
    printf("1. Tambah event\n");
    printf("2. Edit event\n");
    printf("3. Liat event\n");
    printf("4. Tandai event\n");
    printf("5. Exit\n");
}


int main(){


// bagian deklarasi variable
int pil;
int j=0;
char user[8], pas[8];
int ulang = 0;


//membuat username dan password
login:

for(int i=0; i<3; i++){
    printf("\n\n");
    printf("------- Program Aplikasi pengelola jadwal Sederhana --------");
    printf(" \n\n                      Silahkan login\n");
    printf("\n Masukkan username anda : ");
    scanf("%s", &user);

    printf("\n Masukkan password anda : ");
    scanf("%s", &pas);

    if ((strcmp(user,"rizki")==0)&&(strcmp(pas,"kenny")==0)) {
        break;
      } else if((strcmp(user,"rizki")==0)&&(strcmp(pas,"kenny")!=0)){
        printf("\n               Maaf password anda salah\n");
        system("pause");
		system("cls");
        ulang = ulang + 1;
        } else if((strcmp(user,"rizki")!=0)&&(strcmp(pas,"kenny")==0)){
        printf("\n               Maaf username anda salah\n");
        system("pause");
		system("cls");
        ulang = ulang + 1;
        }else {
        printf("\n               Maaf password dan username anda salah\n");
        system("pause");
		system("cls");
        ulang = ulang + 1;
        }
    }
    if(ulang<3){
        printf("\n                      Anda telah berhasil login.\n");
        system("pause");
		system("cls");
		goto mulaimenu;

    } else {
        printf("\n\nSudah melebihi batas login, tidak bisa login lagi\n");
        system("pause");
		system("cls");
		return 0;
    }


// bagian menu aplikasi
mulaimenu:

//deklarasi fungsi void
menu();

// deklarasi vungsi struct
struct Event Event_baru[100];
 
// user menginput pilihan menu
printf("Masukan menu pilihan: ");
scanf("%d",&pil);


//program untuk menambah jadwal
tambahjadwal:
getchar();
system("cls");
if(pil==1){
    printf("1. Menu Tambah event\n");
    printf("====================\n\n");

        Event_baru[j].selesai = 0;
        printf("Nama Event: ");
        gets(Event_baru[j].nama);
        printf("Tahun: ");
        gets(Event_baru[j].tahun);
        printf("Bulan: ");
        gets(Event_baru[j].bulan);
        printf("Tanggal: ");
        gets(Event_baru[j].tanggal);
        printf("Hari: ");
        gets(Event_baru[j].hari);
        printf("Jam: ");
        gets(Event_baru[j].jam);
        printf("Prioritas: ");
        gets(Event_baru[j].prioritas);

        j=j+1;
        printf("\n\nData Berhasil Disimpan \n");

    char ulang;
    printf("Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :");
    scanf("%c",&ulang);

    if(ulang=='y'||ulang=='Y'){
				goto tambahjadwal;
			}else{
				printf("\n\n Data Berhasil Disimpan \n");
				system("pause");
				system("cls");
				goto mulaimenu;
			}
    }


//program untuk mengganti jadwal
ubahevent:
if(pil==2){
    
    int ubah;
    for(int i=0; i < j; i++){
        if (Event_baru[i].selesai == 0){
            printf("Data even ke %d\n",i+1);
            printf("===================\n");
            printf("Nama even adalah : %s\n",Event_baru[i].nama);
            printf("Tahun even adalah : %s\n",Event_baru[i].tahun);
            printf("Bulan even adalah : %s\n",Event_baru[i].bulan);
            printf("Tanggal even adalah : %s\n",Event_baru[i].tanggal);
            printf("Hari even adalah : %s\n",Event_baru[i].hari);
            printf("Jam even adalah : %s\n",Event_baru[i].jam);
            printf("Prioritas even adalah : %s\n ",Event_baru[i].prioritas);
            printf("\n");
          }
        }
        printf("pilih data even nomor berapa yang ingin di ubah : ");
        scanf("%d",&ubah);
         if(ubah<=j){
            printf("\ndata event yang diubah adalah yang ke %d\n",ubah);
            getchar();
            printf("Nama Event: ");
            gets(Event_baru[ubah-1].nama);
            printf("Tahun: ");
            gets(Event_baru[ubah-1].tahun);
            printf("Bulan: ");
            gets(Event_baru[ubah-1].bulan);
            printf("tanggal: ");
            gets(Event_baru[ubah-1].tanggal);
            printf("Hari: ");
            gets(Event_baru[ubah-1].hari);
            printf("Jam: ");
            gets(Event_baru[ubah-1].jam);
            printf("Prioritas: ");
            gets(Event_baru[ubah-1].prioritas);
        }else{
            printf("\nMasukan nomor data event yang sesuai!!!\n");
            printf("Tekan apapun untuk mengulang\n");
            system("pause");
			system("cls");
			goto ubahevent;
        }
        char ulang;
        printf("Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :");
        scanf("%c",&ulang);

        if(ulang=='y'||ulang=='Y'){
                getchar();
                system("cls");
				goto ubahevent;
			}else{
				printf("\n\n Data Berhasil Disimpan \n");
				system("pause");
				system("cls");
				goto mulaimenu;
			}
    
}



//program untuk melihat even yang sudah dibuat
lihatevent:
if(pil==3){
    int pilihan;
    printf("Pilih event yang mau dilihat: \n");
    printf("1. Sudah selesai\n");
    printf("2. Belum selesai\n");
    printf("pilihan : ");
    scanf("%d", &pilihan);
    system("cls");
    switch(pilihan)
    {
    case 1:
        printf("Event yang sudah selesai\n");
        for(int i=0; i < j; i++){
                if (Event_baru[i].selesai == 1)
                {
                    printf("Data even ke %d\n",i+1);
                    printf("=====================\n");
                    printf("Nama even adalah : %s\n",Event_baru[i].nama);
                    printf("Tahun even adalah : %s\n",Event_baru[i].tahun);
                    printf("Bulan even adalah : %s\n",Event_baru[i].bulan);
                    printf("Tanggal even adalah : %s\n",Event_baru[i].tanggal);
                    printf("Hari even adalah : %s\n",Event_baru[i].hari);
                    printf("Jam even adalah : %s\n",Event_baru[i].jam);
                    printf("Prioritas even adalah : %s\n ",Event_baru[i].prioritas);
                    printf("\n");
                }
            }
            break;
    case 2:
        printf("Event yang belum selesai\n");
        for(int i=0; i < j; i++){
                if (Event_baru[i].selesai == 0)
                {
                    printf("Data even ke %d\n",i+1);
                    printf("=====================\n");
                    printf("Nama even adalah : %s\n",Event_baru[i].nama);
                    printf("Tahun even adalah : %s\n",Event_baru[i].tahun);
                    printf("Bulan even adalah : %s\n",Event_baru[i].bulan);
                    printf("Tanggal even adalah : %s\n",Event_baru[i].tanggal);
                    printf("Hari even adalah : %s\n",Event_baru[i].hari);
                    printf("Jam even adalah : %s\n",Event_baru[i].jam);
                    printf("Prioritas even adalah : %s\n ",Event_baru[i].prioritas);
                    printf("\n");
                }
            }
            break;
    default:
        printf("Masukkan angka yang benar!\n");
        printf("Tekan tombol apapun untuk mengulang\n");
        system("pause");
        system("cls");
        goto lihatevent;
    }



        printf("\ntekan apapun untuk kembali ke menu !\n");
        system("pause");
		system("cls");
		goto mulaimenu;
    }

tandaselesai:
if (pil == 4)
{
    int ubah;
    for(int i=0; i < j; i++){
            printf("Data even ke %d\n",i+1);
            printf("===================\n");
            printf("Nama even adalah : %s\n",Event_baru[i].nama);
            printf("Tahun even adalah : %s\n",Event_baru[i].tahun);
            printf("Bulan even adalah : %s\n",Event_baru[i].bulan);
            printf("Tanggal even adalah : %s\n",Event_baru[i].tanggal);
            printf("Hari even adalah : %s\n",Event_baru[i].hari);
            printf("Jam even adalah : %s\n",Event_baru[i].jam);
            printf("Prioritas even adalah : %s\n ",Event_baru[i].prioritas);
            printf("\n");
        }
        printf("pilih data even nomor berapa yang ingin ditandai selesai : ");
        scanf("%d", &ubah);
        getchar();

        if(ubah<=j){
            Event_baru[ubah-1].selesai = 1;
        }
        else{
            printf("\nMasukan nomor data event yang sesuai!!!\n");
            printf("Tekan apapun untuk mengulang\n");
            system("pause");
			system("cls");
			goto tandaselesai;
        }

        char ulang;
        printf("Apakah ada event lain yang anda mau tandai selesai? (y/n) : ");
        scanf("%c",&ulang);

        if(ulang=='y'||ulang=='Y'){
                getchar();
                system("cls");
				goto tandaselesai;
			}else{
				printf("\n\n Data Berhasil Disimpan \n");
				system("pause");
				system("cls");
				goto mulaimenu;
			}
}

//untuk mengakhiri program atau logout
if (pil==5){
    goto login;
    }


//progrma untuk meminta user menginputkan pilihan menu yang tidak sesuai
else{
    goto mulaimenu;
    }
}
