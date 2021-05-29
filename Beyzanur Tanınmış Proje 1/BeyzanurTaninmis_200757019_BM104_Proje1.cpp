#include <iostream> //Okumayı ve standart akışlara yazmayı denetleyen nesneler bildiren kütüphane.
#include <iomanip>  // Input ve output belirli formatlarda yazılması için kullandığımız kütüphane.
#include <cstdlib>  // Rastgele sayıları tutmak için kullandığımız kütüphane.
#include <ctime>    // Tarih ve saat bilgilerini saklamak için kullandığımız kütüphane.

using namespace std; // İsim uzayında std ile ara 

void TombalaKartlariniOlustur(int[10][15]); // 10 tane tombala kartında benzersiz tombala sayıları kullanmak için oluşturduğum fonksiyonun prototipi.

void TombalaKartlarininDagitilmasi(int[5][15], int[10], int, int[10][15]); // Kullanıcı girişi verildikten sonra sayıya göre oluşturulan kartları rastgele ve benzersiz dağıtan fonksiyonun prototipi.

void TombalaTorbasi(int[90]); // Benzersiz şekilde 90 tane sayıyı çeken fonksiyonun prototipi.

void KartaSayiVeCinkoYazdirma(int[][15], int[90], int, int[]); // Oyuncuları kartlarındaki sayıları ve tombala torbasından çekilen sayıları karşılaştırıp aynıysa -1 yazan ve
																// Aynı sayılar 5 olunca 1.çinko olan, 10 olunca 2. çinko olan, 15 olunca tombala olan ve bunu yazdıran fonksiyonun prototipi.

void PuanTablosu(int[5], int); // Oyuncuların çinkolara göre aldığı puanları yazan ve bunları sıralayıp en büyük puanı veren fonksiyonun prototipi.

