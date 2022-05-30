
void fSeri() {

	double itime, ftime, exec_time;
	itime = omp_get_wtime();

	int n;
	int birSayisi;
	int sifirSayisi;
	toplam = 0;

	for (int i = 0; i < N; i++) {
		n = i;
		birSayisi = 0;
		sifirSayisi = 0;
		while (n > 0) {
			if (n % 2 == 1)
			{
				birSayisi++;
			}
			else {
				sifirSayisi++;
			}
			n = n / 2;
		}
		if (birSayisi > sifirSayisi) {
			toplam++;
		}
	}

	ftime = omp_get_wtime();
	exec_time = ftime - itime;
	printf("\n\nSeri kosuyor...");
	printf("\ngecen sure %f", exec_time);
	printf("\n1 sayisi fazla olan binary sayisi: %d", toplam);
}