int subset_enumeration(int s) {
	int now = s;
	while(now) {
		cout << now << ' ';
		now = (now - 1) & s;
	}
	cout << "0\n";
}