int main() // Projenin gövdesi olan main fonksiyonu burada üstte tanımlanan fonksiyolar çağırılarak işlem yapılır
{
	int kullaniciSayisi; // Oyuncu sayısının alınması için tanımlanan değişken

	int puanYazdirma[5]; // En fazla 5 oyuncu olduğu için bunların puanını içinde tutacak olan dizi için tanımlanan değişken

	for (int i = 0; i < 5; i++) // Puan tablosunda her çalıştırıldığıda oyuncuların   puanının sıfır olması için açtığım döngü
	{

		puanYazdirma[i] = 0;

	}

	srand((unsigned int)(time(0))); // Tanımladığım değişken ve dizilerin içindeki sayıların rastgele gelmesi için kullandığım kalıp

	bool kullaniciSayisiAlindiMi = 0; // Oyun 3 defa çalışacağı için her defasında kullanıcı sayısı almaması için açtığım kontrol değişkeni başta kontrol edilebilmesi için 0 yani daha kontrol edilmedi olarak atadım.

	for (int i = 0; i < 3; i++) // Oyunun 3 defa çalıştırılması için açtığım döngü
	{

		cout << "Tombala oyununa hos geldiniz!" << endl; // Hoş geldiniz mesajı bastırmak için kullandım

		cout << endl; // Mesajdan sonra bir enterlık boşluk bırakmak istediğim için  yazdım

		cout << "Kartlar hazirlaniyor..." << endl; // Kartların hazırlandığı mesajını bastırmak için kullandım

		int tombalaKartlari[10][15]; // En fazla 10 kart ve 15 tombala numaralarından oluşan kartları içinde tutmak istediğim diziyi taımladığım değişken

		TombalaKartlariniOlustur(tombalaKartlari); // Tombala kartlarını oluşturduğum fonksiyonun çağırılması

		cout << endl; // Kartlar oluşturulduktan sonra bir enter bırakmak için kullandığım kalıp

		cout << "Lutfen oyunu oynayacak kisi sayisini giriniz." << endl; // Kartlar oluşturulduktan sonra kullanıcı sayısının kullanıcıya bildirilmesi için kullandığım kalıp

		while (1 && kullaniciSayisiAlindiMi == 0) // Kullanıcı sayısının her hatalı girişte tekrar girilmesii sağlamak amacıyla sonsuz while döngüsü açtım ve buraya eğer kullanıcı sayısı daha önce alımadıysa girilmesini istedim
		{

			cin >> kullaniciSayisi; // Girilen kullanıcı sayısını değişkene atamak için kullandığım kalıp

			if (kullaniciSayisi >= 2 && kullaniciSayisi <= 5) // Kullanıcı sayısı 2 den büyük eşitse ve 5 ten küçük eşitse ifin içine gir
			{

				cout << "Oyuncu Sayisi: " << kullaniciSayisi << endl; // Oyuncu sayısını ekrana bastırır

				kullaniciSayisiAlindiMi = true; // Oyuncu sayısı 1 defa alındıysa bu döngüye bir defa daha girme

				break; // Doğru sayı girildiyse döngüyü kırarak bir sonraki adıma geç
			}

			else // Eğer yanlış bir sayı alındıysa 
			{

				cout << "Hatali Giris Yaptiniz.2 ile 5 arasinda bir sayi giriniz." << endl; // Hata mesajı ver ve doğru sayı girilene kadar tekrar kullanıcı sayısı al

			}

		}

		int kullanicilar[5][15]; // En çok 5 oyuncu olduğu için bu kartları elinde tutması için açtığım diziyi tanımladığım değişken

		int secilenKartlar[10] = { 0,1,2,3,4,5,6,7,8,9 }; // Girilen oyuncu sayısı kadar kartların rastgele dağıtılmasını sağlayan diziyi tanımladığım değişken

		TombalaKartlarininDagitilmasi(kullanicilar, secilenKartlar, kullaniciSayisi, tombalaKartlari); // Oyuncu sayısı kadar rastgele kartların dağıtılması ve bunların ekrana yazdırılmasını sağlayan fonksiyonun çağırılması

		cout << endl; // Kartlar dağıtıldıktan sonra bir enter aşağı iner

		int tombalaTorbasi[90]; // 1' den 90' a kadar sayıların içinde tutulan dizi için tanımladığım değişken

		TombalaTorbasi(tombalaTorbasi); // Sayıların rastgele ve benzersiz dağıtılmasını sağlayan ve bunu ekrana yazan fonksiyonun çağırılması
		cout << endl;

		KartaSayiVeCinkoYazdirma(kullanicilar, tombalaTorbasi, kullaniciSayisi, puanYazdirma);
		/* Tombala torbasındaki sayılar ile kullanıcıların kartındaki sayıların karşılaştırıldıktan sonra aynı olanlara -1 yazdıran ve -1'ler 5 tane ise 1.çinkoyu belirleyen, 10 tane ise 2.çinkoyu belirleyen
		15 tane olduğuda Tombala yapan kullanıcıyı belirleyen ve bunu ekrana yazdıran fonksiyonun çağırılması */
		cout << endl;

	}

	PuanTablosu(puanYazdirma, kullaniciSayisi); // Her çinkoya göre puan veren ve program 3 defa çalıştıktan sonra en yüksek puanlı kullanıcıyı bulup bunu bastıran fonksiyonun çağırılması

	return 0; // Main fonksiyonunu bitirir
}


//------------------------------------------------------------------Tombala kartlarının hazırlanması------------------------------------------------------------

