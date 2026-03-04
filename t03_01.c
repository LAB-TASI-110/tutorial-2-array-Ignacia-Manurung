//Ignacia Putri Manurung - 12S25034

#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h> // Untuk fungsi umum seperti EXIT_SUCCESS, dan berpotensi untuk malloc/free jika diperlukan (meskipun tidak dalam kasus ini)
#include <string.h> // Tidak secara langsung dibutuhkan untuk logika ini, tetapi disertakan sesuai permintaan.

int main() {
    // Deklarasi variabel
    int n;          // Untuk menyimpan jumlah angka yang akan diinput (angka pertama)
    int current_num; // Untuk menyimpan angka yang sedang dibaca dari input
    int min_val;    // Untuk menyimpan nilai terkecil yang ditemukan
    int max_val;    // Untuk menyimpan nilai terbesar yang ditemukan

    // Langkah 1: Membaca nilai 'n'
    // Program akan meminta pengguna untuk memasukkan nilai 'n'.
    // Nilai 'n' harus berada di antara -100 dan 100.
    // Menggunakan scanf untuk membaca input integer dari console.
    if (scanf("%d", &n) != 1) {
        // Penanganan error sederhana jika input 'n' tidak valid
        fprintf(stderr, "Input tidak valid untuk n.\n");
        return EXIT_FAILURE;
    }

    // Validasi rentang nilai n
    if (n < -100 || n > 100) {
        fprintf(stderr, "Nilai n harus antara -100 dan 100.\n");
        return EXIT_FAILURE;
    }

    // Penanganan kasus jika n adalah 0 atau negatif, yang berarti tidak ada angka lain untuk diproses.
    // Asumsi dari contoh: n adalah jumlah elemen *setelah* n itu sendiri.
    if (n <= 0) {
        // Jika n non-positif, tidak ada elemen untuk dicari min/max
        printf("Tidak ada data untuk diproses.\n");
        return EXIT_SUCCESS;
    }

    // Langkah 2: Membaca angka pertama dari 'n' baris data dan menginisialisasi min_val dan max_val
    // Membaca angka pertama kali untuk menginisialisasi min_val dan max_val
    // Ini penting agar perbandingan selanjutnya dimulai dengan nilai yang valid dari data masukan.
    if (scanf("%d", &current_num) != 1) {
        fprintf(stderr, "Input tidak valid untuk angka pertama.\n");
        return EXIT_FAILURE;
    }
    min_val = current_num; // Angka pertama adalah min dan max sementara
    max_val = current_num;

    // Langkah 3: Melakukan iterasi untuk membaca sisa 'n-1' angka dan mencari min/max
    // Perulangan ini akan berjalan sebanyak n-1 kali karena satu angka sudah dibaca di atas.
    // Menggunakan loop for dari 1 hingga n-1.
    for (int i = 1; i < n; i++) {
        // Membaca angka berikutnya
        if (scanf("%d", &current_num) != 1) {
            fprintf(stderr, "Input tidak valid untuk angka berikutnya.\n");
            return EXIT_FAILURE;
        }

        // Membandingkan dengan nilai minimum saat ini
        if (current_num < min_val) {
            min_val = current_num; // Jika angka saat ini lebih kecil, update min_val
        }

        // Membandingkan dengan nilai maksimum saat ini
        if (current_num > max_val) {
            max_val = current_num; // Jika angka saat ini lebih besar, update max_val
        }
    }

    // Langkah 4: Mencetak hasil (nilai terkecil dan terbesar)
    // Mencetak nilai minimum, diikuti dengan baris baru.
    printf("%d\n", min_val);
    // Mencetak nilai maksimum, diikuti dengan baris baru.
    printf("%d\n", max_val);

    // Mengembalikan EXIT_SUCCESS untuk menandakan program berakhir dengan sukses.
    return EXIT_SUCCESS;
}