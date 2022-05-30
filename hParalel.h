
void fParalel()
{

	double itime, ftime, exec_time;
	itime = omp_get_wtime();

	omp_set_num_threads(NTHREADS);
	for (int i = 0; i < NTHREADS; i++) {
		araToplam[i] = 0;
	}

	toplam = 0;
	#pragma omp parallel
	{
		int tid = omp_get_thread_num();
		int n;
		int birSayisi;
		int sifirSayisi;
		#pragma omp	for
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
				araToplam[tid]++;
			}
		}
		#pragma omp critical
		toplam += araToplam[tid];
	}

	ftime = omp_get_wtime();
	exec_time = ftime - itime;
	printf("\n\nParalel kosuyor...");
	printf("\ngecen sure %f", exec_time);
	printf("\n1 sayisi fazla olan binary sayisi: %d", toplam);
}