void TombalaKartlariniOlustur(int tombalaKartlari[10][15]) //Tombala kartlarını oluşturduğum fonksiyonun tanımı
{

	for (int i = 0; i < 10; i++) // 10 kartı 10 satırını yazdırmak için açtığım döngü
	{

		cout << endl << "Kart No " << i << ":  " << setw(1);  // Kart numarasını yazdıran kod setw() tanımını karttan sonraki sayıların bastırılmasından önce bir spacelik boşluk bırakması için kullandım

		for (int j = 0; j < 15; j++) // 15 tombala sayısının 15 sütununu yazdırmak için açtığım döngü
		{

			cout << " "; // Bastırılan sayıların arasında boşluk bırakmak için kullandığım tanım

			tombalaKartlari[i][j] = rand() % 90 + 1; // Tombala kartlarına 90 tane sayıyı rastgele yazdırır. 

			for (int c = 0; c < j; c++) // Sayıların benzersizliğini kontrol etmek için sütunda kullandığım değişkenin yerine kontrol değişkeni açtığım döngü
			{

				int gecici1; // Kontrol edilecek sayılar için oluşturulan geçici değişken

				if (tombalaKartlari[i][j] == tombalaKartlari[i][c]) // Eğer tombala kartındaki sayılar ve kontrol değişkeni ile oluşturulan karttaki sayılar aynıysa if in içine gir
				{
					while (1) // Benzer sayılar varsa benzersiz yapana kadar döngüye girmesi için açtığım sonsuz döngü kalıbı

					{

						gecici1 = rand() % 90 + 1; // Geçici kontrol değişkenine 90 tane rastgele sayılar atar

						if (gecici1 != tombalaKartlari[i][c]) // Kontrol değişkenindeki sayılar ve geçici kontrol değişkeniyel oluşturulan kartlardaki sayılar eşit değilse if i içine gir
						{

							tombalaKartlari[i][j] = gecici1; // Kontrol değişkenini asıl kart dizisine ata

							break; // Sayılar benzersiz olduğunda döngüyü kır ve çık

						}

					}

				}

			}

			cout << " " << setw(3) << tombalaKartlari[i][j]; // Kartlardaki sayılar benzersiz olduğunda ekrana yazdırır

		}

		cout << endl; // Bir enterlık boşluk bırakır

	}

}




//-----------------------------------------------------Tombala Kartlarının Dağıtılması -----------------------------------------------

void TombalaKartlarininDagitilmasi(int kullanicilar[5][15], int secilenKartlar[10], int kullaniciSayisi, int tombalaKartlari[10][15])
// Oyuncu sayısı kadar rastgele kartların dağıtılması ve bunların ekrana yazdırılmasını sağlayan fonksiyonun tanımı
{
	cout << "Oyuncular Icin Secilen Kart Sayilari: " << endl; // Seçilen kartların ekrana yazdırılması için bildiri

	for (int i = 0; i < kullaniciSayisi; i++) // Kartların girilen oyuncu satırı kadar ekrana yazdırılmasını sağlayacak olan döngü
	{

		int gecici4 = rand() % 10; // Benzersiz olması için atanan kontrol değişkeninin içindeki 10 sayıyı rastgele dağıtır

		for (int d = 0; d <= i; d++) // Kontrol değişkeniyle oluşturulacak yeni döngü
		{

			if (gecici4 == secilenKartlar[d]) // Eğer kontrol değişkenindeki sayılar diğer kontrol değişkeni ile oluşturulan dizinin içindeki sayılarla benzerse if e gir
			{

				gecici4 = rand() % 10; // Sayılar benzer ise yeniden random sayı oluştur

				break; //Eşit olmadığında döngüyü kır ve çık

			}

		}

		secilenKartlar[i] = gecici4; // Asıl diziyi kontrol değişkenine atar

		cout << setw(3) << gecici4; // Kontrol edilen dizi benzersizse ekrana yazdırır.

		cout << setw(4) << i << ". Oyuncunun Karti: " << gecici4 << setw(4); // Seçilen kartları oyunculara atar

		for (int j = 0; j < 15; j++) //Kullanıcıların kartlarını bastırmak için açılan döngü
		{

			kullanicilar[i][j] = tombalaKartlari[gecici4][j]; // Seçilen kartları oyunculara atar

			cout << setw(4) << kullanicilar[i][j] << setw(4); // Kartları bastırır

		}

		cout << endl;



	}

	cout << endl;

}

//------------------------------------------------------------------- TOMBALA TORBASI -----------------------------------------------------------------------

