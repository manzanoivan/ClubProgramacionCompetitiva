// Eliminacion Gaussiana de matrices.
// Definiciones iniciales para Gauss-Jordan.
typedef vector<double> Vector;
typedef vector<Vector> Matriz;

// Para eliminacion con flotantes.
const double ERROR = 1e-9;
bool EsCero(double a) {
	return fabs(a) < ERROR;
}

// En caso de no permitir el pivoteo (eg. cuando
// requieran sacar una matriz inversa) simplemente
// comenten o borren la seccion <comment>.

void EliminacionGaussiana(Matriz& m) {
	for (int i = 0; i < m.size(); ++i) {
		// <comment>
		int fila_mayor = i;
		for (int j = i + 1; j < m.size(); ++j)
			if (fabs(m[fila_mayor][i]) <
				fabs(m[j][i])) fila_mayor = j;
		swap(m[i], m[fila_mayor]);
		// </comment>

		if (EsCero(m[i][i])) continue;
		for (int j = m[i].size() - 1; j >= i; --j)
			m[i][j] = m[i][j] / m[i][i];
		for (int j = 0; j < m.size(); ++j) {
			if (i == j || EsCero(m[j][i])) continue;
			for (int k = m[j].size() - 1; k >= i; --k)
				m[j][k] = m[j][k] - m[i][k] * m[j][i];
		}
	}
}