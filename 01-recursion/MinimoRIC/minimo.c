int minimo(int* v, int n) {
	// Caso base:
	if (n == 1) {
		return v[0];
	}
	else {
		// Ricorsione

		int min = minimo(v + 1, n - 1);

		if (v[0] < min)
			return v[0];
		else
			return min;
	}

	return;
}