void TombalaTorbasi(int tombalaTorbasi[]) // Sayıların rastgele ve benzersiz dağıtılmasını sağlayan ve bunu ekrana yazan fonksiyonun taımı
{
	int sayac[5]; //Sayıların kotrolü içi açılan sayaç

	cout << "Tombaladan Sirasi Ile Cekilen Numaralar" << endl;

	int gecici5; // Sayıların benzersiz olması için tanımlanan kotrol değişkeni

	for (int i = 0; i < 90; i++) // 90 tane sayıyı bastırmak için kullanılan döngü
	{

		gecici5 = rand() % 90 + 1; // KOtrol değişkenine rastgele 90 sayı bastırır

		for (int j = 0; j < i; ) //Kontrol döngüsü
		{

			if (gecici5 == tombalaTorbasi[j]) // Eğer kontrol değişkenindeki sayılar kontrol değişkeni ile oluşturulan  torbadaki sayılarla aynıysa if in içine gir
			{

				gecici5 = rand() % 90 + 1; // Aynıysa yei rastgele sayı oluştur

				
				j = 0;
			}
			else
			{
				j++;
			}

		}

		tombalaTorbasi[i] = gecici5; // Asıl diziyi kontrol değişkenine atar

		if (i % 10 == 0) // Kare oluşturmak içilen if dizinin 10. elemenına geldiğide aşağı inmesini ister
		{

			cout << endl;

		}

		cout << "\t" << gecici5; // Tab boşluğu bırakır
	}

	cout << endl;

}


//------------------------------------------------------------------------------- -1 YAZDIRMA ----------------------------------------------------------------------------------

void KartaSayiVeCinkoYazdirma(int kullanicilar[5][15], int tombalaTorbasi[90], int kullaniciSayisi, int puanYazdirma[])
/* Tombala torbasındaki sayılar ile kullanıcıların kartındaki sayıların karşılaştırıldıktan sonra aynı olanlara -1 yazdıran ve -1'ler 5 tane ise 1.çinkoyu belirleyen, 10 tane ise 2.çinkoyu belirleyen
   15 tane olduğuda Tombala yapan kullanıcıyı belirleyen ve bunu ekrana yazdıran foksiyonun tanımı */
{

	int cinkoKontrol = 0; // Çinko kontrolü için açılan sayaç

	int sayac[5]; // Puan için açılan sayaç

	for (int i = 0; i < kullaniciSayisi; i++) // Puan sayacının sıfırlanması için açılan döngü
	{

		sayac[i] = 0; // Sayacı sıfırlar

	}

	for (int j = 0; j < 90; j++) // 90 tane sayı çekilmesi için açılan döngü
	{

		for (int a = 0; a < kullaniciSayisi; a++) // Girilen kullanıcı sayısı kadar satır bastıran döngü
		{

			for (int b = 0; b < 15; b++) // Kullanıcılar için atanan kartlardaki sayılar için döngü
			{

				if (kullanicilar[a][b] == tombalaTorbasi[j]) // Tombala torbasındaki ve kullanıcıların kartlarıdaki sayılaır karşılaştırır ve aynıysa içeri girer
				{

					kullanicilar[a][b] = -1; // Aynı sayıların yerine -1 yazdırır

					sayac[a]++; // Puan sayacını arttırırü


				}

			}

			if (sayac[a] == 5 && cinkoKontrol == 0) // Puan sayacı 5 e ulaştığında ve ilk çinko yapılmadığında ifin içine gir
			{

				cout << "Ilk Cinkoyu Yapan Oyuncu: " << a << ". Oyuncu" << endl; // İlk çinkoyu yapa oyuncuyu yazdır

				cinkoKontrol++; // Çinko sayacını, puan sayacı 5 olduğuda arttır

				puanYazdirma[a] += 5; // Puan tablosu için çinko yapan oyunculara 5 puan ekle

				for (int d = 0; d < kullaniciSayisi; d++) // -1 yazılan kartları bastırmak için döngü
				{

					cout << d << ". Oyuncunun Karti: "; // Oyuncunun kartı bastırılır

					for (int g = 0; g < 15; g++)
					{

						cout << setw(5) << kullanicilar[d][g]; // Tombala torbasındaki sayılarla oyunculaırn kartlarındaki sayılar aynıysa -1 yazdırılması için atanan diziyi bastırır

					}

					cout << endl;

				}

			}

			if (sayac[a] == 10 && cinkoKontrol == 1)  //  Puan sayacı 10 e ulaştığında ve kullanıcılar ilk çinkoya ulaştığında ifin içine gir
			{

				cout << "Ikinci Cinkoyu Yapan Oyuncu: " << a << ". Oyuncu" << endl;

				cinkoKontrol++; // 2.çinkoya ulaşıldığında sayacı arttır

				puanYazdirma[a] += 10; // Kartında tombala torbasındaki sayılarla 10 tane aynı olan kullanıcının puanını 10 arttır

				for (int d = 0; d < kullaniciSayisi; d++) // -1 yazılan kartları bastırmak için döngü
				{

					cout << d << ". Oyuncunun Karti: "; // Oyuncunun kartı bastırılır

					for (int g = 0; g < 15; g++)
					{

						cout << setw(5) << kullanicilar[d][g]; // Tombala torbasındaki sayılarla oyunculaırn kartlarındaki sayılar aynıysa -1 yazdırılması için atanan diziyi bastırır

					}

					cout << endl;

				}

			}

			if (sayac[a] == 15 && cinkoKontrol == 2) //  Puan sayacı 15 e ulaştığında ve kullanıcılar ikinci çinkoya ulaştığında ifin içine gir
			{

				cout << "Tombalayi Yapan Oyuncu: " << a << ". Oyuncu" << endl;

				cinkoKontrol++; // Tombalaya ulaşıldığında sayacı arttır

				puanYazdirma[a] += 15;  // Kartında tombala torbasındaki sayılarla 15 tane aynı olan kullanıcının puanını 10 arttır

				for (int d = 0; d < kullaniciSayisi; d++) // -1 yazılan kartları bastırmak için döngü
				{

					cout << d << ". Oyuncunun Karti: "; // Oyuncunun kartı bastırılır

					for (int g = 0; g < 15; g++)
					{

						cout << setw(5) << kullanicilar[d][g];  // Tombala torbasındaki sayılarla oyunculaırn kartlarındaki sayılar aynıysa -1 yazdırılması için atanan diziyi bastırır

					}

					cout << endl;

				}

			}


		}

	}

}

