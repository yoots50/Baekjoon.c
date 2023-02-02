int main() {
	int HH, MM;
	scanf("%d%d", &HH, &MM);
	HH -= 9;
	printf("%d", HH * 60 + MM);
}