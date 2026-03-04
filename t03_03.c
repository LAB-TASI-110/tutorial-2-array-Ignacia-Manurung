//Ignacia Putri Manurung - 12S25034

#include <stdio.h> // Untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h> // Untuk fungsi utility umum, meskipun mungkin tidak langsung digunakan di sini
#include <string.h> // Untuk fungsi manipulasi string, meskipun tidak langsung digunakan di sini
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk DBL_MAX dan DBL_MIN

// Fungsi utama program
int main() {
    int n; // Jumlah baris masukan setelah n
    int current_value; // Nilai yang sedang dibaca
    int prev_value = 0; // Nilai sebelumnya untuk perhitungan rata-rata berturut-turut

    // Membaca nilai n
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error: Gagal membaca nilai N.\n");
        return 1;
    }

    // Validasi n: memastikan n berada dalam rentang yang diminta dan positif
    // Batasan -100 hingga 100 untuk n, tetapi n+1 barisan masukan berarti n harus >= 1
    // Untuk contoh kasus, n=8, jadi asumsi n positif dan valid.
    if (n < 1 || n > 100) { // Batasan untuk n sebagai jumlah baris input (minimal 1 agar ada data)
        fprintf(stderr, "Error: Nilai N harus di antara 1 dan 100.\n");
        return 1;
    }

    int min_val = INT_MAX; // Inisialisasi dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi dengan nilai integer minimum

    double min_avg = DBL_MAX; // Inisialisasi dengan nilai double maksimum
    double max_avg = DBL_MIN; // Inisialisasi dengan nilai double minimum
    int is_first_pair = 1; // Flag untuk menandai perhitungan rata-rata pasangan pertama

    // Loop untuk membaca n baris masukan dan melakukan perhitungan
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &current_value) != 1) {
            fprintf(stderr, "Error: Gagal membaca nilai ke-%d.\n", i + 1);
            return 1;
        }

        // Memperbarui nilai minimum dan maksimum keseluruhan
        if (current_value < min_val) {
            min_val = current_value;
        }
        if (current_value > max_val) {
            max_val = current_value;
        }

        // Hanya hitung rata-rata jika ada nilai sebelumnya (mulai dari nilai kedua)
        if (i > 0) {
            double current_avg = (double)(prev_value + current_value) / 2.0;

            // Inisialisasi min_avg dan max_avg pada pasangan pertama
            if (is_first_pair) {
                min_avg = current_avg;
                max_avg = current_avg;
                is_first_pair = 0; // Setelah inisialisasi, set flag menjadi false
            } else {
                // Perbarui min_avg dan max_avg
                if (current_avg < min_avg) {
                    min_avg = current_avg;
                }
                if (current_avg > max_avg) {
                    max_avg = current_avg;
                }
            }
        }
        
        // Simpan nilai saat ini sebagai nilai sebelumnya untuk iterasi berikutnya
        prev_value = current_value;
    }

    // Menampilkan hasil sesuai format yang diminta
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    
    // Pastikan ada setidaknya satu pasangan untuk rata-rata (n > 1)
    if (n > 1) {
        printf("%.2f\n", min_avg);
        printf("%.2f\n", max_avg);
    } else {
        // Jika n <= 1, tidak ada pasangan rata-rata yang bisa dihitung.
        // Berdasarkan contoh, asumsi n selalu cukup untuk menghitung rata-rata (n >= 2).
        // Namun, jika n=1, output rata-rata terendah dan tertinggi tidak relevan.
        // Kita bisa cetak 0.00 atau pesan, tapi sesuai contoh, diasumsikan n selalu > 1.
        // Mengikuti contoh output jika n=1, bisa diasumsikan tidak ada output rata-rata.
        // Untuk amannya, sesuai instruksi output 4 baris, jika n=1 kita bisa mencetak 0.00
        printf("0.00\n"); 
        printf("0.00\n");
    }

    return 0; // Program berhasil dieksekusi
}