//----------------------------------------------------------------PUAN TABLOSU OLUŞTURMA----------------------------------------------------------------------------

void PuanTablosu(int puanTablosu[5], int kullaniciSayisi) // Her çinkoya göre puan veren ve program 3 defa çalıştıktan sonra en yüksek puanlı kullanıcıyı bulup bunu bastıran fonksiyonun tanımı
{

	int enBuyukPuanSayaci = 1; // En büyük  puan için kullanılacak olan sayaç

	int enBuyukPuan = 0; // En büyk puanı başta 0 olarak kabul eden değişken tanımı

	bool birdenFazlaKazananVarMi = false; // Birden fazla oyucunun kazanıp kazanmadığını kontrol eden değişken

	for (int i = 0; i < kullaniciSayisi; i++) // Kullanıcıların en yüksek puanlısının hangisi olup olmadığını kotrol eden edecek olan döngü

	{

		if (puanTablosu[i] > enBuyukPuan) // İlk en büyük puanlı kullancıyı diğer turlarda diğer kullanıcılarla karşılaştırıp ondan büyüğü varsa en büyük pualıyı ona atar
		{

			enBuyukPuan = puanTablosu[i];

			enBuyukPuanSayaci = i;

		}

		cout << i << " Numaralari Oyuncunun Puani = " << puanTablosu[i] << endl; // En büyük puanı olan oyuncuyu ekrana bastırır

	}

	for (int j = 0; j < kullaniciSayisi; j++) // En büyük puanı alan başka kullanıcı var mı diye kontrol edilmek için açılan döngü
	{

		if (puanTablosu[j] == puanTablosu[enBuyukPuanSayaci]) // Eğer en büyük puanlı birden fazla kullanıcı varsa
		{

			if (j != enBuyukPuanSayaci)
			{

				birdenFazlaKazananVarMi = true; // Sayacı doğru ata

			}

		}
	}

	if (birdenFazlaKazananVarMi) // Birden fazla en yüksek aynı puanlı oyuncu varsa ifin içine gir
	{

		cout << "Kazanan Oyuncu Yok Berabere Kalındı" << endl; // Kazanan olmadığını yazdır

	}

	else // Eğer tek bir en yüksek puanlı oyuncu varsa
	{

		cout << "Kazanan Oyuncu : " << enBuyukPuanSayaci; // Onu ekrana yazdır

	}


}