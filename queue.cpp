#include<iostream>
using namespace std;

#define max_antrian 3  // Ukuran maksimal antrian

string antrian[max_antrian];  // Array biasa untuk menyimpan nama nasabah
int top = 0;  // Indeks untuk antrian

// Fungsi untuk mengecek apakah antrian penuh
bool penuh() {
    return top >= max_antrian;  // Jika jumlah antrian sudah mencapai max_antrian
}

// Fungsi untuk mengecek apakah antrian kosong
bool kosong() {
    return top == 0;  // Jika antrian kosong (top == 0)
}

// Menampilkan menu
void menu() {
    cout << "============================\n";
    cout << "        queue               \n";
    cout << "============================\n";
    cout << "1. Enqueue (Tambah Antrian)\n";
    cout << "2. Dequeue (Layani Pelanggan)\n";
    cout << "3. View (Tampilkan Antrian)\n";
    cout << "4. Keluar\n";
    cout << "============================\n";
}

// Fungsi untuk menambah antrian
void enqueue() {
    if (penuh()) {
        cout << "Antrian sudah penuh. Silakan menunggu kasir selesai melayani.\n";
        return;
    } else {
        string* ptr = &antrian[top];  // Pointer menunjuk ke elemen array antrian
        cout << "Masukkan nama pelanggan: ";
        cin >> *ptr;  // Mengambil input nama nasabah dan menyimpannya pada alamat yang ditunjuk oleh ptr
        top++;  // Menambah jumlah antrian
        cout << "Pelanggan " << *ptr << " berhasil ditambahkan.\n";
    }
}

// Fungsi untuk menghapus pelanggan yang dilayani
void dequeue() {
    if (kosong()) {
        cout << "Antrian kosong. Tidak ada pelanggan yang bisa dilayani.\n";
        return;
    } else {
        // Geser semua elemen ke kiri setelah pelanggan dilayani
        for (int i = 1; i < top; i++) {
            antrian[i-1] = antrian[i];  // Pindahkan nama nasabah ke posisi sebelumnya
        }
        top--;  // Mengurangi jumlah antrian
        cout << "Pelanggan pertama telah dilayani.\n";
    }
}

// Fungsi untuk menampilkan antrian
void view() {
    if (kosong()) {
        cout << "Saat ini tidak ada pelanggan.\n";
    } else {
        cout << "Daftar antrian:\n";
        for (int i = 0; i < top; i++) {
            cout << "Teller " << i + 1 << " : " << antrian[i] << endl;  // Menampilkan nama nasabah
        }
    }
}

int main() {
    int pil;
    do {
        menu();  // Menampilkan menu
        cout << "Masukkan pilihan: ";
        cin >> pil;

        switch (pil) {
            case 1:
                enqueue();  // Menambah antrian
                break;

            case 2:
                dequeue();  // Melayani pelanggan
                break;

            case 3:
                view();  // Menampilkan antrian
                break;

            case 4:
                cout << "Terimakasih!!\n";  // Keluar
                break;

            default:
                cout << "Pilihan tidak valid!!\n";
        }

    } while (pil != 4);

    return 0;
}
