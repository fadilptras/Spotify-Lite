#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

struct Lagu {
    string nama;
    string judul_lagu;
    string artis;
    float durasi;
};

struct Playlist { 
    string nama_playlist;
    Lagu songs[10];
    int jumlah_lagu;
};

Lagu inputData() {
    Lagu data;
    cout << "\nSilahkan Isi Data Berikut :\n";

    cout << "Siapa Namamu : ";
    cin >> data.nama; 

    cout << "Masukan Judul Lagu : ";
    cin >> data.judul_lagu;

    cout << "Siapa penyanyinya tu : ";
    cin >> data.artis;

    cout << "Berapa durasi lagunya : ";
    cin >> data.durasi;

    return data;
}

void tampilData(const Lagu& data, int urutanLagu) {
    cout << urutanLagu << ". " << data.judul_lagu << " - " << data.artis << " (" << data.durasi << " Menit)" << endl;
}

void selectionSort(Lagu lagu[], int n) {
    int minIndex;
    Lagu temp;
    //Loop memilai seluruh element array
    for (int i = 0; i < n - 1; i++) {
        //Cari elemen terbesar dalam array yg belum diurutkan
        minIndex = i; //mengasumsikan bahwa elemen pada posisi i adalah elemen terbesar untuk iterasi saat ini.
        for (int j = i + 1; j < n; j++) {
            if (lagu[j].durasi > lagu[minIndex].durasi) { //Memeriksa apakah durasi elemen pada indeks j lebih besar daripada durasi elemen pada minIndex
                minIndex = j; //menunjukkan bahwa elemen pada indeks j sekarang adalah elemen terbesar
            }
        }
        //Tukar elemen terkeci dengan elemen pertama pada array
        temp = lagu[i];
        lagu[i] = lagu[minIndex];
        lagu[minIndex] = temp;
    }
}

int main() {
    string line;
    ifstream header;
    header.open("a.txt");

    while (getline(header, line)) {
        cout << line << endl;
    } // fungsi ifstream

    queue<string> laguQueue;

    laguQueue.push("1. Kupu-kupu - Tiara Andini (4.02 Menit)");
    laguQueue.push("2. Bermuara - Rizky Febian, Mahalini (4.47 Menit)");
    laguQueue.push("3. Sepenuh Hati - Rony Parulian, Andi Rianto (4.08 Menit)");
    laguQueue.push("4. we can't be friend - Ariana Grande (3.49 Menit)");
    laguQueue.push("5. Rumah - Salma Salsabil (4.19 Menit)");
    laguQueue.push("6. The Way You Look At Me - Nyoman Paul, Andi Rianto (4.10 Menit)");
    laguQueue.push("7. Here, There And Everywhere - The Beatles (2.25 Menit)");
    laguQueue.push("8. AI - Doel Sumbang (3.49 Menit)");
    laguQueue.push("9. Sorai - Nadin Amizah (3.58 Menit)");
    laguQueue.push("10. Terlalu Tinggi - Juicy Luicy (4.39 Menit)");
    
    cout << "\nBerikut Playlist Hits 2024 :" << endl;
    cout << "- Lagu_Viral_Trending -" << endl;

    while (!laguQueue.empty()) {
        cout << laguQueue.front() << endl;
        laguQueue.pop();
    }


    cout << endl;

    cout << "============================================================================" << endl;
    cout << "\nMau Buat Playlist sesukamu ??\n";
    cout << "\nLangkah-langkah :\n";
    cout << "1. Masukkan nama Playlist.\n";
    cout << "2. Masukkan nama kamu, judul lagu favoritmu, nama penyanyinya, dan durasi lagu.\n";
    cout << "3. Mengganti spasi dengan _ (underscore).\n";
    cout << "3. Pastikan kamu mengetik dengan benar.\n";
    cout << "4. Memakai titik (.) pada pengisian durasi lagu.\n";

    cout << "\nContoh :\n";
    cout << "Masukan Nama Playlist : Jumat_Berkah\n";
    cout << "Siapa Namamu : Fadhillah_Putra\n";
    cout << "Masukan Judul Lagu : Sepenuh_Hati\n";
    cout << "Siapa penyanyinya tu : Ucup\n";
    cout << "Berapa durasi lagunya : 2.30 (2 Menit, 30 detik)\n";

    Playlist Playlists[10];
    int jumlahPlaylist = 0;

    while (jumlahPlaylist < 10) {
        cout << "\nMasukkan Nama Playlist: ";
        cin >> Playlists[jumlahPlaylist].nama_playlist;
        Playlists[jumlahPlaylist].jumlah_lagu = 0;

        while (Playlists[jumlahPlaylist].jumlah_lagu < 10) {
            cout << "\nData user ke-" << Playlists[jumlahPlaylist].jumlah_lagu + 1 << endl;
            Playlists[jumlahPlaylist].songs[Playlists[jumlahPlaylist].jumlah_lagu] = inputData();
            Playlists[jumlahPlaylist].jumlah_lagu++;

            cout << "Mau nambah lagu lagi? (y/t): ";
            char pilihan;
            cin >> pilihan;

            if (tolower(pilihan) != 'y') {
                break;
            }
        }

        cout << "Mau nambah playlist lagi ga? (y/t): ";
        char pilihan;
        cin >> pilihan;

        if (tolower(pilihan) != 'y') {
            break;
        }

        jumlahPlaylist++;
    }

    for (int i = 0; i <= jumlahPlaylist; i++) {
        cout << "\n\n- " << Playlists[i].nama_playlist << " -\n";
        selectionSort(Playlists[i].songs, Playlists[i].jumlah_lagu);
        for (int j = 0; j < Playlists[i].jumlah_lagu; j++) {
            tampilData(Playlists[i].songs[j], j + 1);
        }
    }

    return 0;
}
