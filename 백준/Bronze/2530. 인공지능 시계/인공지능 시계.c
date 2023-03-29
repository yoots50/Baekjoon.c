int main() {
	int h, m, s;
	scanf("%d%d%d", &h, &m, &s);

	int time;
	scanf("%d", &time);
	s += time;
	
	m += s / 60;
	s %= 60;

	h += m / 60;
	m %= 60;

	h %= 24;

	printf("%d %d %d", h, m, s);
}