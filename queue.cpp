#include "queue.h"
#include <iostream>
using namespace std; // menggunakan namespace standar agar tidak perlu menulis std::

// definisi prosedur untuk membuat queue kosong
void createQueue(queue &Q)
{
    Q.head = 0; // set kepala/head ke indeks 0
    Q.tail = 0; // set ekor/tail ke indeks 0
    Q.count = 0; // set jumlah elemen/count ke 0
}

// definisi fungsi untuk mengecek apakah queue kosong atau tidak
bool isEmpty(queue Q)
{
    return Q.count == 0; // kembalikan true jika jumlah elemen/count adalah 0
}

// definisi fungsi untuk mengecek apakah queue penuh atau tidak
bool isFull(queue Q)
{
    return Q.count == MAX_QUEUE; // kembalikan true jika jumlah elemen/count sama dengan kapasitas maksimum
}

void enqueue(queue &Q, int x)
{
    if (!isFull(Q)) // jika queue tidak penuh
    {
        Q.info[Q.tail] = x; // tambahkan elemen x di posisi tail
        Q.tail = (Q.tail + 1) % MAX_QUEUE; // masukkan data  (x) ke posisi ekor (tail)
        // pindahkan ekor secara circular (melingkar)
        Q.count++; // tingkatkan jumlah elemen/count
    }
    else // jika queue penuh
    {
        cout << "Antrean penuh!" << endl; // tampilkan pesan error
    }
}

// definisi fungsi untuk menghapus elemen (dequeue) 
int dequeue(queue &Q)
{
    if (!isEmpty(Q)) // jika queue tidak kosong
    {
        int x = Q.info[Q.head]; // ambil elemen di posisi head
        Q.head = (Q.head + 1) % MAX_QUEUE; // pindahkan kepala secara circular (melingkar)
        Q.count--; // kurangi jumlah elemen/count
        return x; // kembalikan elemen yang dihapus
    }
    else // jika queue kosong
    {
        cout << "Antrean kosong!" << endl; // tampilkan pesan error
        return -1; // kembalikan nilai -1 sebagai indikasi error
    }
}   

void printInfo(queue Q)
{
    cout << "Isi queue: [ ";
    if (!isEmpty(Q)) // jika queue tidak kosong
    {
        int i = Q.head; // mulai dari posisi head
        int n = 0;
        while (n < Q.count) // ulangi sebanyak jumlah elemen/count
        {
            cout << Q.info[i] << " "; // tampilkan elemen di posisi i
            i = (i + 1) % MAX_QUEUE; // pindahkan i secara circular (melingkar)
            n++; // tambahkan penghitung 
        }
    }
    cout << "]" << endl; 
}