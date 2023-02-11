int main() {
	double d, f, p;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf%lf%lf", &d, &f, &p);
		printf("$%0.2lf\n", d * f * p);
	}
}