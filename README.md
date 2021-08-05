# Algoritma-Kmeans.md
Berikut adalah Implementasi Algoritma K-Means Clustering untuk pengelompokan hasil akademik mahasiswa berdasarkan nilai UAS dan UTS menggunakan Borland C++.

## Metode
+ Tentukan k (jumlah cluster) yang ingin dibentuk
+ Bangkitkan k centroid (titik pusat cluster) awal secara random
+ Hitung jarak centroid dari data yang ada di masing-masing cluster.
+ Kelompokkan obyek berdasarkan jarak minimum
+ Tentukan posisi centroid baru (Ck) untuk semua cluster dengan cara menghitung nilai rata-rata dari data-data yang berada pada cluster yang sama.
+ Kembali ke Step 3, apabila masih ada data yang berpindah cluster atau apabila terjadi perubahan nilai centroid, ada yang di atas nilai threshold yang ditentukan atau apabila perubahan nilai pada objective function yang digunakan di atas nilai threshold yang ditentukan

## Implementasi
Implementasinya ada di file Kmeans.CPP.

## Dataset
Dataset diperoleh dari hasil inputan oleh user. Dengan permulaan user harus menginputkan jumlah banyaknya data dan banyaknya cluster yang diinginkan, kemudian user harus memasukkan nilai UTS dan UAS sesuai dengan jumlah banyaknya data yang telah diinputkan.

## Authors

* **Mega Musfivawati** - *Initial work* - [megamusfiva](https://github.com/megamusfiva/)
