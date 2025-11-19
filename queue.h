#ifndef QUEUE_H // jika QUEUE_H belum didefinisikan
#define QUEUE_H // 

#define MAX_QUEUE 5

struct queue
{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

// fungsi untuk mengecek apakah queue kosong atau tidak
bool isEmpty(queue Q);

// fungsi untuk mengecek apakah queue penuh atau tidak
bool isFull(queue Q);

// prosedur untuk menambahkan elemen ke dalam queue (enqueue)
void enqueue(queue &Q, int x);

//  fungsi untuk menghapus dan mengembalikan elemen dari queue (dequeue)
int dequeue(queue &Q);

// prosedur untuk menampilkan semua isi queue
void printInfo(queue Q);

#endif