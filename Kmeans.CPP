#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <math.h>

void main()
{
cout<<"\t\t                TUGAS INDIVIDU DATA MINING "<<endl;
cout<<"\t\t             Mega Musfivawati / 081711233102 "<<endl;
cout<<"\t\t    Contoh Kasus Pengelompokan Hasil Akademik Mahasiswa "<<endl;
cout<<"\t\t         Berdasarkan Nilai UAS dan UTS Mahasiswa "<<endl<<endl;

int a, A[100], B[100], k, C1[100],C2[100],prevc1[25],prevc2[25],i,j;
cout<< "banyaknya data : ";
cin>> a;
cout<< "banyaknya kluster : ";
cin>> k;
for(int i=0; i <a; i++)
 {
  cout << "Enter Nilai UAS " << i+1 << ": ";
  cin >> A[i];
  cout << "Enter Nilai UTS " << i+1 << ": ";
  cin >> B[i];
 }
//Datanya
 cout << "Data yang telah dimasukkan: "<<endl<<endl;
 cout<<"No."<<"	"<<"UAS"<<"	"<<"UTS"<<endl;
 for (i=0; i<a; i++)
 {
 	cout<<i+1<<"	"<<A[i]<<"	"<<B[i]<<endl;
 }
// UNTUK PILIH CENTROID RANDOM
for(int i = 0; i <3; i++)
 {
  C1[i]= A[i];
  C2[i]= B[i];
 }

int D[100][100],steps=1,groupsa[25][100],groupsb[25][100],min,groupa,groupb,valuea,valueb, ok = 1;

while(ok == 1)
{
  cout << endl << "Itration Number: " <<steps;
  //calculations
  for(i=0;i<k;i++)
  {
  	for(j=0;j<a;j++)
   {
    D[i][j] =abs((C1[i] - A[j])+(C2[i] - B[j]));
   }
  }

  //groups
  for(i=0;i<a;i++)
  {
   min = 100000;
   for(j=0;j<k;j++)
   {
    if(D[j][i] < min)
    {
        min = D[j][i];
        valuea = A[i];
        valueb = B[i];
        groupa = j;
        groupb = j;
    }
   }
   groupsa[groupa][i] = valuea;
   groupsb[groupb][i] = valueb;
  }

  //jarak
cout << endl << "Jarak" << endl;
  for(i=0;i<a;i++)
  {
  	for(j=0;j<k;j++)
  	{
    cout<<D[j][i] << "\t";
   }
   cout << endl;
  }

 // show groups and get new C's
int suma,counta=0, sumb,countb=0;
cout << endl << "Gruops" << endl;
for(i=0;i<k;i++)
  {
   suma=0;
   counta=0;
   sumb=0;
   countb=0;
   cout << "Group " << i+1 << ": "<<endl;
   cout<<"UAS"<<"\t "<<"UTS"<<endl;
   for(j=0;j<a;j++)
   {
    if(groupsa[i][j] != NULL && groupsb[i][j]!= NULL)
    {
     cout<<groupsa[i][j]<<"\t "<<groupsb[i][j]<<endl;
     suma += groupsa[i][j];
     counta++;
     sumb += groupsb[i][j];
     countb++;
    }
   }
   prevc1[i] = C1[i];
   prevc2[i] = C2[i];
   C1[i] = suma/counta;
   C2[i] = sumb/countb;
cout <<endl<<"C1 = " << C1[i] << endl;
cout <<"C2 = " << C2[i] << endl;
cout<<endl;
}

//array null
for(i=0;i<100;i++)
{
	for(j=0;j<100;j++)
   {
    groupsa[i][j] = NULL;
    groupsb[i][j] = NULL;
   }
  }

//cek kondisi
ok = 0;
for(int i = 0; i < k; i++)
{
	if(prevc1[i] != C1[i]&&prevc2[i] != C2[i])
   {
   	ok = 1;
   }
}
   if(ok != 1)
   {
   	getch();
 	}
   steps++;
}

getch();
}