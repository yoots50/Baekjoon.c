int main() {
	int N, M;
	long long int K;
	scanf("%d%d%lld", &N, &M, &K);
	printf("%lld %lld", K / M, K % M);
}